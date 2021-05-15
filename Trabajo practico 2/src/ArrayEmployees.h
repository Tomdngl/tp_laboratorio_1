/*
 * Employees.h
 *
 *  Created on: 14 may. 2021
 *      Author: Tomas Dangelo
 */

#ifndef EmployeeS_H_
#define EmployeeS_H_

#define MAX_LENGTH 51
#define FALSE 0
#define TRUE 1

typedef struct
{
	int id;
	char name[MAX_LENGTH];
	char last_name[MAX_LENGTH];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int menu(void);
int initEmployees(Employee* array, int limite);
int addEmployees(Employee* array, int limite, int* id);
int printEmployee(Employee* pElemento);
int printEmployees(Employee* array, int limite);
int findEmployeeById(Employee* list, int len,int id);
int modifyEmployee(Employee* list, int len, int index, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int sort_crit);
int salarySum(Employee* list, int len, float* totalSalary);
int salaryProm(Employee* list,int len,float* promSalary, float* totalSalary);
int aboveSalary(Employee* list, int len, int* aboveProm, float* promSalary);
int checkAdd(Employee* list, int len);
#endif /* EmployeeS_H_ */
