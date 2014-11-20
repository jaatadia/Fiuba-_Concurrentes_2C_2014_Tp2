/*
 * InterfazCliente.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */
#include "InterfazCliente.h"

/* **********************************************************************
 *				funciones internas
 ***********************************************************************/

Registro getRecord(vector<string> vec,bool &valid, bool &nombre,bool &direccion, bool &telefono){
	string nom;	string tel;	string dir;
	valid=true;
	nombre=direccion=telefono=false;

	unsigned int i=1;
	while (valid && i<vec.size()){

		bool parametroValido=((vec[i]==NAME_INPUT)||(vec[i]==ADR_INPUT)||(vec[i]==TEL_INPUT));
		bool proximoValido=((i+1<vec.size()) && (vec[i+1]!=NAME_INPUT) && (vec[i+1]!=ADR_INPUT) && (vec[i+1]!=TEL_INPUT));

		if(parametroValido){
			if (proximoValido){
				if(vec[i]==NAME_INPUT){
					nom = vec[i+1];
					nombre=true;
				}else if(vec[i]==ADR_INPUT){
					dir = vec[i+1];
					direccion=true;
				}else if(vec[i]==TEL_INPUT){
					tel = vec[i+1];
					telefono=true;
				}
			}else{
				cout<<MISSING_ARGUMENT_MESSAGE<<vec[i]<<endl;
				valid=false;
			}
		}else{
			cout<<INVALID_PARAMETER_MESSAGE<<vec[i]<<endl;
			valid=false;
		}
		i+=2;
	}

	return Registro(nom,dir,tel);
}


vector<string> parse(string cadena,char delim1, char delim2){
	vector<string> parsed;
	string item="";
	char delim;
	for (unsigned int i=0;i<cadena.size();i++){
		item="";
		if(cadena[i]==delim2){
			delim=delim2;
			i++;
		}else{
			delim=delim1;
		}
		while(cadena[i]!=delim && i<cadena.size()){
			item = item+char(tolower(cadena[i]));
			i++;
		}
		if(item.size()!=0)parsed.push_back(item);
	}
	return parsed;
}


/* ----------------------------------------------------------------------------*/







InterfazCliente::InterfazCliente(): continueInput(true) {
	comandos[DEFAULT_COMMAND] = &InterfazCliente::commandNotFound;
	comandos[EXIT_COMMAND] = &InterfazCliente::exit;
	comandos[ADD_COMMAND] = &InterfazCliente::add;
	comandos[QUERY_COMMAND] = &InterfazCliente::query;
}

InterfazCliente::~InterfazCliente() {
	// TODO Auto-generated destructor stub
}

bool InterfazCliente::commandNotFound(vector<string> vec){
	cout<<INVALID_COMMAND_MESSAGE<<vec[0]<<endl;
	return true;
}

bool InterfazCliente::exit(vector<string> vec){
	continueInput=false;
	return false;
}

bool InterfazCliente::add(vector<string> vec){
	bool valid,nombre,dir,tel;
	Registro rec = getRecord(vec,valid,nombre,dir,tel);
	if(valid&&(nombre&&dir&&tel)){
		Registro recResult = comunicador.enviarAlta(rec);
		cout<<RESULT_ADD_MESSAGE<<recResult.toString()<<endl;
	}else{
		cout<<INVALID_ADD_MESSAGE<<endl;
	}
	return true;
}

bool InterfazCliente::query(vector<string> vec){
	bool valid,nombre,dir,tel;
	Registro rec = getRecord(vec,valid,nombre,dir,tel);
	if(valid&&(nombre||dir||tel)){
		list<Registro> resultado = comunicador.enviarQuery(rec);
		list<Registro>::iterator it;
		cout<<RESULT_QUERY_MESSAGE<<endl;
		for (it = resultado.begin();it!=resultado.end();it++){
			cout<<(*it).toString()<<endl;
		}
	}else{
		cout<<INVALID_QUERY_MESSAGE<<endl;
	}
	return true;
}

string InterfazCliente::InterfazCliente::getEntrada(){
	string entrada="";
	if(!cin.eof())cout<<INPUT_MESSAGE;getline(cin,entrada);
	if(cin.eof()) {
		continueInput=false;
		entrada="";
	}
	return entrada;
}



bool InterfazCliente::procesarComando(vector<string> vec){
	if (vec.size()==0) return true;
	func_t func = (comandos.find(vec[0])!=comandos.end()) ? comandos[vec[0]]:comandos[DEFAULT_COMMAND];
	return (this->*func)(vec);
}

bool InterfazCliente::procesarEntrada(){
		if(!continueInput) return false;
		string entrada = getEntrada();
		vector<string> myvec = parse(entrada,' ','"');
		return procesarComando(myvec);
}
