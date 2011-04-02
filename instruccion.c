/*
 * instruccion.c
 *
 *  Created on: 02/04/2011
 *      Author: Administrador
 */

#include "instruccion.h"

tEstado leerInstruccion(tInstruccion* instruccion, char* entrada) {

	tEstado estadoLectura = ERROR;
	char strInstruccion[100];

	if (sscanf(entrada, "%s", strInstruccion)) {
		if (validarInstruccion(strInstruccion) == OK){
			cargarInstruccion(strInstruccion, instruccion);
			estadoLectura = OK;
		}
	}

	return estadoLectura;
}

tEstado validarInstruccion(char* strInstruccion) {

	return OK;
}

void cargarInstruccion(char* strInstruccion,tInstruccion* instruccion) {

}
