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
        opc=controller_showMenu();

        switch(opc)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;

            case 3:
            	if(!(ll_isEmpty(listaEmpleados)))
            	{
					if(controller_addEmployee(listaEmpleados))
					{
						printf("\nEmpleado cargado con exito.\n");
					}
					else
					{
						printf("\nError al cargar empleado.\n");
					}
            	}
            	else
            	{
            		printf("\nDebe cargar a los empleados existentes.\n");
            	}
            	break;

            case 4:
            	break;

            case 5:
            	if(!(ll_isEmpty(listaEmpleados)))
				{
            	 controller_removeEmployee(listaEmpleados);
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
            default:

            	break;
        }
    }while(opc != 10);

    return 0;
}

