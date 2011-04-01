/*
 * color.h
 *
 *  Created on: Mar 18, 2011
 *      Author: nestor
 */

#ifndef _COLOR_H_
#define _COLOR_H_
#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE = 0,  TRUE = 1} tBoolean;

typedef struct  {
	char R;
	char G;
	char B;
} tColor;

/**
 * Obtiene el color desde los parametros del programa
 * */
tColor tomarColor(char** argv);

/*
 * Verifica que dos colores sean igual
 * */
tBoolean sonIguales(tColor* color, tColor* otroColor);

#endif /* COLOR_H_ */
