/*
 * testEstadosTortuga.c
 *
 *  Created on: 02/04/2011
 *      Author: Administrador
 */

#include "testEstadosTortuga.h"


void testSuiteTortuga(){
	testDerecha30();
	testDerecha30mas70();
	testDerecha30mas350es20();
	testIzq90es270grados();
	testIzq90mas90es180grados();
	testIzq90mas300es330grados();
	testPlumas();
	testColorear();
}

void testDerecha30(){
	tBitmapData bmp_data;
	tEntornoEjecucion entornoActual;
	tInstruccion instruccionesActual;
	inicializarEntorno(&entornoActual, &bmp_data);

	instruccionesActual.idInstruccion = 1;
	instruccionesActual.valor = 30;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	int esperado = 30;
	if (entornoActual.tortuga.angulo != esperado) {
		printf("Fallo en testDerecha30: se esperaba %d se recibio %d \n", esperado, entornoActual.tortuga.angulo );
	}
}

void testDerecha30mas70() {
	tBitmapData bmp_data;
	tEntornoEjecucion entornoActual;
	tInstruccion instruccionesActual;
	inicializarEntorno(&entornoActual, &bmp_data);

	instruccionesActual.idInstruccion = 1;
	instruccionesActual.valor = 30;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	instruccionesActual.idInstruccion = 1;
	instruccionesActual.valor = 70;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	int esperado = 100;
	if (entornoActual.tortuga.angulo != esperado) {
		printf("Fallo en testDerecha30mas70: se esperaba %d se recibio %d \n",
									esperado, entornoActual.tortuga.angulo );
	}
}

void testDerecha30mas350es20() {
	tBitmapData bmp_data;
	tEntornoEjecucion entornoActual;
	tInstruccion instruccionesActual;
	inicializarEntorno(&entornoActual, &bmp_data);

	instruccionesActual.idInstruccion = 1;
	instruccionesActual.valor = 30;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	instruccionesActual.idInstruccion = 1;
	instruccionesActual.valor = 350;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	int esperado = 20;
	if (entornoActual.tortuga.angulo != esperado) {
		printf("Fallo en testDerecha30mas350es20: se esperaba %d se recibio %d \n",
									esperado, entornoActual.tortuga.angulo );
	}
}

void testIzq90es270grados() {
	tBitmapData bmp_data;
	tEntornoEjecucion entornoActual;
	tInstruccion instruccionesActual;
	inicializarEntorno(&entornoActual, &bmp_data);

	instruccionesActual.idInstruccion = 2;
	instruccionesActual.valor = 90;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	assertEqualsInt(270, entornoActual.tortuga.angulo, "testDerecha30");
}

void testIzq90mas90es180grados() {
	tBitmapData bmp_data;
	tEntornoEjecucion entornoActual;
	tInstruccion instruccionesActual;
	inicializarEntorno(&entornoActual, &bmp_data);

	instruccionesActual.idInstruccion = 2;
	instruccionesActual.valor = 90;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	instruccionesActual.idInstruccion = 2;
	instruccionesActual.valor = 90;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	assertEqualsInt(180, entornoActual.tortuga.angulo, "testIzq90mas90es180grados");
}

void testIzq90mas300es330grados() {
	tBitmapData bmp_data;
	tEntornoEjecucion entornoActual;
	tInstruccion instruccionesActual;
	inicializarEntorno(&entornoActual, &bmp_data);

	instruccionesActual.idInstruccion = 2;
	instruccionesActual.valor = 90;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	instruccionesActual.idInstruccion = 2;
	instruccionesActual.valor = 300;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	assertEqualsInt(330, entornoActual.tortuga.angulo, "testIzq90mas300es330grados");
}

void testPlumas() {
	tBitmapData bmp_data;
	tEntornoEjecucion entornoActual;
	tInstruccion instruccionesActual;
	inicializarEntorno(&entornoActual, &bmp_data);

	instruccionesActual.idInstruccion = 4;
	instruccionesActual.valor = 0;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	assertTrue(entornoActual.tortuga.conPluma, "testPlumas");

	instruccionesActual.idInstruccion = 3;
	instruccionesActual.valor = 0;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);

	assertFalse(entornoActual.tortuga.conPluma, "testPlumas");
}

void testColorear(){

	tBitmapData bmp_data;
	tEntornoEjecucion entornoActual;
	tInstruccion instruccionesActual;
	inicializarEntorno(&entornoActual, &bmp_data);

	tColor blanco;
	tColor negro;
	tColor rojo;
	tColor verde;
	tColor azul;

	blanco.R = 255;
	blanco.G = 255;
	blanco.B = 255;

	negro.R = 0;
	negro.G = 0;
	negro.B = 0;

	rojo.R = 255;
	rojo.G = 0;
	rojo.B = 0;

	verde.R = 0;
	verde.G = 255;
	verde.B = 0;

	azul.R = 0;
	azul.G = 0;
	azul.B = 255;

	instruccionesActual.idInstruccion = 7;
	instruccionesActual.valor = 0;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);
	assertTrue(sonIguales(&entornoActual.tortuga.color, &blanco),
										"testPlumas-Blanco");

	instruccionesActual.idInstruccion = 7;
	instruccionesActual.valor = 1;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);
	assertTrue(sonIguales(&entornoActual.tortuga.color, &negro),
										"testPlumas-Negro");

	instruccionesActual.idInstruccion = 7;
	instruccionesActual.valor = 2;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);
	assertTrue(sonIguales(&entornoActual.tortuga.color, &rojo),
										"testPlumas-Rojo");

	instruccionesActual.idInstruccion = 7;
	instruccionesActual.valor = 3;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);
	assertTrue(sonIguales(&entornoActual.tortuga.color, &verde),
										"testPlumas-Verde");

	instruccionesActual.idInstruccion = 7;
	instruccionesActual.valor = 4;
	ejecutarInstruccion(&instruccionesActual, &entornoActual);
	assertTrue(sonIguales(&entornoActual.tortuga.color, &azul),
										"testPlumas-Azul");


}






