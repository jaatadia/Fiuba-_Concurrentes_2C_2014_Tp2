/*
 * BaseDatos.h
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#ifndef BASEDATOS_H_
#define BASEDATOS_H_

#include <list>
#include <string>
#include "Registro.h"
#include "archivos/Maestro.h"

/**
 * Encapsula el funcionamiento concurrente de los archivos.
 */
class BaseDatos {
private:
	Maestro datos;

public:
	BaseDatos(std::string path);
	virtual ~BaseDatos();

	std::list<Registro> query(Registro & reg);
	bool altaRegistro(Registro & reg);
};

#endif /* BASEDATOS_H_ */
