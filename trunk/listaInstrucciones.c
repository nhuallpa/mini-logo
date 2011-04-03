/*
 * listaInstrucciones.c
 *
 *  Created on: 03/04/2011
 *      Author: Administrador
 */

#include "listaInstrucciones.h"

tNodo* crearListaInstruciones() {
	tNodo* primero = crearNodo();
	return primero;
}


void agregar(tNodo* raiz, tInstruccion* instruccion) {

	if (raiz && raiz->instruccion) {
		tNodo* nuevoNodo = crearNodo();
		nuevoNodo->instruccion = crearInstruccion(instruccion);

		tNodo* nodoAuxActual = raiz;
		tNodo* ultimoNodo = NULL;
		while (nodoAuxActual) {
			ultimoNodo = nodoAuxActual;
			nodoAuxActual = nodoAuxActual->siguienteNodo;
		}
		ultimoNodo->siguienteNodo = nuevoNodo;
	} else if (raiz && raiz->instruccion == NULL) {
		raiz->instruccion = (tInstruccion*)malloc(sizeof(tInstruccion));
		raiz->instruccion->idInstruccion = instruccion->idInstruccion;
		raiz->instruccion->valor = instruccion->valor;

	}
}

void liberarListaInstrucciones(tNodo* raiz) {

	tNodo* nodoSiguiente = raiz;
	tNodo* nodoALiberar = NULL;
	while (nodoSiguiente) {
		nodoALiberar = nodoSiguiente;
		if (nodoALiberar->instruccion) {
			free(nodoALiberar->instruccion);
		}
		nodoSiguiente = nodoALiberar->siguienteNodo;
		free(nodoALiberar);
	}
}

tEstadoRecorrido recuperarInstruccion(tNodo* raiz, tInstruccion* instruccion,
								tPosicionado posicionamiento) {
	tEstadoRecorrido estado = OK;
	static tNodo* nodoActual;
	if (posicionamiento == LIST_PRIMERO) {
		nodoActual = raiz;
	} else if (posicionamiento == LIST_SIGUIENTE) {
		nodoActual = nodoActual->siguienteNodo;
	}

	if (nodoActual && nodoActual->instruccion && instruccion) {
		instruccion->idInstruccion = nodoActual->instruccion->idInstruccion;
		instruccion->valor = nodoActual->instruccion->valor;
	} else {
		estado = NO_HAY_SIG;
	}

	return estado;
}


tNodo* crearNodo() {
	tNodo* nuevoNodo = (tNodo*)malloc(sizeof(tNodo));
	nuevoNodo->instruccion = NULL;
	nuevoNodo->siguienteNodo = NULL;
	return nuevoNodo;
}

