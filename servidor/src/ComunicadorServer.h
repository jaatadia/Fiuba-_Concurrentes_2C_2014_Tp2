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
#include "request.h"
#include "Constantes.h"
#include <unistd.h>
#include <iterator>


class ComunicadorServer {
private:
	void procesarQuery();
	void procesarAlta();

	BaseDatos base;

	static const int R_QUERY = 0;
	static const int R_ALTA = 1;
	static const int R_RESPUESTA_PARCIAL = 2;
	static const int R_RESPUESTA_FINAL = 3;
	static const int R_RESPUESTA_VACIA = 4;

	int tipoRequest;
	int senderPID;
	Registro contentRequest; //request recibido para procesar. en forma de Registro
	std::list<Registro> respuestaRequest;  //lista con los registros obtenidos de una query
	Cola<request> cola;

public:
	ComunicadorServer(std::string pathBaseDatos);
	virtual ~ComunicadorServer();
	bool esperarRequest();
	void procesarRequest();
	void enviarRespuesta();
	void cerrar(); //destruye la cola
};

#endif /* COMUNICADORSERVER_H_ */
