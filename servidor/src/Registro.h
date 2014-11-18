/*
 * Registro.h
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#ifndef REGISTRO_H_
#define REGISTRO_H_

#include <string>

class Registro {
public:
	Registro();
	Registro(std::string nombre,std::string direccion ,std::string telefono);
	virtual ~Registro();
	std::string getNombre();
	std::string getDireccion();
	std::string getTelefono();
private:
	char nombre[61];
	char direccion[120];
	char telefono[13];
};

#endif /* REGISTRO_H_ */
