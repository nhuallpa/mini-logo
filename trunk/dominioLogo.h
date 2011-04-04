/*
 * dominioLogo.h
 *
 *  Created on: 02/04/2011
 *      Author: Nestor
 */

#ifndef __DOMINIOLOGO_H_
#define __DOMINIOLOGO_H_

#define TAMANIO_MAX 200

#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "instruccion.h"
#include "listaInstrucciones.h"
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
	tNodo* bloqueRepeat;
	tBoolean armarBloqueRepeat;
	int nroRepeticiones;
} tEntornoEjecucion;

/*
 * Crear un terreno conveniente para la tortuga
 * */
tBitmapData* crearTerrenoLogo();

/*
 * Leer una linea del archivo acotada por
 */
char* leerLinea(FILE* fLogoInstrucciones, char* bufferLinea);

/*
 * Ejecuta en orden la lectura, interpretacion y ejecucion de
 * las instrucciones
 */
void ejecutarInstrucciones(FILE* fLogoInstrucciones, tBitmapData* bmp_data);

/*
 * Ejecuta procedimiento que corresponda a la instruccion para que
 * actualizice el entorno que fue pasado por parametro
 * */
void ejecutarInstruccion(tInstruccion* instruccion, tEntornoEjecucion* entorno);

void inicializarEntorno(tEntornoEjecucion* entornoActual, tBitmapData* bmp_data);

void liberarEntorno(tEntornoEjecucion* entornoActual);

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

void calcular_xy( int x0, int y0, int angle, int d, int *x1, int *y1 );

void pintar(tPosicion* posIni,
			tPosicion* posFin,
			tEntornoEjecucion* entorno);


#endif /* __DOMINIOLOGO_H_ */
