/*
 ============================================================================
 Name        : main.c
 Author      : Huallpa Nestor
 Version     : 1.0
 Description : punto de entrada
 ============================================================================
*/
#define TEST_
#include "testEstadosTortuga.h"
#include "testListaRepetir.h"
#include "testBmp.h"
#include <stdio.h>
#include "color.h"
#include "bmp.h"
#include "bmpVista.h"
#include "dominioLogo.h"



int main(int argc, char* argv[]) {

#if defined(TEST)
	testSuiteTortuga();
	testSuiteLista();
	testSuiteBMP();
#else
	int estado = EXITOSO;
	FILE* fLogoInstrucciones;
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

	if (argc == 3) {
		fclose(fLogoInstrucciones);
	}

#endif
	printf(" estado : %d paramtros %d", estado, argc);
	return estado;
}


