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

	try{
	signal(SIGINT,endInput);
	try{
		InterfazCliente inter;
		cout<<START_MESSAGE<<endl;
		while(inter.procesarEntrada());
		cout<<END_MESSAGE<<endl;
	}catch(string& error){
		cout<<error<<endl;
	}
	} catch (string & e){
		cout << e << endl;
	}
}
