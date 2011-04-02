/*
 * instruccion.h
 *
 *  Created on: 02/04/2011
 *      Author: Administrador
 */

#ifndef __INSTRUCCION_H_
#define __INSTRUCCION_H_
#include "common.h"
#include <stdio.h>

#define CANT_INSTRUCCIONES 8

static const char* listInstrucciones[] = {
		"ad", "de", "iz", "sp", "cp", "repite", "end", "fcolor"
};



typedef struct {
	int idInstruccion;
	int valor;
} tInstruccion;


tEstado leerInstruccion(tInstruccion* instruccion, char* cadena);

tEstado validarInstruccion(char* strInstruccion);

void cargarInstruccion(char* strInstruccion,tInstruccion* instruccion);


#endif /* INSTRUCCION_H_ */
