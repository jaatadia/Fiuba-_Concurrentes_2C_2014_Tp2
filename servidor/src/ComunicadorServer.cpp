/*
 * ComunicadorServer.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#include "ComunicadorServer.h"

ComunicadorServer::ComunicadorServer(std::string path):base(path), contentRequest("","",""), respuestaRequest(), tipoRequest(0){
	// TODO !! está bien generado respuestaRequest y tipoRequest? para el server padre no influye, o si?
	this->cola = new Cola<request>("/tmp/keyfile_cola.txt",'a');

}

ComunicadorServer::~ComunicadorServer() {
	//TODO !!! si es hijo no destruye la cola, no? como lo se entonces?
	//this->cola->destruir();
	delete this->cola;
}

bool ComunicadorServer::esperarRequest(){
	//todo
	return false;
}

void ComunicadorServer::procesarRequest(){
	//todo
}

void ComunicadorServer::enviarRespuesta(){
	//todo
}

void ComunicadorServer::procesarQuery(){
	//todo
}
void ComunicadorServer::procesarAlta(){
	//todo
}
