/*
 * Constantes.h
 *
 *  Created on: Nov 18, 2014
 *      Author: javier
 */

#ifndef CONSTANTES_H_
#define CONSTANTES_H_


#include <string>

static const std::string START_MESSAGE = "Comenzando el cliente";
static const std::string END_MESSAGE = "Terminando el cliente";
static const std::string INPUT_MESSAGE = ">";
static const std::string INVALID_COMMAND_MESSAGE = "Comando Invalido: ";
static const std::string INVALID_PARAMETER_MESSAGE = "Parametro Invalido: ";
static const std::string MISSING_ARGUMENT_MESSAGE = "El parametro requiere argumento: ";

static const std::string INVALID_QUERY_MESSAGE = "No se pudo procesar el pedido, los parametros son erroneos";
static const std::string RESULTADO_QUERY_MESSAGE = "Los resultados son:";

static const std::string ALTA_REGISTRO_MESSAGE = "Se dio de alta el registro: ";

static const std::string DEFAULT_COMMAND = "ERROR";
static const std::string EXIT_COMMAND = "exit";
static const std::string ADD_COMMAND = "add";
static const std::string QUERY_COMMAND = "query";

static const std::string NAME_INPUT = "-nombre";
static const std::string ADR_INPUT = "-direccion";
static const std::string TEL_INPUT = "-telefono";




#endif /* CONSTANTES_H_ */
