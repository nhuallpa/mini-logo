/*
 * dominioLogo.h
 *
 *  Created on: 02/04/2011
 *      Author: Nestor
 */

#ifndef __DOMINIOLOGO_H_
#define __DOMINIOLOGO_H_
#include <stdio.h>
#include "bmp.h"


char* leerLinea(FILE* fLogoInstrucciones, char* buffeLinea);



//  Ejecuta en orden la lectura, interpretacion y ejecucion de
//  los comandos
void ejecutarComandos(FILE* fLogoInstrucciones, tBitmapData* bmp_data);


#endif /* DOMINIOLOGO_H_ */
