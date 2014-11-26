/*
 * ComunicadorCliente.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#include "ComunicadorCliente.h"

ComunicadorCliente::ComunicadorCliente(): cola("/tmp/keyfile_cola.txt",'a') {
}

ComunicadorCliente::~ComunicadorCliente() {
	//TODO !! el cliente no destruye la cola, no?
}

std::list<Registro> ComunicadorCliente::enviarQuery(Registro reg){

	request peticion, respuesta;
	std::list<Registro> respuesta_total;

	//lleno struct para enviar
	peticion.mtype = A_SERVIDOR;
	reg.getNombre(peticion.nombre);
	reg.getDireccion(peticion.direccion);
	reg.getTelefono(peticion.telefono);
	peticion.senderPid = getpid();
	peticion.tipoRequest = R_QUERY;

	this->cola.escribir(peticion);

	//leo respuesta
	int leido = this->cola.leer(getpid(),&respuesta);

	//si la rta no tiene el tamaño del struct, fue error. tira excepcion y devuelve la lista vacía
	if ( leido != (sizeof(request)-sizeof(long)) ){
		stringstream mensaje;
		mensaje << "Error al leer en el cliente (pid " << getpid() << "): "<< strerror(errno);
		throw mensaje.str();
	}
	//si la respuesta fue vacia, devuelvo la lista vacia
	if (respuesta.tipoRequest == R_RESPUESTA_VACIA) return respuesta_total;

	//pongo la respuesta en un registro y pongo ese registro en la lista
	Registro reg_respuesta(respuesta.nombre,respuesta.direccion,respuesta.telefono);
	respuesta_total.push_back(reg_respuesta);

	while (respuesta.tipoRequest != R_RESPUESTA_FINAL) {

		//leo siguiente respuesta
		int leido = this->cola.leer(getpid(),&respuesta);
		if ( leido != (sizeof(request)-sizeof(long)) ){
			stringstream mensaje;
			mensaje << "Error al leer en el cliente (pid " << getpid() << ") :" << strerror(errno);
			throw mensaje.str();
			return respuesta_total; //TODO !! chequear
		}
		//pongo la siguiente respuesta en un registro y pongo ese registro en la lista
		Registro reg_respuesta(respuesta.nombre,respuesta.direccion,respuesta.telefono);
		respuesta_total.push_back(reg_respuesta);
	}

	return respuesta_total;
}

bool ComunicadorCliente::enviarAlta(Registro reg){
	//todo
	request peticion, respuesta;

	//lleno struct para enviar
	peticion.mtype = A_SERVIDOR;
	reg.getNombre(peticion.nombre);
	reg.getDireccion(peticion.direccion);
	reg.getTelefono(peticion.telefono);
	peticion.senderPid = getpid();
	peticion.tipoRequest = R_ALTA;

	this->cola.escribir(peticion);

	//leo respuesta
	int leido = this->cola.leer(getpid(),&respuesta);

	//si la rta no tiene el tamaño del struct, fue error. tira excepcion y devuelve la lista vacía
	if ( leido != (sizeof(request)-sizeof(long)) ){
		stringstream mensaje;
		mensaje << "Error al leer en el cliente (pid " << getpid() << ") :" << strerror(errno);
		throw mensaje.str();
	}
	//si la respuesta fue vacia, no se dio de alta
	if (respuesta.tipoRequest == R_RESPUESTA_VACIA) {
		return false;
	} else if (respuesta.tipoRequest == R_RESPUESTA_FINAL) {
		return true;
	}
	return false;
}
