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
#include <list>

class ComunicadorCliente {
private:
	Cola<request>* cola;
public:
	ComunicadorCliente();
	virtual ~ComunicadorCliente();
	std::list<Registro> enviarQuery(Registro reg);
	Registro enviarAlta(Registro);
};

#endif /* COMUNICADORCLIENTE_H_ */
