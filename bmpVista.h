/*
 * bmpVista.h
 *
 *  Created on: 31/03/2011
 *      Author: Administrador
 */
#ifndef BMPVISTA_H_
#define BMPVISTA_H_
#include "bmp.h"

#define DEFAULT_WIDTH 200
#define DEAULT_HEIGHT 200

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned short ushort;

/*
The BITMAPFILEHEADER:
start size name stdvalue purpose
1 2 bfType 19778 must always be set to 'BM' to declare that this is a .bmp-file.
3 4 bfSize ?? specifies the size of the file in bytes.
7 2 bfReserved1 0 must always be set to zero.
9 2 bfReserved2 0 must always be set to zero.
11 4 bfOffBits 1078 specifies the offset from the beginning of the file to the bitmap data.
*/
typedef struct {
    ushort  bfType;
    uint    bfSize;
    ushort  bfReserved1;
    ushort  bfReserved2;
    uint    bfOffBits;
} tBitmapFileHeader;

/*
The BITMAPINFOHEADER:
start size name stdvalue purpose
15 4 biSize 40 specifies the size of the BITMAPINFOHEADER structure, in bytes.
19 4 biWidth 100 specifies the width of the image, in pixels.
23 4 biHeight 100 specifies the height of the image, in pixels.
27 2 biPlanes 1 specifies the number of planes of the target device, must be set to zero.
29 2 biBitCount 8 specifies the number of bits per pixel.
31 4 biCompression 0 Specifies the type of compression, usually set to zero (no compression).
35 4 biSizeImage 0 specifies the size of the image data, in bytes. If there is no compression, it is valid to set this member to zero.
39 4 biXPelsPerMeter 0 specifies the the horizontal pixels per meter on the designated targer device, usually set to zero.
43 4 biYPelsPerMeter 0 specifies the the vertical pixels per meter on the designated targer device, usually set to zero.
47 4 biClrUsed 0 specifies the number of colors used in the bitmap, if set to zero the number of colors is calculated using the biBitCount member.
51 4 biClrImportant 0 specifies the number of color that are 'important' for the bitmap, if set to zero, all colors are important.
*/
typedef struct
{
    uint   biSize;
    uint   biWidth;
    uint   biHeight;
    ushort biPlanes;
    ushort biBitCount;
    uint   biCompression;
    uint   biSizeImage;
    uint   biXPelsPerMeter;
    uint   biYPelsPerMeter;
    uint   biClrUsed;
    uint   biClrImportant;
} tBitMapInfoHeader;




typedef struct {
	tBitmapFileHeader bmp_file_header;
	tBitMapInfoHeader bmp_info_hader;
	tBitmapData* bmp_data;
} tBmp;

void publicar(tBitmapData* bmp, char* ruta);


#endif /* BMPVISTA_H_ */
