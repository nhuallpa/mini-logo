/*
 * dominioLogo.c
 *
 *  Created on: 02/04/2011
 *      Author: Administrador
 */
#include "dominioLogo.h"

char* leerLinea(FILE* fLogoInstrucciones, char* buffeLinea) {
	return fgets(buffeLinea, 100, fLogoInstrucciones);
}


void ejecutarComandos(FILE* fLogoInstrucciones, tBitmapData* bmp_data) {

	char bufferLinea[100];

		while (leerLinea(fLogoInstrucciones, bufferLinea) != NULL){
			printf("%s", bufferLinea);
		}

}
