/*
 * request.h
 *
 *  Created on: Nov 20, 2014
 *      Author: florencia
 */

#ifndef REQUEST_H_
#define REQUEST_H_

typedef struct request {
	long mtype;
	long senderPid;
	short tipoRequest;
	char nombre[61]; //TODO ! esto lo dejo así o lo pongo en constantes? o como define acá arriba?
	char direccion[120];
	char telefono[13];
} request;

#endif /* REQUEST_H_ */

//TODO !!! copiar este archivo y Cola.h al src del proyecto servidor (cuando esté chequeado y ande)


