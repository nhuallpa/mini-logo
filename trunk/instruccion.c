/*
 * instruccion.c
 *
 *  Created on: 02/04/2011
 *      Author: Administrador
 */

#include "instruccion.h"

static const char* listInstrucciones[] = {
		"ad", "de", "iz", "sp", "cp", "repite", "end", "fcolor"
};


tEstado leerInstruccion(tInstruccion* instruccion, char* strInstruccion) {

	tEstado estadoLectura = ERROR;
	if (validarInstruccion(strInstruccion) == OK){
		cargarInstruccion(strInstruccion, instruccion);
		estadoLectura = OK;
	}
	return estadoLectura;
}

tEstado validarInstruccion(char* strInstruccion) {
	tEstado estado = OK;
	if (buscarIdInstruccion(strInstruccion) == ID_INVALIDO) {
		estado = ERROR;
	}
	return estado;
}

void cargarInstruccion(char* strInstruccion, tInstruccion* instruccion) {

	instruccion->idInstruccion = buscarIdInstruccion(strInstruccion);
	instruccion->valor = tomarValor(strInstruccion);

}

int buscarIdInstruccion(char* strInstruccion) {
	int idInstruccion = ID_INVALIDO;
	int indice = 0;
	for ( indice = 0; indice < CANT_INSTRUCCIONES; indice++) {
		int encontrado = strnicmp(strInstruccion,
									listInstrucciones[indice],
									strlen(listInstrucciones[indice]));

		if (encontrado ==  0) {
			idInstruccion = indice;
			continue;
		}
	}
	return idInstruccion;
}

int tomarValor(char* strInstruccion) {
	char dummy[LONG_BUFFER];
	int valor = 0;
	if (sscanf(strInstruccion, "%s %d", dummy, &valor) == 0) {
		valor = 0;
	}
	return valor;
}

void mostrarInstruccionConsola(tInstruccion* instruccion) {
	printf("instruccion %d valor %d \n", instruccion->idInstruccion,
											instruccion->valor);
}

tInstruccion* crearInstruccion(tInstruccion* instruccion) {
	tInstruccion* nuevaInstruccion = NULL;
	if (instruccion) {
		nuevaInstruccion = (tInstruccion*)malloc(sizeof(tInstruccion));
		nuevaInstruccion->idInstruccion = instruccion->idInstruccion;
		nuevaInstruccion->valor = instruccion->valor;
	}
	return nuevaInstruccion;
}




