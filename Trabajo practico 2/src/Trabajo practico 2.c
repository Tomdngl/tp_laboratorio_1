#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define ELEMENTS 1000
int main(void){
	setbuf(stdout, NULL);

	Employee list[ELEMENTS];
	int employee_id = 0;
	int id_aux;
	int index_aux;
	int sort_crit;
	int opc;
	float totalSalary;
	float promSalary;
	int aboveProm;
	char NoEmployeeChargedMsj[]="Debe realizar la carga de un empleado primero.";

	//Inicializo el array de empleados.
	if(initEmployees(list, ELEMENTS)==0){
		puts("Array inicializado correctamente\n");
	}

	do{
	//Imprimo el menu y leo respuesta
	opc=menu();
	//Switch del menu
	switch(opc){
		case 0:
		//SALIDA
			opc = 0;
		break;
		case 1:
		//ALTAS
			puts("\n\t ALTA \t");
			if(addEmployees(list, ELEMENTS, &employee_id)==0){
			puts("Se ha realizado el alta del empleado de manera exitosa");
			}
			else{
				printf("\nNo hay mas lugar.");
			}
		break;
		case 2:
		//MODIFICACIONES
			if(checkAdd(list, ELEMENTS)){
			puts("\n\t MODIFICACIONES \t");
			printEmployees(list, ELEMENTS);
			if(utn_getNumero(&id_aux, "\nIngrese el id del empleado que desea modificar: ", "\nError", 0, 1000, 2)==0){
				index_aux = findEmployeeById(list, ELEMENTS, id_aux);
				if(index_aux >= 0 &&
						modifyEmployee(list, ELEMENTS, index_aux, id_aux)==0){
					puts("Se ha realizado la modificacion con exito");
					}
				}
			}
			else{
				puts(NoEmployeeChargedMsj);
			}
		break;
		case 3:
		//BAJAS
			if(checkAdd(list, ELEMENTS)){
			puts("\n\t BAJAS \t");
			printEmployees(list, ELEMENTS);
			if(utn_getNumero(&id_aux, "\nIngrese el id del empleado que desea dar de baja: ", "\nError", 0, 1000, 2)==0){
				if(removeEmployee(list, ELEMENTS, id_aux)==0){
					puts("Se ha realizado la baja con exito");
				}
			}
			else{
				puts("El ID no existe");
			}
		}
			else{
				puts(NoEmployeeChargedMsj);
			}
		break;
		case 4:
		//INFORME
			if(checkAdd(list, ELEMENTS)){
			puts("\n\t INFORMES \t");
			if(utn_getNumero(&sort_crit, "\n[1. Por nombre | 2. Por sector]\nQue informe que desea visualizar: ", "\nError",1, 2, 2)==0){
				if(sort_crit==1){
					sortEmployees(list, ELEMENTS, sort_crit);
					}
				else if(sort_crit==2){
					sortEmployees(list, ELEMENTS, sort_crit);
				}
				printEmployees(list, ELEMENTS);
				salarySum(list, ELEMENTS, &totalSalary);
				salaryProm(list, ELEMENTS, &promSalary, &totalSalary);
				aboveSalary(list, ELEMENTS, &aboveProm ,&promSalary);
				printf("\nEl salario total de los empleados es %.2f", totalSalary);
				printf("\nEl promedio de los salarios es %.2f y lo sobrepasan %d empleados.", promSalary, aboveProm);
				}
			}
			else{
				puts(NoEmployeeChargedMsj);
			}
			break;
		}
	}while(opc!= 0);
	puts("\n\t Salir del programa. \t");
	return 0;
}

