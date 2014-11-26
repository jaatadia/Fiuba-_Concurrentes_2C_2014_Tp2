/*
 * Archivo.cpp
 *
 *  Created on: 19/11/2014
 *      Author: jonathan
 */

#include "Archivo.h"
#include "../excepciones/ArchivoException.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
using namespace std;

Archivo::Archivo(const string& path) :
		path(path), eof_val(false) {
//	if(!exists_test(path)){
//		fstream stream2;
//		stream2.open(path.c_str(), std::ios::out);
//		stream2.close();
//	}
	file = fopen(path.c_str(),"ab+");
	if(file == NULL ){
		throw ArchivoException("No pudo abrirse el archivo "+ path, strerror(errno));
	}
}

Archivo::~Archivo() {
	fclose(file);
}


bool Archivo::exists_test (const std::string& name) {
    ifstream f(name.c_str());
    if (f.good()) {
        f.close();
        return true;
    } else {
        f.close();
        return false;
    }
}

bool Archivo::eof() {
	return eof_val;
}

void Archivo::start() {
	eof_val = false;
	fseek(file,0,SEEK_SET);
}
