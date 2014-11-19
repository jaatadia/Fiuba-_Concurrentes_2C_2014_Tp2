/*
 * Registro.h
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#ifndef REGISTRO_H_
#define REGISTRO_H_

#include <string>

static const int LENGTH_NOMBRE=61;
static const int LENGTH_DIRECCION=120;
static const int LENGTH_TELEFONO=13;

class Registro {
public:
	Registro();
	Registro(std::string nombre,std::string direccion ,std::string telefono);
	virtual ~Registro();
	std::string getNombre();
	std::string getDireccion();
	std::string getTelefono();
	void getNombre(char nombre[LENGTH_NOMBRE]);
	void getDireccion(char direccion[LENGTH_DIRECCION]);
	void getTelefono(char telefono[LENGTH_TELEFONO]);
private:
	std::string nombre;
	std::string direccion;
	std::string telefono;
};

#endif /* REGISTRO_H_ */
