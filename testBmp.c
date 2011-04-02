
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

void testMainImage() {
	printf("tam uint %d", sizeof(uint));
	printf("tam ushort %d", sizeof(ushort));

	char* ruta = "salida.bmp";
	tColor color;
	color.B = 255;
	color.R = 0;
	color.G = 0;
	tBitmapData* bmp = (tBitmapData*)malloc(sizeof(tBitmapData));
	bmp->alto = 200;
	bmp->ancho = 200;
	inicializar(bmp);
	// TODO: testInicializarBmpData
	testInicializarBmpData(bmp);

	pintarPunto(&bmp->puntos[0][0], &color);
	pintarPunto(&bmp->puntos[0][1], &color);
	pintarPunto(&bmp->puntos[0][2], &color);
	pintarPunto(&bmp->puntos[1][0], &color);
	pintarPunto(&bmp->puntos[1][1], &color);
	pintarPunto(&bmp->puntos[1][2], &color);

	int fila = 0;
	for (fila = 0; fila < bmp->alto; fila++ ) {
		pintarPunto(&bmp->puntos[fila][75], &color);
	}

	publicar(bmp, ruta);
	destruir(bmp);
}
