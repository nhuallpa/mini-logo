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
	entornoActual->tortuga.x = 0;
	entornoActual->tortuga.y = 0;
	entornoActual->tortuga.angulo = 0;
	entornoActual->tortuga.conPluma = FALSE;
	// Todo: incializar lista repeat. luego destruir
	//entornoActual
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
	printf("Derecha \n");

}

void iIzquierda(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	printf("IZQUIEDA \n");
}

void iSinPluma(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	printf("Sin pluma \n");
}

void iConPluma(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	printf("con Pluma \n");
}

void iRepeate(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	printf("repetir \n");
}

void iEnd(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	printf("end \n");
}

void iFColor(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual){
	printf("color \n");
}

