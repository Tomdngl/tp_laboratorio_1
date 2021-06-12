#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
		opc=employee_showMenu();

		switch(opc)
			{
			case 1:
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
				//A desarrollar controller from Binary. Solo se puede ingresar una vez que se guardo el csv text en binario. (Si no existe binario no carga nada)
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
			//EN DESARROLLO
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
			}
		}while(opc != 10);
	return 0;
}

