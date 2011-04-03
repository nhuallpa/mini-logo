/*
 * testUnit.c
 *
 *  Created on: 03/04/2011
 *      Author: Administrador
 */

#include "testUnit.h"

void assertEqualsInt(int esperado, int resultado, char* nombreTest) {
	if (resultado != esperado) {
		printf("Fallo en '%s': se esperaba %d se recibio %d \n", nombreTest,
																esperado,
																resultado);
	}
}

void assertTrue(tBoolean expresion, char* nombreTest) {
	if (expresion == FALSE) {
		printf("Fallo en '%s': se esperaba TRUE se recibio FALSE \n", nombreTest);
	}
}

void assertFalse(tBoolean expresion, char* nombreTest) {
	if (expresion == TRUE) {
		printf("Fallo en '%s': se esperaba FALSE se recibio TRUE \n", nombreTest);
	}
}
