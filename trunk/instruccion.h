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

#define CANT_INSTRUCCIONES 8
#define ID_INVALIDO -1

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




#endif /* INSTRUCCION_H_ */
