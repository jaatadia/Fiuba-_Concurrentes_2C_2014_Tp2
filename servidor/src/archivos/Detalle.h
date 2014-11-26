/*
 * Detalle.h
 *
 *  Created on: 19/11/2014
 *      Author: jonathan
 */

#ifndef DETALLE_H_
#define DETALLE_H_
#include "ArchivoStr.h"
#include "../Registro.h"
class Detalle {
private:
	ArchivoStr archivo;
public:
	Detalle(const string& path);
	int guardar(Registro &);
	Registro leer(int offset);
	virtual ~Detalle();
};

#endif /* DETALLE_H_ */
