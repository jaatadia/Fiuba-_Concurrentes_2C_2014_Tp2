//============================================================================
// Name        : servidor.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
using namespace std;

#include "Constantes.h"
#include "ComunicadorServer.h"


static const char* PATH_DB = "./base.db";
int main(int argc,char argv[]) {

	cout<<START_MESSAJE<<endl;

	bool child = false;
	ComunicadorServer comunicador(PATH_DB);
	while(!child && comunicador.esperarRequest()){
		int pid = fork();//todo verificar error
		if(pid==0){
			child = true;
			comunicador.procesarRequest();
			comunicador.enviarRespuesta();
		}
	}

	if(!child){
		comunicador.cerrar();
		cout<<END_MESSAJE<<endl;
	}
	//TODO ! y el return?
}
