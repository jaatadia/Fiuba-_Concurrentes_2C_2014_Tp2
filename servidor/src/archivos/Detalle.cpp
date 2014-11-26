/*
 * Detalle.cpp
 *
 *  Created on: 19/11/2014
 *      Author: jonathan
 */

#include "Detalle.h"

Detalle::Detalle(const string& path ): archivo(path+"-detalle.dat") {

}

int Detalle::guardar(Registro & r) {
	int pos = archivo.escribir(r.getNombre());
	archivo.escribir(r.getDireccion());
	archivo.escribir(r.getTelefono());
	return pos;
}

Registro Detalle::leer(int offset) {
	string nombre =archivo.leer(offset);
	string direccion = archivo.leer();
	string telefono = archivo.leer();
	Registro re(nombre,direccion,telefono);
	return re;
}

Detalle::~Detalle() {
}

