/*
 * ComunicadorServer.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#include "ComunicadorServer.h"

ComunicadorServer::ComunicadorServer(std::string path):base(path), tipoRequest(0), contentRequest("","",""), respuestaRequest(), cola("/tmp/keyfile_cola.txt",'a') {
	// TODO !! está bien generado respuestaRequest y tipoRequest? para el server padre no influye, o si?
}

ComunicadorServer::~ComunicadorServer() {
	//TODO !!! si es hijo no destruye la cola, no? como lo se entonces?
	//this->cola->destruir();
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
