#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE *data;
	int rtn = 0;

	if(path!=NULL&&pArrayListEmployee!=NULL)
	{
		data=fopen(path,"r");
		if(data!=NULL && parser_EmployeeFromText(data, pArrayListEmployee))
		{
			printf("\nDatos cargados exitosamente\n");
			rtn = 1;
		}
	}

	fclose(data);

    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int rtn;
	rtn=employee_add(pArrayListEmployee);
	if(1)
	{
		printf("\nAlta realizada con exito.\n");
		rtn = 1;
	}
	else if(-1)
	{
		printf("\nAlta cancelada.\n");
		rtn = -1;
	}
	else
	{
		printf("\nAlta cancelada.\n");
		rtn=0;
	}

    return rtn;
	}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

	int rtn;
	if(employee_edit(pArrayListEmployee))
	{
	rtn=1;
	}
	else
	{
	rtn=0;
	}

    return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int rtn;
	if(employee_remove(pArrayListEmployee))
	{
	rtn=1;
	}
	else
	{
	rtn=0;
	}

    return rtn;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	int len;

	Employee* auxEmployee;

	if(pArrayListEmployee!=NULL)
	{
		len = ll_len(pArrayListEmployee);

		if(len > 0)
		{
			 printf("\n\nID     NOMBRE   HORAS TRABAJADAS   SUELDO\n\n");

			  for(int i=0; i<len; i++)
			            {
			                auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
			                employee_list(auxEmployee);
			                rtn=1;
			            }
		}
	}
    return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	if(pArrayListEmployee!=NULL)
	{
		if(employee_sort(pArrayListEmployee) == 0)
		{
			printf("Empleados ordenados exitosamente.\n");
		}
	}
	else
	{
		printf("Error\n");
	}

    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

