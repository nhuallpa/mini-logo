/*
 * dominioLogo.c
 *
 *  Created on: 02/04/2011
 *      Author: Administrador
 */
#include "dominioLogo.h"

void(*hashInstrucciones[])(tInstruccion* i,tEntornoEjecucion* e) = {
		iAdelante, iDerecha, iIzquierda, iSinPluma, iConPluma, iRepeate, iEnd, iFColor
};

void(*hashColorear[CANT_COLORES])(tColor* color) = {
	colorearBlanco, colorearNegro, colorearRojo, colorearVerde, colorearAzul
};




char* leerLinea(FILE* fLogoInstrucciones, char* bufferLinea) {
	return fgets(bufferLinea, LONG_BUFFER, fLogoInstrucciones);
}

void ejecutarInstrucciones(FILE* fLogoInstrucciones, tBitmapData* bmp_data) {

	char bufferLinea[LONG_BUFFER];
	tInstruccion instruccionesActual;
	tEntornoEjecucion entornoActual;

	inicializarEntorno(&entornoActual, bmp_data);

	while (leerLinea(fLogoInstrucciones, bufferLinea) != NULL){
		if (leerInstruccion(&instruccionesActual, bufferLinea) == OK) {

			ejecutarInstruccion(&instruccionesActual, &entornoActual);
			// ver si hay bloque a repetir en el entorno y ejecutar
		}
	}

}

void inicializarEntorno(tEntornoEjecucion* entornoActual, tBitmapData* bmp_data) {
	entornoActual->terreno = bmp_data;
	inicializarTortuga(&entornoActual->tortuga);
	// Todo: incializar lista repeat. luego destruir
	//entornoActual
}

void inicializarTortuga(tTortuga* tortuga) {
	tortuga->angulo = 0;
	tortuga->conPluma = TRUE;
	tortuga->x = 0;
	tortuga->y = 0;
	tortuga->color.R = 0;
	tortuga->color.G = 0;
	tortuga->color.B = 0;
}

void ejecutarInstruccion(tInstruccion* instruccion, tEntornoEjecucion* entorno) {
	hashInstrucciones[instruccion->idInstruccion](instruccion, entorno);
}

void iAdelante(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	printf("adelante \n");
}

void iDerecha(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){

	int sumaAngulos = entornoActual->tortuga.angulo + instruccionesActual->valor;
	if (sumaAngulos < 360 ) {
		entornoActual->tortuga.angulo = entornoActual->tortuga.angulo +
													instruccionesActual->valor;
	} else {
		entornoActual->tortuga.angulo = sumaAngulos - 360;
	}
}

void iIzquierda(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){

	tInstruccion instAux;
	instAux.idInstruccion = instruccionesActual->idInstruccion;
	instAux.valor = 360 - instruccionesActual->valor;

	iDerecha(&instAux, entornoActual);

}

void iSinPluma(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	entornoActual->tortuga.conPluma = FALSE;
}

void iConPluma(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	entornoActual->tortuga.conPluma = TRUE;
}

void iRepeate(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	printf("repetir \n");
}

void iEnd(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	printf("End \n");
}

void iFColor(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	hashColorear[instruccionesActual->valor](&entornoActual->tortuga.color);
}

