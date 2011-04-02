
#include "testBmp.h"

void testInicializarBmpData(tBitmapData* bmp_data) {

	tColor blanco;
	blanco.B = 255;
	blanco.G = 255;
	blanco.R = 255;

	int fila = 0;
	for (fila = 0; fila < bmp_data->ancho; fila++ ) {
		int columna = 0;
		for (columna = 0; columna < bmp_data->alto; columna++) {
			tPunto* puntoActual = &bmp_data->puntos[fila][columna];
			if (!sonIguales(&puntoActual->pixel, &blanco)) {
				printf("testInicializarBmpData: NO PASO");
			}
		}
	}
}
