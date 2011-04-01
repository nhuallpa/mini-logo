/*
 ============================================================================
 Name        : main.c
 Author      : Huallpa Nestor
 Version     : 1.0
 Description : punto de entrada
 ============================================================================
*/
#include<stdio.h>
#include "color.h"

#define EXITOSO			0
#define NOEXISTE_IMAGEN 2
#define CANT_PARAM_INV  1
#include "bmp.h"
#include "bmpVista.h"


int main(int argc, char* argv[]) {

	printf("tam uint %d", sizeof(uint));
	printf("tam ushort %d", sizeof(ushort));

	char* ruta = "salida.bmp";
	tColor color;
	color.B = 255;
	color.R = 0;
	color.G = 0;
	tBitmapData* bmp = (tBitmapData*)malloc(sizeof(tBitmapData));
	bmp->alto = 200;
	bmp->ancho = 200;
	inicializar(bmp);
	pintar(bmp, 0 , 0, &color);
	publicar(bmp, ruta);
	destruir(bmp);

	return 0;
}
