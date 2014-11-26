/*
 * Maestro.h
 *
 *  Created on: 19/11/2014
 *      Author: jonathan
 */

#ifndef MAESTRO_H_
#define MAESTRO_H_
#include "../Registro.h"
#include "Detalle.h"
#include "ArchivoInt.h"
#include <string>
#include <list>
using namespace std;

class Maestro {
private:
	Detalle detalle;
	ArchivoInt archivo;
public:
	Maestro(const string&);
	virtual ~Maestro();
	list<Registro> query(Registro &);
	int guardar(Registro &);
	bool match(Registro & filtro, Registro & datos);
};

#endif /* MAESTRO_H_ */
