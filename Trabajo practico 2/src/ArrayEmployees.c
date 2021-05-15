#include "ArrayEmployees.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

/**
 * @fn int menu()
 * @brief Menu print and read the option selected
 *
 * @return Return an int with the option selected
 */
int menu()
{
	int opc;
	printf("\n\t>ABM EMPLEADOS<\t\n");
	printf("1. Alta empleados\n");
	printf("2. Modificacion empleados\n");
	printf("3. Baja empleados\n");
	printf("4. Informe empleados\n");
	printf("0. Salir\n");
	utn_getNumero(&opc, "Seleccione una opcion: ", "Error, opcion invalida\n", 0, 4, 5);
	return opc;
}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	int rtn = -1;
	int i;
		if(list != NULL && len > 0)
		{
			rtn = 0;
			for(i=0;i<len;i++)
			{
				list[i].isEmpty = TRUE;
			}
		}
	return rtn;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployees(Employee* list, int len, int* id)
{
	int rtn = -1;
	int i;
	Employee employeeBuffer;
	i = *id;
	if(list != NULL && len > 0 && id!=NULL && *id<len){
		if(utn_getNombre(employeeBuffer.name, MAX_LENGTH, "Ingrese el nombre del empleado: ", "Error\n", 2)==0 &&
		utn_getNombre(employeeBuffer.last_name, MAX_LENGTH, "Ingrese el apellido del empleado: ", "Error\n", 2)==0 &&
		utn_getNumeroFlotante(&employeeBuffer.salary, "Ingrese el salario de su empleado: ", "Error\n", 20000,  10000000, 2)==0 &&
		utn_getNumero(&employeeBuffer.sector, "[1. RRHH][2. VENTAS][3. IT]\nIngrese el sector del empleado: ", "Error\n", 0, 3, 2)==0)
		{
			employeeBuffer.isEmpty = FALSE;
			employeeBuffer.id = *id;
			list[i]=employeeBuffer;
			(*id)++;
			rtn = 0;
		}
	}
	return rtn;
}

/**
 * @fn int printEmployee(Employee*)
 * @brief print the content of one employee
 *
 * @param Element index given by printEmployees();
 * @return
 */
int printEmployee(Employee* Element)
{
	int rtn=-1;
	if(Element != NULL && Element->isEmpty == 0)
	{
		rtn=0;
		printf("\nID: %d - %s - %s - %.2f - %d",Element->id,Element->name,Element->last_name,Element->salary,Element->sector);
	}
	return rtn;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int printEmployees(Employee* list, int len)
{
	int rtn = -1;
	int i;
	if(list != NULL && len > 0)
	{
		rtn = 0;
		for(i=0;i<len;i++)
		{
				printEmployee(&list[i]);
		}
	}
	return rtn;
}

/** \brief find an Employee by Id and returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
	int rtn = -1;
	int i;
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				rtn = i;
				break;
			}
		}
	return rtn;
}

/**
 * @fn int modifyEmployee(Employee*, int, int, int)
 * @brief modify an Employee by ID and verify the user is sure
 *
 * @param list Employee*
 * @param lenght int
 * @param index int
 * @param id int
 * @return Return (-1) if error - (0) if ok - (1) if the user regrets
 */
int modifyEmployee(Employee* list, int len, int index, int id)
{
	int rtn = -1;
	int verify;
	Employee employeeBuffer;
	if(list != NULL && list[index].isEmpty==FALSE && index >= 0){
	if(utn_getNombre(employeeBuffer.name, MAX_LENGTH, "Ingrese el nombre del empleado: ", "Error\n", 2)==0 &&
			utn_getNombre(employeeBuffer.last_name, MAX_LENGTH, "Ingrese el apellido del empleado: ", "Error\n", 2)==0 &&
			utn_getNumeroFlotante(&employeeBuffer.salary, "Ingrese el salario de su empleado: ", "Error\n", 20000,  10000000, 2)==0 &&
			utn_getNumero(&employeeBuffer.sector, "[1. RRHH][2. VENTAS][3. IT]\nIngrese el sector del empleado: ", "Error\n", 0, 3, 2)==0)
			{
				employeeBuffer.isEmpty = FALSE;
				employeeBuffer.id = list[index].id;
				utn_getNumero(&verify, "\n [1. SI | 2. NO]\n¿Desea confirmar los cambios? : ", "Error\n", 1 , 2, 2);
				if(verify==1){
				list[index]=employeeBuffer;
				rtn = 0;
				}
				else{
					puts("\nHa cancelado la modificacion.");
					rtn = 1;
				}
			}
		}

	return rtn;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok - (1) if the user regrets
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
	int rtn = -1;
	int verify;
	if(list!=NULL && (findEmployeeById(list, len, id))!=-1){
		utn_getNumero(&verify, "\n [1. SI | 2. NO]\n¿Desea confirmar la baja? : ", "Error\n", 1 , 2, 2);
		if(verify==1){
		list[id].isEmpty=TRUE;
		rtn = 0;
		}
		else{
			puts("\nHa cancelado la baja");
			rtn = 1;
		}
	}
 return rtn;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
	int rtn = -1;
	int flagSwap;
	int i;
	Employee buffer;
	if(list != NULL && len > 0 && order==1)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(list[i].last_name,list[i+1].last_name,MAX_LENGTH) > 0)
				{
					flagSwap = 1;
					buffer = list[i];
					list[i] = list[i+1];
					list[i+1]=buffer;
				}
			}
			len--;
		}while(flagSwap);
	}
	if(list != NULL && len > 0 && order==2){
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
				{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				if(list[i].sector>list[i+1].sector)
				{
					flagSwap = 1;
					buffer = list[i];
					list[i] = list[i+1];
					list[i+1]=buffer;
				}
			}
			len--;
		}while(flagSwap);
	}
	return rtn;
}

/**
 * @fn int salarySum(Employee*, int, float*)
 * @brief Sums all the salaries of the active employees on the list
 *
 * @param list Employee*
 * @param len int
 * @param totalSalary
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int salarySum(Employee* list, int len, float* totalSalary)
{
	int rtn = -1;
	int i;
	*totalSalary=0;

	if(list != NULL && len > 0){
		for(i=0; i<len; i++){
		if(list[i].isEmpty==FALSE){
			*totalSalary = *totalSalary + list[i].salary;
			rtn = 0;
			}
		}
	}

	return rtn;
}

/**
 * @fn int salaryProm(Employee*, int, float*, float*)
 * @brief Average the salaries of the active employees on the list
 *
 * @param list Employee*
 * @param len int
 * @param promSalary int*
 * @param totalSalary float*
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int salaryProm(Employee* list,int len,float* promSalary, float* totalSalary)
{
	int rtn = -1;
	int i;
	int j = 0;
	*promSalary=0;

	if(list != NULL && len > 0){
		for(i=0; i<len; i++){
			if(list[i].isEmpty==FALSE)
			j++;
		}
		*promSalary=(*totalSalary/j);
		rtn = 0;
	}
	return rtn;
}

/**
 * @fn int aboveSalary(Employee*, int, int*, float*)
 * @brief Counts the number of employees that are above the promSalary
 *
 * @param list Employee*
 * @param len int
 * @param aboveProm int*
 * @param promSalary float*
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int aboveSalary(Employee* list, int len, int* aboveProm, float* promSalary)
{
	int rtn = -1;
	int i;
	*aboveProm=0;
	if(list != NULL && len > 0){
		for(i=0; i<len; i++){
			if(list[i].salary>*promSalary){
				(*aboveProm)++;
				rtn = 0;
			}
		}
	}
	return rtn;
}

/**
 * @fn int checkAdd(Employee*, int)
 * @brief Verifies if an employee has been added to the list
 *
 * @param list Employee*
 * @param len int
 * @return (0) if didn't find an employee - (1) If is at least one employee on the list
 */
int checkAdd(Employee* list, int len)
{
	int rtn = 0;
	int i;
	if(list != NULL && len > 0){
		for(i=0; i<len; i++){
			if(list[i].isEmpty==FALSE){
				rtn=1;
				break;
			}
		}
	}
	return rtn;
}
