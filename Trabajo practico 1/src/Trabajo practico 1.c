/*
 ============================================================================
 Nombre        : Trabajo.c
 Autor         : Tomás D'Angelo
 Trabajo práctico Nº1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn_get.h"

int main(void) {
	setbuf(stdout, NULL);
	float operandoA;
	float operandoB;
	int resultadoFactorialA;
	int resultadoFactorialB;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	int opcion;
	int operandoAEntero;
	int operandoBEntero;
	operandoAEntero=0;
	operandoBEntero=0;
	opcion=0;

	do{
		printf("\nSeleccione una opción, para ello digite el número correspondiente y presione ENTER.\n");
		printf("1. Ingresar 1er operando A = %.2f\n", operandoA);
		printf("2. Ingresar 2do operando B = %.2f\n", operandoB);
		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		printf("Opción seleccionada:");

		fflush(stdin);
		scanf("%d", &opcion);

			switch(opcion){
				case 1:
					utn_getNumeroFloat(&operandoA,"Ingrese el numero:","Error ",-3.4028235E+38 , 3.4028235E+38, 3);
					operandoAEntero=(int) operandoA;
				break;
				case 2:
					utn_getNumeroFloat(&operandoB,"Ingrese el numero:","Error ",-3.4028235E+38 ,3.4028235E+38, 3);
					operandoBEntero=(int) operandoB;
				break;
				case 3:
					//Evaluo que el operando A sea distinto de 0
					if(operandoAEntero!=0){
					//Evaluar si el factorial A se puede calcular
						if(operandoA>0){
							if(operandoA - operandoAEntero){
								printf("El factorial de su operando A no se puede calcular ya que debe ser un número sin decimales.");
							}
							else{
								resultadoFactorialA=calcularFactorial(operandoA);
							}
						}
							else{
							printf("El factorial de su operando A no se puede calcular ya que debe ser un número positivo.");
							}
					//Evaluar si el factorial B se puede calcular
						if(operandoB>0){
							if(operandoB - operandoBEntero){
								printf("El factorial de su operando B no se puede calcular ya que debe ser un número sin decimales.");
									}
							else{
								resultadoFactorialB=calcularFactorial(operandoB);
							}
						}
						else{
							printf("El factorial de su operando B no se puede calcular ya que debe ser un número positivo.");
						}
						//Calculo la suma
							resultadoSuma=calcularSuma(operandoA, operandoB);
						//Calculo la resta
							resultadoResta=calcularResta(operandoA, operandoB);
						//Calculo la multiplicación
							resultadoMultiplicacion=calcularMultiplicacion(operandoA, operandoB);
						//Calculo la division, primero verifico que el divisor sea distinto de 0
							if(operandoBEntero==0){
								printf("No puede realizar una division donde el divisor sea 0.");
								resultadoDivision=0;
							}
							else{
								resultadoDivision=calcularDivision(operandoA, operandoB);
							}
					}
					//Si hay operandos vacíos
					else{
					printf("\n Para realizar los calculos debe ingresar por lo menos un dato en el operando A.");
					}
				break;
				case 4:
					if(operandoA!=0){
					printf("\n El resultado de A+B es: %.2f", resultadoSuma);
					printf("\n El resultado de A-B es: %.2f", resultadoResta);
					printf("\n El resultado de A*B es: %.2f", resultadoMultiplicacion);
					printf("\n El resultado de A/B es: %.2f", resultadoDivision);
					printf("\n El factorial de A es: %d y el factorial de B es: %d" , resultadoFactorialA, resultadoFactorialB);
					}
					else{
						printf("\n Debe ingresar por lo menos un dato en el operando A y calcular para mostrar los resultados");
					}
				break;
				case 5:
					printf("\n Gracias por usar este programa");
				break;
				default:
					printf("\nLa opcion que seleccionó es incorrecta.\n");
				break;
		}
	}while(opcion!=5);

	return 0;
}
