/*
 * ArchivoStr.cpp
 *
 *  Created on: 25/11/2014
 *      Author: jonathan
 */

#include "ArchivoStr.h"
#include "../excepciones/ArchivoException.h"

ArchivoStr::ArchivoStr(const string& path):Archivo(path) {
}

ArchivoStr::~ArchivoStr() {
}

string ArchivoStr::leer() {
	//El formato de string es un byte con la longitud y luego los bytes con el string.
	if(eof_val){
		throw ArchivoException("Fin de archivo alcanzado", "eof");
	}
	char longitud;
	eof_val = !stream.read(&longitud, 1);
	char * buffer = new char[longitud];
	eof_val = !stream.read(buffer, longitud);
	string result(buffer);
	delete[] buffer;
	return result;

}


string ArchivoStr::leer(int position) {
	stream.seekg(position);
	return this->leer();
}



int ArchivoStr::escribir(const string& cadena) {
	int longitud = cadena.length();
	if (longitud > 255) {
		throw ArchivoException(
				"Error escribiendo cadena, se supero la longitud maxima de 255 caracteres",
				"Limite de cadenas excedido");
	}
	char lo = longitud;
	stream.seekg(0, ios::end);
	int pos = stream.tellg();
	stream.write((char*)&lo, 1);
	stream.write(cadena.c_str(), lo);
	return pos;
}
