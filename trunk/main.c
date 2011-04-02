/*
 ============================================================================
 Name        : main.c
 Author      : Huallpa Nestor
 Version     : 1.0
 Description : punto de entrada
 ============================================================================
*/



#include <stdio.h>
#include "color.h"
#include "bmp.h"
#include "bmpVista.h"
#include "dominioLogo.h"

int main(int argc, char* argv[]) {

	char* instrucciones = "enun1.log";

	FILE* fLogoInstrucciones = fopen(instrucciones, "rb");

	tBitmapData* bmp_data = crearBmpData();
	ejecutarInstrucciones(fLogoInstrucciones, bmp_data);
	destruirBMPData(bmp_data);


	fclose(fLogoInstrucciones);



	return 0;
}


