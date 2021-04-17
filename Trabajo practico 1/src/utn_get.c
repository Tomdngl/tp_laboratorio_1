/*
 * utn_get.c
 *
 *  Created on: 16 abr. 2021
 *      Author: Tomas Dangelo
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max, int reintentos){
	int ret;
	float num;

	while(reintentos>0){
		printf(mensaje);
		if(scanf("%f", &num)==1)
		{
			if(num<=max && num>min)
			break;
		}
		fflush(stdin);

		reintentos--;
		printf(mensajeError);
	}

	if(reintentos==0)
	{
		ret=-1;
	}
	else{
		ret=0;
		*pResultado = num;
	}
	return ret;
}

int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos){
	int ret;
	float num;

	while(reintentos>0){
		printf(mensaje);
		if(scanf("%f", &num)==1)
		{
			if(num<=max && num>min)
			break;
		}
		fflush(stdin);

		reintentos--;
		printf(mensajeError);
	}

	if(reintentos==0)
	{
		ret=-1;
	}
	else{
		ret=0;
		*pResultado = num;
	}
	return ret;
}
