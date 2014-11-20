/*
 * Constantes.h
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#ifndef CONSTANTES_H_
#define CONSTANTES_H_


#include <string>


static const std::string DEFAULT_COMMAND = "ERROR";
static const std::string EXIT_COMMAND = "exit";
static const std::string ADD_COMMAND = "add";
static const std::string QUERY_COMMAND = "query";
static const std::string HELP_COMMAND = "help";

static const std::string NAME_INPUT = "-name";
static const std::string ADR_INPUT = "-address";
static const std::string TEL_INPUT = "-phone";


static const std::string START_MESSAGE = "Comenzando el cliente, para ver la ayuda ingresar: "+HELP_COMMAND;
static const std::string END_MESSAGE = "Terminando el cliente";
static const std::string INPUT_MESSAGE = ">";
static const std::string INVALID_COMMAND_MESSAGE = "Comando Invalido: ";
static const std::string INVALID_COMMAND_HELP_MESSAGE = "Para ver los comandos validos ver: "+HELP_COMMAND;

static const std::string INVALID_PARAMETER_MESSAGE = "Parametro Invalido: ";
static const std::string MISSING_ARGUMENT_MESSAGE = "El parametro requiere argumento: ";

static const std::string RESULT_QUERY_MESSAGE = "Los resultados son:";
static const std::string INVALID_QUERY_MESSAGE = "No se pudo procesar el pedido, los parametros son erroneos, se necesita al menos uno de los siguientes: "+NAME_INPUT+" "+ADR_INPUT+" "+TEL_INPUT;

static const std::string RESULT_ADD_MESSAGE = "Se dio de alta el registro: ";
static const std::string INVALID_ADD_MESSAGE = "No se pudo procesar el pedido, los parametros son erroneos, se necesitan: "+NAME_INPUT+" "+ADR_INPUT+" "+TEL_INPUT;

static const std::string INTEGRANTES_MESSAGE="Trabajo practico numero 2 - Tecnicas de programacion concurrentes 1 - 2ºC 2014\nIntegrantes: Alvarez Etcheverry Florencia (93408) Atadia Javier (93223) Tierno Jonatan (92713)\n";
static const std::string HELP_MESSAGE = INTEGRANTES_MESSAGE+"Los comandos posibles son:\n"+
		"\t"+HELP_COMMAND+": Para mostrar esa ayuda\n"+
		"\t"+QUERY_COMMAND+": Para realizar una consulta lleva los parametros: "+NAME_INPUT+" "+ADR_INPUT+" "+TEL_INPUT+" de los cuales al menos uno es necesario\n"+
		"\t"+ADD_COMMAND+": Para dar de alta un registro, lleva los parametros: "+NAME_INPUT+" "+ADR_INPUT+" "+TEL_INPUT+"\n"+
		"\t"+EXIT_COMMAND+" o ctrl-D: Para terminal el programa";






#endif /* CONSTANTES_H_ */
