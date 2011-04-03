/*
 * testListaRepetir.c
 *
 *  Created on: 03/04/2011
 *      Author: Administrador
 */

#include "testListaRepetir.h"

void mainTestSuiteLista() {

	testReservarYLiberar();
	testAgregarYRecuperar();

}


void testReservarYLiberar() {

	tInstruccion instruccion;

	tNodo* listaInstrucciones = crearListaInstruciones();

	instruccion.idInstruccion = 1;
	instruccion.valor = 1;
	agregar(listaInstrucciones, &instruccion);

	instruccion.idInstruccion = 2;
	instruccion.valor = 2;
	agregar(listaInstrucciones, &instruccion);
	instruccion.idInstruccion = 3;
	instruccion.valor = 3;
	agregar(listaInstrucciones, &instruccion);


	liberarListaInstrucciones(listaInstrucciones);

}

void testAgregarYRecuperar() {
	// todo: probar esto
	tInstruccion instruccion;

	tNodo* listaInstrucciones = crearListaInstruciones();

	instruccion.idInstruccion = 1;
	instruccion.valor = 1;
	agregar(listaInstrucciones, &instruccion);
	instruccion.idInstruccion = 2;
	instruccion.valor = 2;
	agregar(listaInstrucciones, &instruccion);
	instruccion.idInstruccion = 3;
	instruccion.valor = 3;
	agregar(listaInstrucciones, &instruccion);

	// recuperamos y verificamos
//	recuperarInstruccion(listaInstrucciones, &instruccion, LIST_PRIMERO);
//	assertEqualsInt(1, instruccion->idInstruccion);
//	assertEqualsInt(1, instruccion->valor);
//	recuperarInstruccion(listaInstrucciones, &instruccion, LIST_SIGUIENTE);
//	assertEqualsInt(2, instruccion->idInstruccion);
//	assertEqualsInt(2, instruccion->valor);
//	recuperarInstruccion(listaInstrucciones, &instruccion, LIST_SIGUIENTE);
//	assertEqualsInt(3, instruccion->idInstruccion);
//	assertEqualsInt(3, instruccion->valor);
	// liberamos recursos
	liberarListaInstrucciones(listaInstrucciones);

}
