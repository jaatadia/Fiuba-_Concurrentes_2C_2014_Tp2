/*
 * ComunicadorCliente.h
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#ifndef COMUNICADORCLIENTE_H_
#define COMUNICADORCLIENTE_H_

#include "Registro.h"
#include "request.h"
#include "Cola.h"
#include "Constantes.h"
#include <list>
#include <unistd.h>

class ComunicadorCliente {
private:
	Cola<request> cola;

	static const int R_QUERY = 0;
	static const int R_ALTA = 1;
	static const int R_RESPUESTA_PARCIAL = 2;
	static const int R_RESPUESTA_FINAL = 3;
	static const int R_RESPUESTA_VACIA = 4;

public:
	ComunicadorCliente();
	virtual ~ComunicadorCliente();
	std::list<Registro> enviarQuery(Registro reg);
	bool enviarAlta(Registro); //todo ! cambiar en el diagrama de clases
};

#endif /* COMUNICADORCLIENTE_H_ */
