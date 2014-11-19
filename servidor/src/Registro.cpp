/*
 * Registro.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#include "Registro.h"

Registro::Registro(std::string nombre,std::string direccion,std::string telefono): nombre(nombre), direccion(direccion), telefono(telefono) {

}

Registro::~Registro() {
	// TODO Auto-generated destructor stub
}

std::string Registro::getNombre(){
	return this->nombre;
}

std::string Registro::getDireccion(){
	return this->direccion;
}

std::string Registro::getTelefono(){
	return this->telefono;
}

void copyString(std::string myString,char* cadena,int longitud){
	unsigned int i=0;
	while (i<longitud && i<myString.size()){
		cadena[i]=myString[i];
		i++;
	}
	if (i<longitud) cadena[i]='\0';
}


void Registro::getNombre(char nom[LENGTH_NOMBRE]){
	copyString(nombre,nom,LENGTH_NOMBRE);
}

void Registro::getDireccion(char dir[LENGTH_DIRECCION]){
	copyString(direccion,dir,LENGTH_DIRECCION);
}

void Registro::getTelefono(char tel[LENGTH_TELEFONO]){
	copyString(telefono,tel,LENGTH_TELEFONO);
}
