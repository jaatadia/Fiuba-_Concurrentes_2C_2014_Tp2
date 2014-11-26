/*
 * ArchivoInt.h
 *
 *  Created on: 25/11/2014
 *      Author: jonathan
 */

#ifndef SRC_ARCHIVOS_ARCHIVOINT_H_
#define SRC_ARCHIVOS_ARCHIVOINT_H_
#include "Archivo.h"

class ArchivoInt: public Archivo {
public:
	ArchivoInt(const string & path);
	int leer(int position);
	int leer();
	int escribir(const int);
	virtual ~ArchivoInt();
};

#endif /* SRC_ARCHIVOS_ARCHIVOINT_H_ */
