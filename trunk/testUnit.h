/*
 * testUnit.h
 *
 *  Created on: 03/04/2011
 *      Author: Administrador
 */

#ifndef _TESTUNIT_H_
#define _TESTUNIT_H_
#include "common.h"
#include <stdio.h>


void assertEqualsInt(int esperado, int resultado, char* nombreTest);

void assertTrue(tBoolean expresion, char* nombreTest);

void assertFalse(tBoolean expresion, char* nombreTest);


#endif /* TESTUNIT_H_ */
