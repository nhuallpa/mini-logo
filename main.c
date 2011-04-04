/*
 ============================================================================
 Name        : main.c
 Author      : Huallpa Nestor
 Version     : 1.0
 Description : punto de entrada del Mini interprete Logo
 ============================================================================
*/

#include <stdio.h>
#include "color.h"
#include "bmp.h"
#include "bmpVista.h"
#include "dominioLogo.h"

int main(int argc, char* argv[]) {
	int estado = EXITOSO;
	FILE* fLogoInstrucciones = NULL;
	char* imagenSalida = argv[1];

	if (argc == 3) {
		if ((fLogoInstrucciones = fopen(argv[2], "rb")) == NULL) {
			estado = NO_ENCUENTRO_ARCHIVO;
		}
	} else if (argc == 2) {
		fLogoInstrucciones = stdin;
	} else {
		estado = CANT_PARAM_INV;
	}

	if (estado == EXITOSO) {
		tBitmapData* bmp_data = crearTerrenoLogo();
		ejecutarInstrucciones(fLogoInstrucciones, bmp_data);
		publicar(bmp_data, imagenSalida);
		destruirBMPData(bmp_data);
	}

	if (estado == EXITOSO && argc == 3) {
		fclose(fLogoInstrucciones);
	}
	return estado;
}


