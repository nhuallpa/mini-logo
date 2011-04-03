/*
 * instruccion.h
 *
 *  Created on: 02/04/2011
 *      Author: Administrador
 */

#ifndef __INSTRUCCION_H_
#define __INSTRUCCION_H_
#include "common.h"
#include "string.h"
#include <stdio.h>
#include <malloc.h>

#define CANT_INSTRUCCIONES 8
#define ID_INVALIDO -1

typedef enum {
	I_ADELANTE, I_DERECHA, I_IZQUIERDA,
	I_SIN_PLUMA, I_CON_PLUMA, I_REPEAT, I_END, I_FCOLOR
} tTipoInstruccion;

typedef struct {
	int idInstruccion;
	int valor;
} tInstruccion;


/*
 * Parsea strInstruccion y carga el paramtro instruccion con valores validos
 * Retorno OK si se cargo de forma valida o ERROR en caso contrario
 */
tEstado leerInstruccion(tInstruccion* instruccion, char* strInstruccion);

/*
 * Valida que el parametro strInstruccion corresponde a una instruccion valida
 * Retorno OK si se valido de forma valida o ERROR en caso contrario
 */
tEstado validarInstruccion(char* strInstruccion);

/**
 * Busca la instrucciones pasada por parametro en la lista de
 * instrucciones.
 * Retorna el id de la instruccion si es encontrado la instruccion
 * Retorno ID_INVALIDO si no se encontro la instruccion
 * */
int buscarIdInstruccion(char* strInstruccion);

/**
 * Retorna un valor mayor o igual a cero que corresponde
 * a la instruccion tipo char* que llega por parametro
 * Por default retorna 0
 */
int tomarValor(char* strInstruccion);


/*
 * Modifaca la instruccion pasada por parametro con los datos pasados
 * por strInstruccion
 * */
void cargarInstruccion(char* strInstruccion, tInstruccion* instruccion);


void mostrarInstruccionConsola(tInstruccion* instruccion);

/*
 * Crea una nueva instancias de instruccion en el Heap
 * Retorna el puntero a la instruccion creada con memoria dinamica
 * Retorna NULL sin el parametro instruccion es NULL
 *
 * */
tInstruccion* crearInstruccion(tInstruccion* instruccion);

tBoolean esTipoInstruccion(tInstruccion* instruccion, tTipoInstruccion tipo);


#endif /* INSTRUCCION_H_ */
