/*
 * testEstadosTortuga.h
 *
 *  Created on: 02/04/2011
 *      Author: Administrador
 */

#ifndef TESTESTADOSTORTUGA_H_
#define TESTESTADOSTORTUGA_H_

#include "bmp.h"
#include "dominioLogo.h"

void testSuiteTortuga();

void testDerecha30();

void testDerecha30mas70();

void testDerecha30mas350es20();

void testIzq90es270grados();

void testIzq90mas90es180grados();

void testIzq90mas300es330grados();

void testPlumas();

void testColorear();

// testCommon

void assertEqualsInt(int esperado, int resultado, char* nombreTest);

void assertTrue(tBoolean expresion, char* nombreTest);

void assertFalse(tBoolean expresion, char* nombreTest);

#endif /* TESTESTADOSTORTUGA_H_ */
