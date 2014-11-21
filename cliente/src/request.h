/*
 * request.h
 *
 *  Created on: Nov 20, 2014
 *      Author: florencia
 */

#ifndef MENSAJES_H_
#define MENSAJES_H_

#define	PETICION	1
#define	RESPUESTA	2
#define TEXTO_SIZE	255


typedef struct mensaje {
	long mtype;
	int id;
	char texto[TEXTO_SIZE];
} mensaje;
//TODO !!

#endif /* MENSAJES_H_ */


