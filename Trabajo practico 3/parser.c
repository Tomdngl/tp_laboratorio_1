#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

#define LNG_C_PARSER 128

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* data , LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	//Orden de los char: id , nombre, horasTrabajadas, sueldo
	char id[LNG_C_PARSER];
	char nombre[LNG_C_PARSER];
	char horasTrabajadas[LNG_C_PARSER];
	char sueldo[LNG_C_PARSER];
	int lecturas;
	int inicio = 1;
	Employee* this = NULL;

	if(data!=NULL && pArrayListEmployee!=NULL)
	{
		do{
			lecturas = fscanf(data, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

			if(lecturas==4 && strlen(id)<LNG_C_PARSER && strlen(nombre)<LNG_C_PARSER && strlen(horasTrabajadas)<LNG_C_PARSER && strlen(sueldo)<LNG_C_PARSER&&inicio!=1)
			{
				this = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				if(this != NULL)
				{
					ll_add(pArrayListEmployee, this);
					rtn = 1;
				}
				else
				{
					employee_delete(this);
				}
			}
			else
			{
				inicio = 0;
			}

		}while(!feof(data));
	}

    return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* data , LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	Employee* this = NULL;

	if(data != NULL && pArrayListEmployee != NULL)
	{
		do {
			this = employee_new();

			if(fread(this ,sizeof(Employee), 1, data)==1)
			{
				ll_add(pArrayListEmployee, this);
				rtn = 1;
			}
		} while (!feof(data));
	}
    return rtn;
}

int parser_Id(FILE* pFile, int* idMax)
{
	int rtn = 0;
	char idStr[5];

	if(fscanf(pFile, "%[^,]",idStr))
	{
		rtn = 1;
		*idMax = atoi(idStr);
	}

	return rtn;
}
