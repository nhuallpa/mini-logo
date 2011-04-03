/*
 * listaInstrucciones.c
 *
 *  Created on: 03/04/2011
 *      Author: Administrador
 */

#include "listaInstrucciones.h"

tNodo* crearListaInstruciones() {
	tNodo* primero = (tNodo*)malloc(sizeof(tNodo));
	primero->siguienteNodo = NULL;
	return primero;
}


void agregar(tNodo* raiz, tInstruccion* instruccion) {

	tNodo* nuevoNodo = (tNodo*)malloc(sizeof(tNodo));
	nuevoNodo->instruccion = (tInstruccion*)malloc(sizeof(tInstruccion));
	nuevoNodo->siguienteNodo = NULL;

	nuevoNodo->instruccion->idInstruccion = instruccion->idInstruccion;
	nuevoNodo->instruccion->valor = instruccion->valor;

	tNodo* nodoAuxActual = raiz;
	tNodo* ultimoNodo = NULL;
	while (nodoAuxActual) {
		ultimoNodo = nodoAuxActual;
		nodoAuxActual = nodoAuxActual->siguienteNodo;
	}
	ultimoNodo->siguienteNodo = nuevoNodo;
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

