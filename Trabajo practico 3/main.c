#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);
	int opc;

	LinkedList* listaEmpleados = ll_newLinkedList();

	do{
		opc=menu_showMenu();

		switch(opc)
			{
			case 1:
				//Desarrollar pregunta de si queremos pisar los datos existentes al cargar una lista si ya hay datos cargados.
				if(ll_isEmpty(listaEmpleados))
				{
				controller_loadFromText("data.csv",listaEmpleados);
				}
				else
				{
					printf("\nYa cargo la lista.\n");
				}
			break;

			case 2:
				controller_loadFromBinary("data.bin", listaEmpleados);
			break;

			case 3:
				if(!(ll_isEmpty(listaEmpleados)))
				{
					controller_addEmployee(listaEmpleados);
				}
				else
				{
					printf("\nDebe cargar a los empleados existentes.\n");
				}
			break;

			case 4:
				if(!(ll_isEmpty(listaEmpleados)))
				{
				controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("\nDebe cargar a los empleados existentes.\n");
				}
			break;

			case 5:
				if(!(ll_isEmpty(listaEmpleados)))
				{
				 controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("\nNo hay empleados cargados en el sistema.\n");
				}
			break;
			case 6:
				if(!(ll_isEmpty(listaEmpleados)))
				{
				controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("\nDebe cargar a los empleados antes de listarlos.\n\n");
				}
			break;
			case 7:
				if(!(ll_isEmpty(listaEmpleados)))
				{
				controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("\nDebe cargar a los empleados antes de ordenarlos.\n\n");
				}
				break;
			case 8:
				if(!(ll_isEmpty(listaEmpleados)))
				{
				controller_saveAsText("data.csv", listaEmpleados);
				}
				else
				{
					printf("\nNo hay empleados para guardar.\n\n");
				}
				break;
			case 9:
				if(!(ll_isEmpty(listaEmpleados)))
				{
				controller_saveAsBinary("data.bin", listaEmpleados);
				}
				else
				{
					printf("\nNo hay empleados para guardar.\n\n");
				}
				break;
			}
		}while(opc != 10);
	return 0;
}

