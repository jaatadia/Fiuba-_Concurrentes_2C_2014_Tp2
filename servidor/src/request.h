/*
 * request.h
 *
 *  Created on: Nov 23, 2014
 *      Author: florencia
 */

//TODO !!!! revisar lo copiado

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

