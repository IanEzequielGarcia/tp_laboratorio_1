/******************************************************************************
1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
de Id. El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o name o lastName
o Salario o Sector
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfab�ticamente por lastName y Sector.
2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de alg�n empleado.
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "ArrayEmployees.h"

int main()
{
    int i=0;
    int menu;
    int banderaCaseOne=0;


    InitEmployees(eEmployeeArray,TAM);
    do
    {
        printf("1.A�adir Empleado\n2.Modificar Empleado\n3.Dar de baja\n4.Mostrar Empleados\n10.salir\n");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                eEmployeeArray[i]=addEmployees(eEmployeeArray,TAM);
                banderaCaseOne=1;
                i++;
                break;
            case 2:
                if(banderaCaseOne==1)
                {
                    ModifyEmployee(eEmployeeArray);
                }
                else
                {
                 printf("Debe cargar algun numero primero\n");
                }
                break;
            case 3:
                if(banderaCaseOne==1)
                {
                    RemoveEmployee(eEmployeeArray);
                }
                else
                {
                 printf("Debe cargar algun numero primero\n");
                }
                break;
            case 4:
                if(banderaCaseOne==1)
                {
                    PrintEmployees(eEmployeeArray,TAM);
                    printf("\n");
                }
                else
                {
                 printf("Debe cargar algun numero primero\n");
                }

                break;
        }
    }while(menu!=10);


    return 0;
}

