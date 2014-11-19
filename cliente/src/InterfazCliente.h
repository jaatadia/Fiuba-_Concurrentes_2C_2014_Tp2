/*
 * InterfazCliente.h
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#ifndef INTERFAZCLIENTE_H_
#define INTERFAZCLIENTE_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#include "ComunicadorCliente.h"
#include "Constantes.h"

class InterfazCliente {
public:
	InterfazCliente();
	virtual ~InterfazCliente();
	bool procesarEntrada();
private:

	string getEntrada();
	vector<string> parse(string cadena,char delim1, char delim2);
	bool procesarComando(vector<string> vec);


	typedef bool (InterfazCliente::*func_t)(vector<string>);
	map<const string,func_t> comandos;
	bool commandNotFound(vector<string> vec);
	bool exit(vector<string> vec);
	bool add(vector<string> vec);
	bool query(vector<string> vec);

	ComunicadorCliente comunicador;
	bool continueInput;
};

#endif /* INTERFAZCLIENTE_H_ */
