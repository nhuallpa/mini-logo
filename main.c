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
	FILE* fimagen = NULL;
	int estado = EXITOSO;
	if (argc == 5) {
		if ((fimagen = fopen(argv[1], "rb")) == NULL) {
			estado = NOEXISTE_IMAGEN;
		} else {
			char* ruta = "salida.bmp";
			tColor color;
			color.B = 255;
			color.R = 0;
			color.G = 0;
			tBmp* bmp = (tBmp*)malloc(sizeof(tBmp));
			inicializar(bmp);
			pintar(bmp, 0 , 0, &color);
			publicar(bmp, ruta);
			destruir(bmp);
		}
	} else {
		estado = CANT_PARAM_INV;
	}

	if (estado == EXITOSO) fclose(fimagen);
	return estado;
}
