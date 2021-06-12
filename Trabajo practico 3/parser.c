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
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	//Orden de los char: id , nombre, horasTrabajadas, sueldo
	char id[LNG_C_PARSER];
	char nombre[LNG_C_PARSER];
	char horasTrabajadas[LNG_C_PARSER];
	char sueldo[LNG_C_PARSER];
	int lecturas;
	int inicio = 1;
	Employee* aux = NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do{
			lecturas = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

			if(lecturas==4 && strlen(id)<LNG_C_PARSER && strlen(nombre)<LNG_C_PARSER && strlen(horasTrabajadas)<LNG_C_PARSER && strlen(sueldo)<LNG_C_PARSER&&inicio!=1)
			{
				aux = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				if(aux != NULL)
				{
					ll_add(pArrayListEmployee, aux);
					rtn = 1;
				}
				else
				{
					employee_delete(aux);
				}
			}
			else
			{
				inicio = 0;
			}

		}while(!feof(pFile));
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
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
