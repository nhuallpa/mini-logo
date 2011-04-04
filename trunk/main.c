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
	char* instrucciones = "enun1.log";
	FILE* fLogoInstrucciones = fopen(instrucciones, "rb");
	tBitmapData* bmp_data = crearTerrenoLogo();

	ejecutarInstrucciones(fLogoInstrucciones, bmp_data);

	publicar(bmp_data, "salida.bmp");
	destruirBMPData(bmp_data);
	fclose(fLogoInstrucciones);
#endif
	return 0;
}


