/*
 * ArchivoStr.h
 *
 *  Created on: 25/11/2014
 *      Author: jonathan
 */

#ifndef SRC_ARCHIVOS_ARCHIVOSTR_H_
#define SRC_ARCHIVOS_ARCHIVOSTR_H_
#include "Archivo.h"

class ArchivoStr: public Archivo {
public:
	ArchivoStr(const string&);
	virtual ~ArchivoStr();
	string leer();
	string leer(int position);
	int escribir(const string &);
};

#endif /* SRC_ARCHIVOS_ARCHIVOSTR_H_ */
