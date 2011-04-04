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

typedef enum { LIST_PRIMERO, LIST_SIGUIENTE} tPosicionado;

struct nodo {
	struct nodo* siguienteNodo;
	tInstruccion* instruccion;
};

typedef struct nodo tNodo;


/*
 * Crea una nodo de lista en estado vacio
 * Retorno el nodo puntero
 * */
tNodo* crearListaInstruciones();

/*
 * Agrega dinamicamente una nodo a la lista y almacena
 * los datos de la instruccion
 * **/
void agregar(tNodo* raiz, tInstruccion* instruccion);

/*
 * Libera todos los recursos
 * */
void liberarListaInstrucciones(tNodo* raiz);


/*
 * Recupara los instrucciones de la lista y los carga en la instruccion
 * pasada por parametro.
 *
 * Se utiliza los enumerados LIST_PRIMERO y LIST_SIGUIENTE para recorrer
 * de manera secuencial la lista completa.
 *
 * Retorna ENCONTRADO si se puedo cargar la instruccion correctamente
 * Retorna NO_HAY_SIG si no puedo cargar la instruccion correctamente porque
 * ha llegado a al final de la lista.
 * */
tEstadoRecorrido recuperarInstruccion(tNodo* raiz, tInstruccion* instruccion,
								tPosicionado posicionamiento);
/**
 * Crea un nodo vacio y lo deja en estado valido
 * */
tNodo* crearNodo();


#endif /* LISTAINSTRUCCIONES_H_ */
