/*
 * ArchivoException.h
 *
 *  Created on: 03/10/2014
 *      Author: jonathan
 */

#ifndef ARCHIVOEXCEPTION_H_
#define ARCHIVOEXCEPTION_H_

#include "Exception.h"

/**
 * Excepcion para cuando un proceso es Archivo por una senial
 */
class ArchivoException: public Exception {
public:
	ArchivoException(string mje, string cause);
	~ArchivoException();
};

#endif /* ARCHIVOEXCEPTION_H_ */
