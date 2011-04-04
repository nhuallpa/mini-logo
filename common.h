/*
 * common.h
 *
 *  Created on: 02/04/2011
 *      Author: Huallpa Nestor
 */



#ifndef __COMMON_H_
#define __COMMON_H_

#define LONG_BUFFER 50

typedef enum {FALSE = 0,  TRUE = 1} tBoolean;

typedef enum {ERROR = 0,  OK = 1} tEstado;

typedef enum {NO_HAY_SIG = 0,  ENCONTRADO = 1} tEstadoRecorrido;

typedef enum {	EXITOSO = 0,
				CANT_PARAM_INV = 1,
				NO_ENCUENTRO_ARCHIVO = 2
} tEstadoEjecucion;




#endif /* COMMON_H_ */


