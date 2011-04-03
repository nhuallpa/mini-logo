/*
 * testListaRepetir.c
 *
 *  Created on: 03/04/2011
 *      Author: Administrador
 */

#include "testListaRepetir.h"

void testSuiteLista() {

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

	instruccion.idInstruccion = 0;
	instruccion.valor = 0;

	// recuperamos y verificamos
	recuperarInstruccion(listaInstrucciones, &instruccion, LIST_PRIMERO);
	assertEqualsInt(1, instruccion.idInstruccion, "testAgregarYRecuperar");
	assertEqualsInt(1, instruccion.valor, "testAgregarYRecuperar");
	recuperarInstruccion(listaInstrucciones, &instruccion, LIST_SIGUIENTE);
	assertEqualsInt(2, instruccion.idInstruccion, "testAgregarYRecuperar");
	assertEqualsInt(2, instruccion.valor, "testAgregarYRecuperar");
	recuperarInstruccion(listaInstrucciones, &instruccion, LIST_SIGUIENTE);
	assertEqualsInt(3, instruccion.idInstruccion, "testAgregarYRecuperar");
	assertEqualsInt(3, instruccion.valor, "testAgregarYRecuperar");

	tEstadoRecorrido estado = recuperarInstruccion(listaInstrucciones, &instruccion, LIST_SIGUIENTE);
	assertTrue((estado == NO_HAY_SIG),"testAgregarYRecuperar");

	// liberamos recursos

	liberarListaInstrucciones(listaInstrucciones);

}
