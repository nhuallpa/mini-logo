/*
 * bmp.h
 *
 *  Created on: Mar 18, 2011
 *      Author: nestor
 *
 * Esta libreria contiene las funciones para armar el BMP en una estructura tBmpData
 */
#ifndef __BMP_H_
#define __BMP_H_
#include <stdio.h>
#include <malloc.h>
#include "color.h"

#define MAX_COORD 500

typedef struct {
	int x;
	int y;
}tPosicion;

typedef struct {
	void* lider;
	tColor pixel;
} tPunto;

typedef struct {
	int ancho, alto;
	tPunto puntos[MAX_COORD][MAX_COORD];
} tBitmapData;


/*
 * Libera la memoria dimamica reservada para el mapa
 * */
void destruirBMPData(tBitmapData* bmp);

/*
 * Retorta el puntro a un tBitmapData que tiene reservado con memoria dinamica
 */
tBitmapData* crearBmpData();

/*
 * Inicializa el tBitmapData de color blanco
 * Pre: necesita tener cargado las dimensiones
 */
void inicializarBmp(tBitmapData* bmp);

/*
 * Pinta el pixel que esta en el punto que se pasa por parametro
 * */
void pintarPunto(tPunto* punto, tColor* color);

/*
 * Verifica que los Xo y Yo caigan dentro de las dimensiones
 * del terreno a pintar
 */
tBoolean validaPosicion(int x0, int y0, tBitmapData* bmp_terreno);

/*
 * Modifica el terreno pintando en las coordenas indicadas con el color
 * pasado por parametro
 * Pre: Las coordenas deben ser validas
 */
void pintarPosicion(int x0, int y0, tBitmapData* bmp_terreno, tColor* color);

#endif /* BMP_H_ */
