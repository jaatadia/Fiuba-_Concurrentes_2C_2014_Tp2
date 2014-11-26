/*
 * Archivo.h
 *
 *  Created on: 19/11/2014
 *      Author: jonathan
 */

#ifndef ARCHIVO_H_
#define ARCHIVO_H_
#include <string>
using namespace std;
#include <fstream>   // file I/O
/**
 * Encapsulamiento de los formatos de escritura/lectura en archivo..
 */

class Archivo {
protected:
	fstream stream;
	int fd;
	string path;
	bool eof_val;
public:
	Archivo(const string&);
	virtual ~Archivo();
	bool exists_test (const std::string& name);
	void close();
	bool eof();
	void start();
};

#endif /* ARCHIVO_H_ */
