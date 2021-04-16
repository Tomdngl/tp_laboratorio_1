/*
 * funciones.c
 *
 *  Created on: 15 abr. 2021
 *      Author: Tomas Dangelo
 */
#include "funciones.h"
int calcularFactorial(int numero)
{
	int resultado;

	if(numero==0){
		resultado = 1;
	}
	else{
		resultado=numero * calcularFactorial(numero-1);
	}

	return resultado;
}
