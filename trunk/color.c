/*
 * color.c
 *
 *  Created on: Mar 18, 2011
 *      Author: nestor
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

