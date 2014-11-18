/*
 * ComunicadorCliente.h
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#ifndef COMUNICADORCLIENTE_H_
#define COMUNICADORCLIENTE_H_

#include "Registro.h"
#include <list>

class ComunicadorCliente {
public:
	ComunicadorCliente();
	virtual ~ComunicadorCliente();
	std::list<Registro> enviarQuery(Registro reg);
	Registro enviarAlta(Registro);
};

#endif /* COMUNICADORCLIENTE_H_ */
