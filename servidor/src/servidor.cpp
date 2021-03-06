//============================================================================
// Name        : servidor.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <sys/types.h>
#include <sys/wait.h>

#include <iostream>
#include <unistd.h>
#include "signal.h"
using namespace std;

#include "Constantes.h"
#include "ComunicadorServer.h"
#include "excepciones/Exception.h"

bool endProgram=false;
void endInput(int signal){
	endProgram=true;
}



static const char* PATH_DB = "./base.db";
int main(int argc,char* argv[]) {

	int hijos=0;
	cout<<START_MESSAJE<<endl;
	signal(SIGINT,endInput);

	bool child = false;
	try {
		ComunicadorServer comunicador(PATH_DB);
		while(!endProgram && !child && comunicador.esperarRequest()){
			int pid = fork();//todo verificar error
			if(pid==0){
				child = true;
				comunicador.procesarRequest();
				comunicador.enviarRespuesta();
			}else{
				hijos++;
			}
		}

		if(!child){
			int status;
			cout<<END_MESSAJE_WAITING_KIDS<<endl;
			for (int i=0;i<hijos;i++) wait(&status);
			comunicador.cerrar();
			cout<<END_MESSAJE<<endl;
		}
	} catch (string & e){
		cout << e<<endl;
	} catch (Exception & e) {
		cout << e.what() << endl;
	} catch (...){
		cout << "Error desconocido" <<endl;
	}

	return 0;
}
