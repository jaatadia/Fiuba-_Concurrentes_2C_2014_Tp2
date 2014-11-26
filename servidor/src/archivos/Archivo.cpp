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

using namespace std;

Archivo::Archivo(const string& path) :
		path(path), eof_val(false) {
	if(!exists_test(path)){
		fstream stream2;
		stream2.open(path.c_str(), std::ios::out);
		stream2.close();
	}
	fstream::openmode mode = fstream::in | std::ios::out | ios::binary;
	stream.open(path.c_str(), mode);
}

Archivo::~Archivo() {
	stream.close();
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

void Archivo::close() {
	stream.close();
}

bool Archivo::eof() {
	return eof_val;
}

void Archivo::start() {
	stream.seekg(0);
}
