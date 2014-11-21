/*
 * ComunicadorServer.h
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#ifndef COMUNICADORSERVER_H_
#define COMUNICADORSERVER_H_

#include <list>
#include <string>
#include "Registro.h"
#include "BaseDatos.h"
#include "Cola.h"


class ComunicadorServer {
private:
	void procesarQuery();
	void procesarAlta();

	BaseDatos base;
	static const int R_QUERY = 0;
	static const int R_ALTA = 1;
	int tipoRequest;
	Registro contentRequest; //TODO !!!! no se que es esto
	std::list<Registro> respuestaRequest;  //TODO !!!! no se que es esto
	Cola<request>* cola;

	request reqRecibido;
	request reqRespuesta;

public:
	ComunicadorServer(std::string pathBaseDatos);
	virtual ~ComunicadorServer();
	bool esperarRequest();
	void procesarRequest();
	void enviarRespuesta();
};

#endif /* COMUNICADORSERVER_H_ */
