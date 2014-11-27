/*
 * BaseDatos.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#include "BaseDatos.h"
#include "excepciones/Exception.h"
BaseDatos::BaseDatos(std::string path): datos(path), lock(datos.getFileName()) {

}

BaseDatos::~BaseDatos() {
	// TODO Auto-generated destructor stub
}

std::list<Registro> BaseDatos::query(Registro & reg){
	return datos.query(reg);
}

bool BaseDatos::altaRegistro(Registro & reg){
	try {
		lock.tomarLock();
 		datos.guardar(reg);
		lock.liberarLock();
		return true;
	} catch (Exception & e){
		return false;
	}
}

