/*
 * bmp.c
 *
 *  Created on: Mar 18, 2011
 *      Author: nestor
 */
#include "bmp.h"


void destruirBMPData(tBitmapData* bmp) {
	free(bmp);
}

tBitmapData* crearBmpData() {
	return (tBitmapData*)malloc(sizeof(tBitmapData));
}


void inicializarBmp(tBitmapData* bmp_data) {
	tColor blanco;
	blanco.B = 255;
	blanco.G = 255;
	blanco.R = 255;
	int fila = 0;
	for (fila = 0; fila < bmp_data->alto; fila++) {
		int columna = 0;
		for (columna = 0; columna < bmp_data->ancho; columna++) {
			tPunto* puntoActual = &bmp_data->puntos[fila][columna];
			pintarPunto(puntoActual, &blanco);
		}
	}
}

void pintarPunto(tPunto* punto, tColor* color) {
	if (punto && color) {
		punto->pixel.B = color->B;
		punto->pixel.G = color->G;
		punto->pixel.R = color->R;
	}
}

tBoolean validaPosicion(int x0, int y0, tBitmapData* bmp_terreno) {
	tBoolean valido = FALSE;
	if (x0 >= 0 && x0 < bmp_terreno->alto &&
		y0 >= 0 && y0 < bmp_terreno->ancho) {
		valido = TRUE;
	}
	return valido;
}

void pintarPosicion(int x0, int y0, tBitmapData* bmp_terreno, tColor* color) {
	tPunto* punto = &bmp_terreno->puntos[x0][y0];
	pintarPunto(punto, color);
}





