/*
 * Cola.h
 *
 *  Created on: Nov 23, 2014
 *      Author: florencia
 */
#ifndef COLA_H_
#define COLA_H_

#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sstream>
using namespace std;

template <class T> class Cola {
	private:
		key_t	clave;
		int		id;
		string archivo;

	public:
		Cola(const string& archivo,const char letra);
		~Cola();
		int escribir(const T& dato) const; //devuelve 0 en exito, -1 en error (y tira el msj como excepción)
		int leer(const int tipo,T* buffer) const; //devuelve cant de bytes copiados en el buffer, o -1 en error (y tira el msj como excepción)
		int destruir() const; //devuelve 0 en exito, -1 en error (y tira el msj como excepción) - clientes NO deberían destruirla
};

//TODO !!!! revisar lo copiado!

template <class T> Cola<T>::Cola(const string& arch,const char letra): archivo(arch) {

	//el servidor crea el archivo
	FILE* fd = fopen(archivo.c_str(), "a+");
	if (!fd) {
		string mensaje = string("Error al crear el archivo de key para la cola: ") + string(strerror(errno));
		throw mensaje;
	}
	fclose(fd);

	//despues crea la cola
	this->clave = ftok(archivo.c_str(),letra);

	if (this->clave == -1){
		string mensaje = string("Error en ftok(): ") + string(strerror(errno));
		throw mensaje;
		return; //TODO !! esto funciona?
	}

	this->id = msgget(this->clave,0777|IPC_CREAT);
	if (this->id == -1) {
		string mensaje = string("Error en msgget al crear la cola: ") + string(strerror(errno));
		throw mensaje;
		return; //TODO !! esto funciona?
	}
}

template <class T> Cola<T>::~Cola() {
}

template <class T> int Cola<T>::destruir() const {
	int resultado = msgctl(this->id,IPC_RMID,NULL);
	if (resultado == -1){
		string mensaje = string("Error en msgctl al destruir la cola: ") + string(strerror(errno));
		throw mensaje;
	}
	unlink(archivo.c_str());
	return resultado;
}

template <class T> int Cola<T>::escribir(const T& dato) const {
	int resultado = msgsnd(this->id,static_cast<const void*>(&dato),sizeof(T)-sizeof(long),0);
	if (resultado == -1){
		string mensaje = string("Error en msgsnd: ") + string(strerror(errno));
		throw mensaje;
	}
	return resultado;
}

template <class T> int Cola<T>::leer(const int tipo,T* buffer) const {
	int resultado = msgrcv(this->id,static_cast<void*>(buffer),sizeof(T)-sizeof(long),tipo,0);
	if (resultado == -1){
		stringstream mensaje;
		mensaje << "Error en msgrcv (mensaje de tipo: " << tipo << "): " << strerror(errno);
		throw mensaje.str();
	}
	return resultado;
}

#endif /* COLA_H_ */
