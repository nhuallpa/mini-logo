/*
 * dominioLogo.c
 *
 *  Created on: 02/04/2011
 *      Author: Huallpa Nestor
 */
#include "dominioLogo.h"


void(*hashInstrucciones[])(tInstruccion* i, tEntornoEjecucion* e) = {
		iAdelante, iDerecha, iIzquierda, iSinPluma, iConPluma, iRepeate, iEnd, iFColor
};

void(*hashColorear[CANT_COLORES])(tColor* color) = {
	colorearBlanco, colorearNegro, colorearRojo, colorearVerde, colorearAzul
};

tBitmapData* crearTerrenoLogo() {
	tBitmapData* bmp_data = crearBmpData();
	bmp_data->alto = TAMANIO_MAX;
	bmp_data->ancho = TAMANIO_MAX;
	inicializarBmp(bmp_data);
	return bmp_data;
}

char* leerLinea(FILE* fLogoInstrucciones, char* bufferLinea) {
	return fgets(bufferLinea, LONG_BUFFER, fLogoInstrucciones);
}

void ejecutarInstrucciones(FILE* fLogoInstrucciones, tBitmapData* bmp_data) {
	char bufferLinea[LONG_BUFFER];
	tInstruccion instruccionesActual;
	tEntornoEjecucion entornoActual;
	inicializarEntorno(&entornoActual, bmp_data);
	while (leerLinea(fLogoInstrucciones, bufferLinea) != NULL) {
		if (leerInstruccion(&instruccionesActual, bufferLinea) == OK) {
			ejecutarInstruccion(&instruccionesActual, &entornoActual);
			if (entornoActual.armarBloqueRepeat &&
				!esTipoInstruccion(&instruccionesActual, I_REPEAT) &&
				!esTipoInstruccion(&instruccionesActual, I_END)) {
				agregar(entornoActual.bloqueRepeat, &instruccionesActual);
			}
		}
	}
	liberarEntorno(&entornoActual);
}

void inicializarEntorno(tEntornoEjecucion* entornoActual,
						tBitmapData* bmp_data) {
	entornoActual->terreno = bmp_data;
	inicializarTortuga(&entornoActual->tortuga);
	entornoActual->armarBloqueRepeat = FALSE;
	//  No lo creo aca porque se crear cuando encuentra un repeat como instruccion
	//  entornoActual->bloqueRepeat = crearListaInstruciones();
}



void liberarEntorno(tEntornoEjecucion* entornoActual) {
	//  se libera cuando llega la instruccion End despues
	//  de ejecuatar el bloque
	//  libero por las dudas.
	liberarListaInstrucciones(entornoActual->bloqueRepeat);
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

void ejecutarInstruccion(tInstruccion* instruccion,
						tEntornoEjecucion* entorno) {
	hashInstrucciones[instruccion->idInstruccion](instruccion, entorno);
}

void iAdelante(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual) {
	tTortuga* tortuga = &entornoActual->tortuga;
	int distancia = instruccionesActual->valor;
	int xFin = 0;
	int yFin = 0;
	calcular_xy(tortuga->x, tortuga->y, tortuga->angulo, distancia,
														&xFin, &yFin);
	tPosicion posIni;
	posIni.x = tortuga->x / 100;
	posIni.y = tortuga->y / 100;
	tPosicion posFin;
	posFin.x = xFin / 100;
	posFin.y = yFin / 100;
	pintar(&posIni, &posFin, entornoActual);
	tortuga->x = xFin;
	tortuga->y = yFin;
}

void iDerecha(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual) {
	int sumaAngulos =
			entornoActual->tortuga.angulo + instruccionesActual->valor;
	if (sumaAngulos < 360) {
		entornoActual->tortuga.angulo = entornoActual->tortuga.angulo +
											instruccionesActual->valor;
	} else {
		entornoActual->tortuga.angulo = sumaAngulos - 360;
	}
}

void iIzquierda(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual) {
	tInstruccion instAux;
	instAux.idInstruccion = instruccionesActual->idInstruccion;
	instAux.valor = 360 - instruccionesActual->valor;
	iDerecha(&instAux, entornoActual);
}

void iSinPluma(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual) {
	entornoActual->tortuga.conPluma = FALSE;
}

void iConPluma(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual) {
	entornoActual->tortuga.conPluma = TRUE;
}

void iRepeate(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual) {
	entornoActual->bloqueRepeat = crearListaInstruciones();
	entornoActual->armarBloqueRepeat = TRUE;
	entornoActual->nroRepeticiones = instruccionesActual->valor;
}

void iEnd(tInstruccion* instruccionEnd, tEntornoEjecucion* entornoActual) {
	entornoActual->nroRepeticiones = entornoActual->nroRepeticiones - 1;
	entornoActual->armarBloqueRepeat = FALSE;
	while (entornoActual->nroRepeticiones > 0) {
		tInstruccion instruccionEnBloque;
		tEstadoRecorrido estadoRecorrido =
		recuperarInstruccion(entornoActual->bloqueRepeat,
							 &instruccionEnBloque,
							 LIST_PRIMERO);
		while (estadoRecorrido ==  ENCONTRADO) {
			ejecutarInstruccion(&instruccionEnBloque, entornoActual);
			estadoRecorrido = recuperarInstruccion(entornoActual->bloqueRepeat,
												   &instruccionEnBloque,
												   LIST_SIGUIENTE);
		}
		entornoActual->nroRepeticiones = entornoActual->nroRepeticiones - 1;
	}
	liberarListaInstrucciones(entornoActual->bloqueRepeat);
	entornoActual->bloqueRepeat = NULL;
}

void iFColor(tInstruccion* instruccionesActual,
				tEntornoEjecucion* entornoActual) {
	hashColorear[instruccionesActual->valor](&entornoActual->tortuga.color);
}


void calcular_xy(int x0, int y0, int angle, int d, int *x1, int *y1) {
    #define R(x) (((x) >= 0) ? ((int)((x)+0.5)) : ((int)((x)-0.5)))
    *x1 = R(((double)x0) + ((double)d) * cos((((double)angle)*MI_PI)/180));
    *y1 = R(((double)y0) + ((double)d) * sin((((double)angle)*MI_PI)/180));
}

/* Simplification Bresenham's line algorithm*/

void pintar(tPosicion* posIni,
			tPosicion* posFin,
			tEntornoEjecucion* entorno) {
	tBitmapData* bmp_terreno = entorno->terreno;
	tColor* color = &entorno->tortuga.color;
	tBoolean conPluma = entorno->tortuga.conPluma;
	int x0, x1, y0, y1, dx, dy, sx, sy, err, e2;
	x0 = posIni->x;
	y0 = posIni->y;
	x1 = posFin->x;
	y1 = posFin->y;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	err = dx - dy;
	if (x0 < x1) {sx=1;} else {sx=-1;}
	if (y0 < y1) {sy=1;} else {sy=-1;}
	do {
		if (validaPosicion(y0, x0, bmp_terreno) && conPluma) {
			pintarPosicion(y0, x0, bmp_terreno, color);
		}
		if (x0 == x1 && y0 == y1) {
			break;
		}
		e2 = 2*err;
		if (e2 > -dy) {
			err = err - dy;
			x0 = x0 + sx;
		}
		if (e2 < dx) {
			err = err + dx;
			y0 = y0 + sy;
		}
	} while (1);
}
