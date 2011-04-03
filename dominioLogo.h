/*
 * dominioLogo.h
 *
 *  Created on: 02/04/2011
 *      Author: Nestor
 */

#ifndef __DOMINIOLOGO_H_
#define __DOMINIOLOGO_H_

#include <stdio.h>
#include "bmp.h"
#include "instruccion.h"
#include "common.h"

typedef struct {
	int x;
	int y;
	int angulo;
	tBoolean conPluma;
	tColor color;
} tTortuga;



typedef struct {
	tBitmapData* terreno;
	tTortuga tortuga;
	//TODO: Ver tipo de lista
	//tListaRepeat listaRepeat;
} tEntornoEjecucion;


/*
 * Leer una linea del archivo acotada por
 */
char* leerLinea(FILE* fLogoInstrucciones, char* bufferLinea);

/*
 * Ejecuta en orden la lectura, interpretacion y ejecucion de
 * las instrucciones
 */
void ejecutarInstrucciones(FILE* fLogoInstrucciones, tBitmapData* bmp_data);

void ejecutarInstruccion(tInstruccion* instruccion, tEntornoEjecucion* entorno);

void inicializarEntorno(tEntornoEjecucion* entornoActual, tBitmapData* bmp_data);

/*
 * Deja en estado inicial valido a una variable tortuga
 * */
void inicializarTortuga(tTortuga* tortuga);

void iAdelante(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual);

void iDerecha(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual);

void iIzquierda(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual);

void iSinPluma(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual);

void iConPluma(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual);

void iRepeate(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual);

void iEnd(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual);

void iFColor(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual);



#endif /* __DOMINIOLOGO_H_ */
