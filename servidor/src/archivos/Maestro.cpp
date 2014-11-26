/*
 * Maestro.cpp
 *
 *  Created on: 19/11/2014
 *      Author: jonathan
 */

#include "Maestro.h"

/**
 * Archivo de registros de longitud fija que contiene los ids de los registros.
 */
Maestro::Maestro(const string& path):detalle(path),archivo(path+"-id.idx") {


}

Maestro::~Maestro() {

}

list<Registro> Maestro::query(Registro& query) {
	list<Registro> result;
	archivo.start();

	while (!archivo.eof()){
		int valor = archivo.leer();
		if(valor > 0){
			Registro registro = detalle.leer(valor - 1);
			if(match(query,registro)){
				result.push_back(registro);
			}
		}

	}

	return result;
}


int Maestro::guardar(Registro & reg) {
	//prevenir guardar el caracter cero.
	int offset = detalle.guardar(reg) +1;
	int pos = archivo.escribir(offset);
	return pos;
}

bool Maestro::match(Registro& filtro, Registro& datos) {
	if(!filtro.getDireccion().empty() && filtro.getDireccion() != datos.getDireccion()){
		return false;
	}

	if(!filtro.getNombre().empty() && filtro.getNombre() != datos.getNombre()){
		return false;
	}
	if(!filtro.getTelefono().empty() && filtro.getTelefono() != datos.getTelefono()){
		return false;
	}
	return true;
}
