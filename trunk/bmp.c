/*
 * bmp.c
 *
 *  Created on: Mar 18, 2011
 *      Author: nestor
 */
#include "bmp.h"


int  filtroPorColor(FILE* fimagen, tColor* color, tBitmapData* bmp) {
	int estado = EXIT_SUCCESS;
	int ancho, alto;

	estado = cargarAnchoAlto(fimagen, &ancho, &alto);
	if (estado == EXIT_SUCCESS) {
		bmp->alto = alto;
		bmp->ancho = ancho;
		cargarPorColor(bmp, fimagen, color);
	}
	return estado;
}

void destruirBMPData(tBitmapData* bmp) {
	free(bmp);
}

int cargarAnchoAlto(FILE* fimagen, int* ancho, int* alto) {
	int estado = EXIT_SUCCESS;
	estado = fseek(fimagen, 18, SEEK_SET);
	if (estado == EXIT_SUCCESS) {
		*ancho = leerEntero(fimagen);
		*alto = leerEntero(fimagen);
	}
	return estado;
}

int cargarPorColor(tBitmapData* bmp_data, FILE* fimagen, tColor* color) {
	int estado = EXIT_SUCCESS;

	estado = posicionarComienzoImagen(fimagen);

	int fil=0, col=0;
	for (fil = 0; fil < bmp_data->alto; fil++ ) {
		for (col = 0; col < bmp_data->ancho; col++) {
			tColor pixel;
			leerSiguientePixel(fimagen, &pixel);
			if (sonIguales(color, &pixel)) {
				cargarPixel(bmp_data, &pixel, fil, col);
			} else {
				blankearPixel(bmp_data, fil, col);
			}
		}
		retornoCarro(fimagen, bmp_data->ancho);
	}
	return 0;
}

int posicionarComienzoImagen(FILE* fimagen) {
	return fseek(fimagen, 54, SEEK_SET);
}

int leerSiguientePixel(FILE* fimagen, tColor* pixel) {

	// pixel ordenado en el arhivo como BGR

	pixel->B = fgetc(fimagen);
	pixel->G = fgetc(fimagen);
	pixel->R = fgetc(fimagen);

	return 0;
}

void cargarPixel( tBitmapData* bmp_data, tColor* pixel,
							int fil, int col) {
	bmp_data->puntos[fil][col].pixel.R = pixel->R;
	bmp_data->puntos[fil][col].pixel.G = pixel->G;
	bmp_data->puntos[fil][col].pixel.B = pixel->B;
}

void blankearPixel(tBitmapData* bmp_data, int fil, int col) {
	bmp_data->puntos[fil][col].pixel.R = -1;
	bmp_data->puntos[fil][col].pixel.G = -1;
	bmp_data->puntos[fil][col].pixel.B = -1;
}

int leerEntero(FILE* fimagen) {
	// Consideramos que los 4 bytes estan ordenados en little endian
	int byte1 = fgetc(fimagen);
	int byte2 = fgetc(fimagen);
	int byte3 = fgetc(fimagen);
	int byte4 = fgetc(fimagen);
	return  byte4*(3*256) + byte3*(2*256) + byte2*256 + byte1;
}

void retornoCarro(FILE* fimage, int ancho) {
	int nroBytesPadding = ancho % 4;
	int i = 0;
	for (i = 0; i < nroBytesPadding; i++)
		fgetc(fimage);
}

int obtenerPuntosEntorno(tBitmapData* bmp, int fila, int columna, tPunto* listaPuntos[]) {
	int cantPuntos = 0;

	if (fila == (bmp->alto-1)) { // si es ultima fila
		if (columna != (bmp->ancho-1)) { // si no es ultima columna
			listaPuntos[0] = &bmp->puntos[fila][columna + 1]; // Derecha
			cantPuntos = 1;
		}
	} else { // No es ultima fila
		if (columna == 0 ) {
			listaPuntos[0] = &bmp->puntos[fila + 1][columna]; // Abajo
			listaPuntos[1] = &bmp->puntos[fila + 1][columna + 1]; // Abajo - Derecha
			listaPuntos[2] = &bmp->puntos[fila][columna + 1]; // Derecha
			cantPuntos = 3;
		}
		if (columna == (bmp->ancho-1)) {
			listaPuntos[0] = &bmp->puntos[fila + 1][columna]; // Abajo
			listaPuntos[1] = &bmp->puntos[fila + 1][columna - 1]; // Abajo - Izquierda
			cantPuntos = 2;
		}
		if (columna != 0 && columna != (bmp->ancho-1)) { // si no esta en los extremos de columnas
			listaPuntos[0] = &bmp->puntos[fila + 1][columna]; // Abajo
			listaPuntos[1] = &bmp->puntos[fila + 1][columna + 1]; // Abajo - Derecha
			listaPuntos[2] = &bmp->puntos[fila][columna + 1]; // Derecha
			listaPuntos[3] = &bmp->puntos[fila + 1][columna - 1]; // Abajo - Izquierda
			cantPuntos = 4;
		}
	}
	return cantPuntos;
}


//  para logoMini


tBitmapData* crearBmpData(){
	return (tBitmapData*)malloc(sizeof(tBitmapData));
}


void inicializar(tBitmapData* bmp_data) {

	tColor blanco;
	blanco.B = 255;
	blanco.G = 255;
	blanco.R = 255;
	int fila = 0;
	for (fila = 0; fila < bmp_data->alto; fila++ ) {
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

