/*
 ============================================================================
 Name        : main.c
 Author      : Huallpa Nestor
 Version     : 1.0
 Description : punto de entrada
 ============================================================================
*/
#include<stdio.h>
#include "color.h"

#define EXITOSO			0
#define NOEXISTE_IMAGEN 2
#define CANT_PARAM_INV  1
#include "bmp.h"
#include "bmpVista.h"

#include "testBmp.h"


int main(int argc, char* argv[]) {

	testMainImage();
	return 0;
}
