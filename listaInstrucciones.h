/*
 * listaInstrucciones.h
 *
 *  Created on: 03/04/2011
 *      Author: Administrador
 */

#ifndef __LISTAINSTRUCCIONES_H_
#define __LISTAINSTRUCCIONES_H_
#include <malloc.h>
#include "instruccion.h"


struct nodo{
	struct nodo* siguienteNodo;
	tInstruccion* instruccion;
};

typedef struct nodo tNodo;


tNodo* crearListaInstruciones();

void agregar(tNodo* raiz, tInstruccion* instruccion);

void liberarListaInstrucciones(tNodo* raiz);


#endif /* LISTAINSTRUCCIONES_H_ */
