/*
 * funciones.c
 *
 *  Created on: 15 abr. 2021
 *      Author: Tomas Dangelo
 */
#include "funciones.h"
int calcularFactorial(float numero)
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

float calcularSuma(float operandoA, float operandoB)
{
	float resultado;

		resultado=operandoA+operandoB;

	return resultado;
}

float calcularResta(float operandoA, float operandoB)
{
	float resultado;

		resultado=operandoA-operandoB;

	return resultado;
}

float calcularMultiplicacion(float operandoA, float operandoB)
{
	float resultado;

		resultado=operandoA*operandoB;

	return resultado;
}

float calcularDivision(float operandoA, float operandoB)
{
	float resultado;

		resultado=operandoA/operandoB;

	return resultado;
}
