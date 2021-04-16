/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	int factorial;

	factorial=calcularFactorial(5);
	printf("El factorial de 5 es: %d",factorial);
	return 0;
}
