#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int* id_add(int* idMax)
{
	*idMax = *idMax + 1;

	return idMax;
}

int id_getMax(int* idMax)
{
	return *idMax;
}

void id_remove(int* idMax)
{
	*idMax = *idMax - 1;
}

int id_save(int* idMax)
{
	int rtn = 0;
	FILE* lastId;
	lastId = fopen("lastId.csv", "w");
	if(lastId!=NULL)
	{
		fprintf(lastId,"%d", *idMax);
		rtn = 1;
	}
	return rtn;
}
