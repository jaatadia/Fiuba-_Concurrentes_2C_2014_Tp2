/*
 * ComunicadorCliente.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#include "ComunicadorCliente.h"

ComunicadorCliente::ComunicadorCliente() {
	this->cola = new Cola<request>("/tmp/keyfile_cola.txt",'a');
}

ComunicadorCliente::~ComunicadorCliente() {
	//TODO !! el cliente no destruye la cola, no?
	delete this->cola;
}

std::list<Registro> ComunicadorCliente::enviarQuery(Registro reg){
	//todo
}

Registro ComunicadorCliente::enviarAlta(Registro){
	//todo
}
