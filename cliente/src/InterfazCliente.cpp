/*
 * InterfazCliente.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#include "InterfazCliente.h"

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
	//todo
	return true;
}

bool InterfazCliente::query(vector<string> vec){
	//todo
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

vector<string> InterfazCliente::parse(string cadena,char delim1, char delim2){
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
