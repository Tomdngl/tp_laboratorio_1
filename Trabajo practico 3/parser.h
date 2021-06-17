#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_Id(FILE* pFile, int *idMax);

#endif
