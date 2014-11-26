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
	eof_val = fread(&longitud,1,1,file) == EOF;
	char * buffer = new char[longitud];
	eof_val = fread(buffer, 1, longitud,file) == EOF;
	string result(buffer);
	delete[] buffer;
		if(ferror(file)){
			throw ArchivoException(
					"Error al leer de " + path,
					"Error de lectura");
		}
	return result;

}


string ArchivoStr::leer(int position) {
	int res = fseek(file, position, SEEK_SET);
	if(res != 0) {
		throw ArchivoException("Posicion de archivo "+ path + " invalida", "Fallo de seek");
	}
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
	fseek(file, 0, SEEK_END);
	int pos = ftell(file);
	fwrite(&lo,sizeof(char),1,file );
	if(ferror(file)){
		throw ArchivoException(
				"Error al escribir en " + path,
				"Error de escritura");
	}
	fwrite(cadena.c_str(),sizeof(char),lo,file );

	if(ferror(file)){
		throw ArchivoException(
				"Error al escribir en " + path,
				"Error de escritura");
	}
	return pos;
}
