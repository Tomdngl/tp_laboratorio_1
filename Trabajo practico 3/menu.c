#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"
#include "employee.h"

int menu_showMenu()
{
	int opc;
    printf("\n                    ###   Menu   ###\n");
    printf("\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");
	utn_getNumero(&opc, "Seleccione una opcion: ", "Error, ", 0, 10, 3);
	return opc;
}

int menu_showEditMenu(Employee* this)
{
	int opc;
    printf("\n            ###   Menu modificaciones   ###\n");
    printf("\n\nID     NOMBRE   HORAS TRABAJADAS   SUELDO\n");
    employee_list(this);
    printf("\n\n");
    printf("1. Modificar nombre del empleado.\n");
    printf("2. Modificar horas trabajadas del empleado.\n");
    printf("3. Modificar sueldo del empleado.\n");
    printf("4. Confirmar modificación.\n");

    printf("10. Salir\n\n");
	utn_getNumero(&opc, "Seleccione una opcion: ", "Error, ", 1, 10, 3);
	return opc;
}

int menu_showSortMenu()
{
	int opc;
    printf("\n            ###   Menu de ordenamiento   ###\n");
    printf("\n\n");
    printf("1. Ordenar por Id.\n");
    printf("2. Ordenar por nombre.\n");
    printf("3. Ordenar por horas trabajadas.\n");
    printf("4. Ordenar por sueldo.\n");

    printf("10. Salir\n\n");
	utn_getNumero(&opc, "Seleccione una opcion: ", "Error, ", 1, 10, 3);
	return opc;
}
