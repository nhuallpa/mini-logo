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




/**
 * Devuelve un entero con el estado de la ejecucion de este metodo
 * Reserva memoria para el param bmp
 * Liberar la memoria con destruir(bmp) luego de terminar de utilizarla
 * */
int  filtroPorColor(FILE* fimagen, tColor* color, tBitmapData* bmp);


/*
 * toma el ancho y el alto de la imagen .bmp
 *
 * */
int cargarAnchoAlto(FILE* fimagen, int* ancho, int* alto);

/**
* Leera 4 bytes del archivo a partir de la posicion en la que se encuentre
* formato RGB. Los datos se almacenan en orden inverso: BGR.
**/
int leerEntero(FILE* fimagen);

/**
 * Carga desde el archivo de .bmp hacia la estructura tBitmapData
 * */
int cargarPorColor(tBitmapData* bmp_data, FILE* fimagen, tColor* color);

/*
 * posiciona el puntero en al comienzo de los puntos que formar la imagen
 * */
int posicionarComienzoImagen(FILE* fimagen);

/**
 * carga un pixel en el bitmap data
 * */
void cargarPixel( tBitmapData* bmp_data, tColor* pixel,
							int fil, int col);

/**
 * Coloca al pixel ubicado en la columan y fila especificada en
 * estado valido
 * */
void blankearPixel(tBitmapData* bmp_data, int fil, int col);


/**
 * Leer los siguientes 3 bytes como un color y los carga en
 * el parametro pixel
 * */
int leerSiguientePixel(FILE* fimagen, tColor* pixel);


/*
 * Libera la memoria dimamica reservada para el mapa
 * */
void destruirBMPData(tBitmapData* bmp);

/**
 * Debido a que despues de finalizar la fila, se encuentran
 * dos bytes en exceso
 */
void retornoCarro(FILE* fimage, int ancho);

/**
 * Retorna la cantidad de puntos validos que se encontraron en el entorno
 * La referencia a los puntos se almacena en listaPuntos
 * */
int obtenerPuntosEntorno(tBitmapData* bmp,
						 int fila,
						 int columna,
						 tPunto*
						 listaPuntos[]);


//  Para LogoMini

tBitmapData* crearBmpData();

void inicializarBmp(tBitmapData* bmp);

void pintarPunto(tPunto* punto, tColor* color);

tBoolean validaPosicion(int x0, int y0, tBitmapData* bmp_terreno);

void pintarPosicion(int x0, int y0,tBitmapData* bmp_terreno,tColor* color);

#endif /* BMP_H_ */
