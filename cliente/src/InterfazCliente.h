/*
 * InterfazCliente.h
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#ifndef INTERFAZCLIENTE_H_
#define INTERFAZCLIENTE_H_

#include "ComunicadorCliente.h"

class InterfazCliente {
public:
	InterfazCliente();
	virtual ~InterfazCliente();
	bool procesarEntrada();
private:
	ComunicadorCliente comunicador;
};

#endif /* INTERFAZCLIENTE_H_ */
