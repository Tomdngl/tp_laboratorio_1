#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include "menu.h"
#include "utn.h"
#include "id.h"

Employee* employee_new()
{
	Employee* nuevoEmpleado = NULL;

	nuevoEmpleado = (Employee*)calloc(1, sizeof(Employee));

	return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = employee_new();

	int id;
	int horas;
	int sueldo;

	id = atoi(idStr);
	horas = atoi(horasTrabajadasStr);
	sueldo = atoi(sueldoStr);

	if(this==NULL || employee_setConfirm(this, id, nombreStr, horas, sueldo))
	{
		employee_delete(this);
	}

	return this;
}

int employee_setConfirm(Employee* this, int id, char* nombre, int horas, int sueldo)
{
	int rtn = 1;

	if(employee_setId(this, id) == 0 &&
	employee_setNombre(this, nombre) == 0 &&
	employee_setHorasTrabajadas(this, horas) == 0 &&
	employee_setSueldo(this, sueldo) == 0)
	{
		rtn = 0;
	}
	return rtn;
}

int employee_inputData(char* nombre, int* horas, int* sueldo)
{
	int rtn = 0;

	if(utn_getNombre(nombre, 128, "Ingrese el nombre del empleado: ", "Error. ", 2) == 0 &&
	   utn_getNumero(horas, "Ingrese la cantidad de horas: ", "Error. ", 0, 800, 2) == 0 &&
	   utn_getNumero(sueldo, "Ingrese el salario del empleado: ", "Error. ", 0, 500000, 2) == 0)
		{
			rtn = 1;
		}

	return rtn;
}

//Add, edit and remove.

int employee_add(LinkedList* pArrayListEmployee, int* idMax)
{
	int rtn=0;
	int confirmarCambio;
	int auxSueldo;
	int* auxId;
	int auxHoras;
	char auxNombre[128];
	Employee* this;

	if(pArrayListEmployee!=NULL)
	{
		auxId = id_add(idMax);
		if(employee_inputData(auxNombre, &auxHoras, &auxSueldo)==1)
		{
			utn_getNumero(&confirmarCambio, "¿Esta seguro de realizar el alta?\n[1. Si] [2. No]: ", "Opcion invalida. ", 1, 2, 2);
			if(confirmarCambio==1)
			{
				this = employee_new();
				if(this!=NULL)
				{
					employee_setConfirm(this, *auxId, auxNombre, auxHoras, auxSueldo);
					ll_add(pArrayListEmployee,this);
					rtn = 1;
				}
				else
				{
					id_remove(idMax);
					employee_delete(this);
					rtn = 0;
				}
			}
			else
			{
				id_remove(idMax);
				rtn = 0;
			}
		}
	}
	    return rtn;
}

int employee_edit(LinkedList* pArrayListEmployee, int* idMax)
{
	int rtn = 0;
	int i;
	int opc;
	int len;
	int id;
	int confirmarCambio = 0;
	int confirmarSalida = 0;
	int estado = 0;
	int limiteId = id_getMax(idMax);
	Employee* this;
	Employee* aux = employee_new();

	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSalario;

	if(pArrayListEmployee!=NULL)
	{
			len = ll_len(pArrayListEmployee);
			controller_ListEmployee(pArrayListEmployee);
			utn_getNumero(&auxId, "Inserte el id que desea modificar: ", "Error, ese id no existe. ", 0, limiteId, 2);
			for (i = 0; i < len; i++)
			{
				this = (Employee*)ll_get(pArrayListEmployee, i);
				*aux = *this;
				employee_getId(this, &id);
				if(id==auxId)
				{
					do {
						opc=menu_showEditMenu(aux);
						switch (opc){
							case 1:
								utn_getNombre(auxNombre, 128, "\nIngrese el nuevo nombre: ", "Error. ", 2);
								if(employee_setNombre(aux,auxNombre)==0)
								{
									estado = 1;
								}
								break;
							case 2:
								utn_getNumero(&auxHoras, "Ingrese las nuevas cantidad de horas: ", "Error. ", 0, 800, 2);
								if(employee_setHorasTrabajadas(aux, auxHoras)==0)
								{
									estado = 1;
								}
								break;
							case 3:
								utn_getNumero(&auxSalario, "Ingrese el nuevo salario: ", "Error. ", 0, 500000, 2);
								if(employee_setSueldo(aux, auxSalario)==0)
								{
									estado = 1;
								}
								break;
							case 4:
								utn_getNumero(&confirmarCambio, "¿Esta seguro de realizar los cambios?\n[1. Si] [2. No]: ", "Opción invalida. ", 1, 2, 2);
								if(estado==1 && confirmarCambio==1)
								{
									*this = *aux;
									free(aux);
									rtn = 1;
								}
								else if(estado==0 && confirmarCambio==1)
								{
									printf("\nNo ha realizado ningun cambio para confirmar.\n");
								}
								else
								{
									printf("\nSe ha cancelado la modificación\n");
									free(aux);
								}
								break;

							case 10:
								utn_getNumero(&confirmarSalida, "\n¿Desea salir del menu de modificaciones?\n [1. Si] [2. No]: ", "Opción incorrecta. ", 1, 2, 2);
								opc=0;
								if(confirmarSalida==1)
								{
									opc=10;
								}
								break;
							default:
								printf("\nLa opción seleccionada es inválida.\n");
								break;
						}
					}while (opc!=10);
				}
			}
	}
	return rtn;
}

int employee_remove(LinkedList* pArrayListEmployee, int* idMax)
{
	int rtn;
	int len;
	int i;
	int id;
	int auxId;
	int confirmar;
	Employee* this;
	int limiteId = id_getMax(idMax);

		if(pArrayListEmployee!=NULL)
		{
			len = ll_len(pArrayListEmployee);
			controller_ListEmployee(pArrayListEmployee);
			utn_getNumero(&auxId, "Inserte el id que desea remover: ", "Error, ese id no existe. ", 0, limiteId, 2);
			for (i = 0; i < len; i++) {
				this = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(this, &id);
				if(id==auxId)
				{
				printf("\n\nID     NOMBRE   HORAS TRABAJADAS   SUELDO\n");
				employee_list(this);
				utn_getNumero(&confirmar, "\n¿Seguro desea dar de baja al empleado?\n [1. Si] [2. No]: ", "Opcion incorrecta. ", 1, 2, 2);
					if(confirmar == 1)
					{
						ll_remove(pArrayListEmployee, i);
						printf("\nEmpleado dado de baja exitosamente\n");
						employee_delete(this);
						rtn=1;
						break;
					}
					else
					{
						printf("\nBaja cancelada\n");
					}
				}
			}
		}
	return rtn;
}

//Setters

int employee_setId(Employee* this,int id)
{
    int rtn=1;

    if(this != NULL && id > 0)
    {
        this->id=id;
        rtn=0;
    }
    return rtn;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int rtn=1;

    if(this != NULL && nombre!= NULL && strlen(nombre)>1)
    {
        strcpy(this->nombre, nombre);
        rtn=0;
    }

    return rtn;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int rtn=1;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        rtn=0;
    }
    return rtn;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int rtn=1;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo=sueldo;
        rtn=0;
    }
    return rtn;
}

//Getters

int employee_getId(Employee* this,int* id)
{
    int rtn=0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        rtn=1;
    }
    return rtn;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int rtn=0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		rtn=1;
	}
	return rtn;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int rtn=0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		rtn=1;
	}
	return rtn;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int rtn=0;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		rtn=1;
	}
	return rtn;
}

//Miscellaneous

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
        this=NULL;
    }
}

int employee_sort(LinkedList* pArrayListEmployee)
{
	int rtn = 1;
	int ordenamiento;
	int opc;
		if(pArrayListEmployee!=NULL)
		{
			opc=menu_showSortMenu();
			switch (opc) {
				case 1:
					utn_getNumero(&ordenamiento, "[1.] Ascendente o [0.] Descendente: ", "Opcion invalida. ", 0, 1, 2);
					printf("Aguarde un momento.\n");
					ll_sort(pArrayListEmployee, employee_sortById, ordenamiento);
					controller_ListEmployee(pArrayListEmployee);
					rtn = 0;
					break;
				case 2:
					utn_getNumero(&ordenamiento, "[1.] Ascendente o [0.] Descendente: ", "Opcion invalida. ", 0, 1, 2);
					printf("Aguarde un momento.\n");
					ll_sort(pArrayListEmployee, employee_sortByName, ordenamiento);
					controller_ListEmployee(pArrayListEmployee);
					rtn = 0;
					break;
				case 3:
					utn_getNumero(&ordenamiento, "[1.] Ascendente o [0.] Descendente: ", "Opcion invalida. ", 0, 1, 2);
					printf("Aguarde un momento.\n");
					ll_sort(pArrayListEmployee, employee_sortByHours, ordenamiento);
					controller_ListEmployee(pArrayListEmployee);
					rtn = 0;
					break;
				case 4:
					utn_getNumero(&ordenamiento, "[1.] Ascendente o [0.] Descendente: ", "Opcion invalida. ", 0, 1, 2);
					printf("Aguarde un momento.\n");
					ll_sort(pArrayListEmployee, employee_sortBySalary, ordenamiento);
					controller_ListEmployee(pArrayListEmployee);
					rtn = 0;
					break;
				default:
					printf("\nLa opción seleccionada es invalida.\n");
					break;
			}
		}
	return rtn;
}

int employee_sortById(void* firstEmployee, void* secondEmployee)
{
	int rtn = 0;
	int firstId;
	int secondId;

	employee_getId(firstEmployee, &firstId);
	employee_getId(secondEmployee, &secondId);

	if(firstId > secondId)
	{
		rtn = 1;
	}
	else if(firstId < secondId)
	{
		rtn = -1;
	}
	return rtn;
}

int employee_sortByName(void* firstEmployee, void* secondEmployee)
{
	int rtn = 0;
	char firstName[128];
	char secondName[128];

	employee_getNombre(firstEmployee, firstName);
	employee_getNombre(secondEmployee, secondName);

	if(strcmp(firstName, secondName) > 0)
	{
		rtn = 1;
	}
	else if(strcmp(firstName, secondName) < 0)
	{
		rtn = -1;
	}

	return rtn;
}

int employee_sortByHours(void* firstEmployee, void* secondEmployee)
{
	int rtn = 0;
	int firstHours;
	int secondHours;

	employee_getHorasTrabajadas(firstEmployee, &firstHours);
	employee_getHorasTrabajadas(secondEmployee, &secondHours);

	if(firstHours > secondHours)
	{
		rtn = 1;
	}
	else if(firstHours < secondHours)
	{
		rtn = -1;
	}
	return rtn;
}

int employee_sortBySalary(void* firstEmployee, void* secondEmployee)
{

	int rtn = 0;
	int firstSalary;
	int secondSalary;

	employee_getSueldo(firstEmployee, &firstSalary);
	employee_getSueldo(secondEmployee, &secondSalary);

	if(firstSalary > secondSalary)
	{
		rtn = 1;
	}
	else if(firstSalary < secondSalary)
	{
		rtn = -1;
	}
	return rtn;
}

int employee_list(Employee* this)
{
	    int rtn=0;
	    int auxId;
	    char nombre[128];
	    int auxHoras;
	    int auxSueldo;
	    employee_getId(this, &auxId);
	    employee_getNombre(this, nombre);
	    employee_getHorasTrabajadas(this, &auxHoras);
	    employee_getSueldo(this, &auxSueldo);

	    if(this != NULL)
	    {
	        printf("%d %10s %10d %15d\n", auxId, nombre, auxHoras, auxSueldo);
	        rtn=1;
	    }
	    return rtn;
}


