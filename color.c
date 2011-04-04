/*
 * color.c
 *
 *  Created on: Mar 18, 2011
 *      Author: nestor
 *      V 1.0.1
 */
#include "color.h"

tColor tomarColor(char** argv) {
	tColor color;

	color.R = atoi(argv[2]);
	color.G = atoi(argv[3]);
	color.B = atoi(argv[4]);

	return color;
}

tBoolean sonIguales(tColor* color, tColor* otroColor) {
	tBoolean iguales = FALSE;
	if (color->R == otroColor->R &&
		color->G == otroColor->G &&
		color->B == otroColor->B) {
		iguales = TRUE;
	}
	return iguales;
}

void colorearBlanco(tColor* color) {
	color->R = 255;
	color->G = 255;
	color->B = 255;
}

void colorearNegro(tColor* color) {
	color->R = 0;
	color->G = 0;
	color->B = 0;
}

void colorearRojo(tColor* color) {
	color->R = 255;
	color->G = 0;
	color->B = 0;
}

void colorearVerde(tColor* color) {
	color->R = 0;
	color->G = 255;
	color->B = 0;
}

void colorearAzul(tColor* color) {
	color->R = 0;
	color->G = 0;
	color->B = 255;
}
