/*
 * ArchivoInt.cpp
 *
 *  Created on: 25/11/2014
 *      Author: jonathan
 */

#include "ArchivoInt.h"
#include "../excepciones/ArchivoException.h"
ArchivoInt::ArchivoInt(const string & path): Archivo(path) {

}

ArchivoInt::~ArchivoInt() {
}

//int ArchivoInt::leer(int position) {
//	fseek(file,position*(sizeof(position)), SEEK_SET);
//	return this->leer();
//}

int ArchivoInt::escribir(const int numero) {
	//fseek(file,0, SEEK_END);
	int id = ftell(file);
	fwrite(&numero,sizeof(int),1,file );
	if(ferror(file)){
		throw ArchivoException(
				"Error al escribir en " + path,
				"Error de escritura");
	}
	//retorno en que posicion quedo el registro
	return id;
}

int ArchivoInt::leer() {
	if(eof_val){
		throw ArchivoException("Se alcanzo el final de archivo", "eof");
	}
	int buffer;
	eof_val = fread(&buffer,sizeof(int),1,file) == 0;
	if(ferror(file)){
		throw ArchivoException(
				"Error al leer de " + path,
				"Error de lectura");
	}
	return eof_val ? -1 : buffer;

}
