/*
 * ComunicadorServer.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#include "ComunicadorServer.h"
#include <iostream>

ComunicadorServer::ComunicadorServer(std::string path):base(path), tipoRequest(0), senderPID(0), contentRequest("","",""), respuestaRequest(), cola("/tmp/keyfile_cola.txt",'a') {
	// TODO !! está bien generado respuestaRequest y tipoRequest? para el server padre no influye, o si?
}

ComunicadorServer::~ComunicadorServer() {
	//TODO !!! si es hijo no destruye la cola, no? como lo se entonces?
}

bool ComunicadorServer::esperarRequest(){
	try{
		request peticionRecibida;
		this->cola.leer(A_SERVIDOR,&peticionRecibida);

		this->senderPID = peticionRecibida.senderPid;
		this->contentRequest = Registro(peticionRecibida.nombre,peticionRecibida.direccion,peticionRecibida.telefono);
		this->tipoRequest = peticionRecibida.tipoRequest;

		return true;
	}catch(string &e){
		return false;
	}
}

void ComunicadorServer::procesarRequest(){
	if (this->tipoRequest == R_ALTA) {
		procesarAlta();
	} else if (this->tipoRequest == R_QUERY){
		procesarQuery();
	}
}

void ComunicadorServer::enviarRespuesta(){

	request respuesta;
	respuesta.mtype = this->senderPID;
	respuesta.senderPid = getpid();

	if (this->respuestaRequest.empty()) {
		respuesta.tipoRequest = R_RESPUESTA_VACIA;
		this->cola.escribir(respuesta);
	} else {

		std::list<Registro>::iterator it = this->respuestaRequest.begin();

		while (it != this->respuestaRequest.end()) {
			(*it).getNombre(respuesta.nombre);
			(*it).getDireccion(respuesta.direccion);
			(*it).getTelefono(respuesta.telefono);
			it++;
			if (it == this->respuestaRequest.end()) {
				respuesta.tipoRequest = R_RESPUESTA_FINAL;
			} else respuesta.tipoRequest = R_RESPUESTA_PARCIAL;
			this->cola.escribir(respuesta);
		}
	}
}

void ComunicadorServer::procesarQuery(){
	this->respuestaRequest = this->base.query(this->contentRequest);
}

void ComunicadorServer::procesarAlta(){
	if (this->base.altaRegistro(this->contentRequest)) {
		Registro resultado;
		this->respuestaRequest.push_back(resultado);
	}
}

void ComunicadorServer::cerrar(){
	this->cola.destruir();
}
