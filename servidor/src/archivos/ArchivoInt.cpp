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

int ArchivoInt::leer(int position) {
	stream.seekg(position*(sizeof(position)));
	return this->leer();
}

int ArchivoInt::escribir(const int numero) {
	stream.seekg(0, ios::end);
	int id = (stream.tellg()+ 1) /sizeof(int);
	stream.write((char*)&numero, sizeof(int));
	//retorno en que posicion quedo el registro
	return id;
}

int ArchivoInt::leer() {
	if(eof_val){
		throw ArchivoException("Se alcanzo el final de archivo", "eof");
	}
	int buffer;
	eof_val = !stream.read((char*)(&buffer), sizeof(buffer));
	return buffer;

}
