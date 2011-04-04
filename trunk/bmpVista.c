/*
 * bmpVista.c
 *
 *  Created on: 31/03/2011
 *      Author: Nestor
 */
#include "bmpVista.h"

void publicar(tBitmapData* bmp_data, char* ruta) {
	tBmp bmp;
	bmp.bmp_data = bmp_data;
	inicializarFileHeader(&bmp.bmp_file_header);
	inicializarInfoHeader(&bmp.bmp_info_hader, bmp.bmp_data);
	FILE* output = abrirSalida(ruta);
	// Todo: se puede pasar a una libreria bmpFile.h
	salvarFileHeader(&bmp.bmp_file_header, output);
	salvarInfoHeader(&bmp.bmp_info_hader, output);
	salvarDatosVisuales(bmp.bmp_data, output);
	cerrarSalida(output);
}


void inicializarFileHeader(tBitmapFileHeader* bmp_file_header) {
	if (bmp_file_header) {
		memcpy(&(bmp_file_header->bfType), "BM", 2);
		bmp_file_header->bfSize = 0;
		bmp_file_header->bfReserved1 = bmp_file_header->bfReserved2 = 0;
		bmp_file_header->bfOffBits = 54;
	}
}

void inicializarInfoHeader(tBitMapInfoHeader* bmp_info_hader,
							tBitmapData* bmp_data) {
	int cantBytesPorPixel = 3;
	if (bmp_data && bmp_info_hader) {
		bmp_info_hader->biSize = 40;
		bmp_info_hader->biHeight =  bmp_data->alto;
		bmp_info_hader->biWidth = bmp_data->ancho;
		bmp_info_hader->biPlanes = 1;
		bmp_info_hader->biBitCount = 24;
		bmp_info_hader->biCompression = 0;
		bmp_info_hader->biSizeImage = 	bmp_data->alto *
										bmp_data->ancho *
										cantBytesPorPixel;
		bmp_info_hader->biXPelsPerMeter = bmp_info_hader->biYPelsPerMeter = 0;
		bmp_info_hader->biClrUsed = 0;
		bmp_info_hader->biClrImportant = 0;
	}
}

void salvarFileHeader(tBitmapFileHeader* bmp_file_header, FILE* output) {
	fwrite(&bmp_file_header->bfType, sizeof(ushort),1,output);
	fwrite(&bmp_file_header->bfSize, sizeof(uint),1,output);
	fwrite(&bmp_file_header->bfReserved1, sizeof(ushort),1,output);
	fwrite(&bmp_file_header->bfReserved2, sizeof(ushort),1,output);
	fwrite(&bmp_file_header->bfOffBits, sizeof(uint),1,output);
}

void salvarInfoHeader(tBitMapInfoHeader* bmp_info_header, FILE* output) {
	fwrite(&bmp_info_header->biSize, sizeof(uint), 1, output);
	fwrite(&bmp_info_header->biWidth, sizeof(uint), 1, output);
	fwrite(&bmp_info_header->biHeight, sizeof(uint), 1, output);
	fwrite(&bmp_info_header->biPlanes, sizeof(ushort), 1, output);
	fwrite(&bmp_info_header->biBitCount, sizeof(ushort), 1, output);
	fwrite(&bmp_info_header->biCompression, sizeof(uint), 1, output);
	fwrite(&bmp_info_header->biSizeImage, sizeof(uint), 1, output);
	fwrite(&bmp_info_header->biXPelsPerMeter, sizeof(uint), 1, output);
	fwrite(&bmp_info_header->biYPelsPerMeter, sizeof(uint), 1, output);
	fwrite(&bmp_info_header->biClrUsed, sizeof(uint), 1, output);
	fwrite(&bmp_info_header->biClrImportant, sizeof(uint), 1, output);
}

void salvarDatosVisuales(tBitmapData* bmp_data, FILE* output) {
	int padding = bmp_data->ancho % 4;
	int fila = 0;
	for (fila = (bmp_data->alto - 1); fila >= 0 ; fila--) {
		int columna = 0;
		for (columna = 0; columna < bmp_data->ancho; columna++) {
			tColor* pixel = &bmp_data->puntos[fila][columna].pixel;
			fwrite(&pixel->B, sizeof(uchar), 1, output);
			fwrite(&pixel->G, sizeof(uchar), 1, output);
			fwrite(&pixel->R, sizeof(uchar), 1, output);
		}
		if (!padding) {
			int i = 0;
			for (i = 0; i < padding; i++) {
				putc(0, output);
			}
		}
	}
}

FILE* abrirSalida(char* ruta) {
	return fopen(ruta, "w+");
}

void cerrarSalida(FILE* output) {
	fclose(output);
}

