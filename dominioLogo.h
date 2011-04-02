/*
 * dominioLogo.h
 *
 *  Created on: 02/04/2011
 *      Author: Nestor
 */

#ifndef __DOMINIOLOGO_H_
#define __DOMINIOLOGO_H_

#define LONG_BUFFER 100

#include <stdio.h>
#include "bmp.h"
#include "instruccion.h"
/*
 * Leer una linea del archivo acotada por
 */
char* leerLinea(FILE* fLogoInstrucciones, char* bufferLinea);


//  Ejecuta en orden la lectura, interpretacion y ejecucion de
//  las instrucciones
void ejecutarInstrucciones(FILE* fLogoInstrucciones, tBitmapData* bmp_data);


#endif /* DOMINIOLOGO_H_ */
