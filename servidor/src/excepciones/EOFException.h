/*
 * ArchivoException.h
 *
 *  Created on: 03/10/2014
 *      Author: jonathan
 */

#ifndef EOFEXCEPTION_H_
#define EOFEXCEPTION_H_

#include "ArchivoException.h"

/**
 * Excepcion de acceso ante un eof.
 */
class EOFException: public ArchivoException {
public:
	EOFException(string mje, string cause);
	~EOFException();
};

#endif /* EOFEXCEPTION_H_ */
