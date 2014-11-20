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

static const std::string PRESENTADOR = "El registro es: ";
static const std::string PRESENTADOR_NOMBRE="Nombre: ";
static const std::string PRESENTADOR_DIRECCION=" Direccion: ";
static const std::string PRESENTADOR_TELEFONO=" Telefono: ";

class Registro {
public:
	Registro();
	Registro(std::string nombre,std::string direccion ,std::string telefono);
	virtual ~Registro();
	std::string getNombre();//devuelve el nombre
	std::string getDireccion();//devuelve la direccion
	std::string getTelefono();//devuelve el telefono
	void getNombre(char nombre[LENGTH_NOMBRE]);//guarda el nombre del registro en el puntero "nombre"
	void getDireccion(char direccion[LENGTH_DIRECCION]);//guarda la direccion del registro en el puntero "direccion"
	void getTelefono(char telefono[LENGTH_TELEFONO]);//guarda el telefono del registro en el puntero "telefono"
	std::string toString();//devuelve los datos en un formato escribible por pantalla
private:
	std::string nombre;
	std::string direccion;
	std::string telefono;
};
#endif /* REGISTRO_H_ */
