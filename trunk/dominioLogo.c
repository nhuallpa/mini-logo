/*
 * dominioLogo.c
 *
 *  Created on: 02/04/2011
 *      Author: Administrador
 */
#include "dominioLogo.h"

char* leerLinea(FILE* fLogoInstrucciones, char* bufferLinea) {
	return fgets(bufferLinea, LONG_BUFFER, fLogoInstrucciones);
}


void ejecutarInstrucciones(FILE* fLogoInstrucciones, tBitmapData* bmp_data) {

	char bufferLinea[100];

	tInstruccion instruccionesActual;

	while (leerLinea(fLogoInstrucciones, bufferLinea) != NULL){
		if (leerInstruccion(&instruccionesActual, bufferLinea) == OK) {

		}
	}

}
