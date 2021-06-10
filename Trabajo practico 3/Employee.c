#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "utn.h"

Employee* employee_new()
{
	Employee* nuevoEmpleado = NULL;

	//Intentar usar calloc si funciona con malloc.
	nuevoEmpleado = (Employee*)malloc(sizeof(Employee));

	if(nuevoEmpleado!=NULL)
	{
		nuevoEmpleado->id=0;
		nuevoEmpleado->horasTrabajadas=0;
		nuevoEmpleado->sueldo=0;
		strcpy(nuevoEmpleado->nombre, "");
	}

	return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = employee_new();

	if(this==NULL ||
			employee_setId(this, atoi(idStr)) ||
			employee_setNombre(this, nombreStr) ||
			employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) ||
			employee_setSueldo(this, atoi(sueldoStr))
		)
	{
		employee_delete(this);
	}

	return this;
}


int employee_add(LinkedList* pArrayListEmployee)
{
	int rtn=0;
	int auxSueldo;
	int auxId;
	int auxHoras;
	char auxNombre[128];
	Employee* this;

	if(pArrayListEmployee!=NULL)
	{
		auxId=findIdMax(pArrayListEmployee);
		utn_getNombre(auxNombre, 128, "Ingrese el nombre del empleado: ", "Error. ", 2);
		utn_getNumero(&auxHoras, "Ingrese las horas trabajadas del empleado: ", "Error. ", 0, 800, 2);
		utn_getNumero(&auxSueldo, "Ingrese el sueldo del empleado: ", "Error. ", 0, 500000, 2);

		this = employee_new();

		if(this!=NULL)
		{
			 if( employee_setId(this,auxId) == 0 &&
				 employee_setNombre(this,auxNombre) == 0 &&
				 employee_setHorasTrabajadas(this,auxHoras) == 0 &&
				 employee_setSueldo(this,auxSueldo) == 0 )
			{
				ll_add(pArrayListEmployee,this);
				rtn = 1;
			}
			else
			{
				rtn = 0;
			}
		}
	}
	    return rtn;
}

int employee_remove(LinkedList* pArrayListEmployee)
{
	int rtn;
	int len;
	int i;
	int auxId;
	int confirmar;
	Employee* this;
	int limiteId=findIdMax(pArrayListEmployee);

		if(pArrayListEmployee!=NULL)
		{
			len = ll_len(pArrayListEmployee);
			utn_getNumero(&auxId, "Inserte el id que desea remover: ", "Error, ese id no existe. ", 0, limiteId, 2);
			for (i = 0; i < len; i++) {
				this = (Employee*)ll_get(pArrayListEmployee, i);
				if(this->id==auxId)
				{
				utn_getNumero(&confirmar, "\n¿Seguro desea dar de baja al empleado?\n [1. Si] [2. No] ", "Opcion incorrecta. ", 1, 2, 2);
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

int findIdMax(LinkedList* pArrayListEmployee)
{
	int idMax = 0;
	Employee* aux;
	int i;
	int len = ll_len(pArrayListEmployee);

      for(i=0; i<len; i++)
      {
          aux = ll_get(pArrayListEmployee,i);
          if(idMax<aux->id || idMax == 0)
          {
              idMax = aux->id;
          }
      }

      return idMax + 1;
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

//Miscellaneous

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
        this=NULL;
    }
}

int employee_list(Employee* this)
{
	    int rtn=0;

	    if(this != NULL)
	    {
	        printf("%d %10s %10d %15d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
	        rtn=1;
	    }

	    return rtn;
}
