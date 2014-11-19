//============================================================================
// Name        : cliente.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "InterfazCliente.h"
#include "Constantes.h"

int main() {
	cout<<START_MESSAGE<<endl;
	InterfazCliente inter;
	while(inter.procesarEntrada());
	cout<<END_MESSAGE<<endl;
}
