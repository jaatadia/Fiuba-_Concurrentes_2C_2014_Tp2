//============================================================================
// Name        : cliente.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <iostream>
#include "signal.h"
using namespace std;

#include "InterfazCliente.h"
#include "Constantes.h"



void endInput(int signal){
	fclose(stdin);
}


int main() {

	signal(SIGINT,endInput);

	InterfazCliente inter;
	cout<<START_MESSAGE<<endl;
	while(inter.procesarEntrada());
	cout<<END_MESSAGE<<endl;
}
