#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include <string.h>
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
    LinkedList* miLista;
    miLista = ll_newLinkedList();

    int menu=0;
    int opcion;

    int banderaParsearArchivo=0;
    do
    {
        printf("1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3.Aniadir Empleado\n4.Modificar Empleado\n5.Dar de baja\n6.Mostrar Empleados\n7.Ordenar Empleados\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9.Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10.salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                    if(!(controller_loadFromText("data.csv", miLista)))
                    {
                        printf("Error al leer el archivo");
                        break;
                    }
                    banderaParsearArchivo=1;
                break;
            case 2:
                if(!(controller_loadFromBinary("data.bin", miLista)))
                {
                    printf("Error al leer el archivo");
                    break;
                }
                banderaParsearArchivo=1;
                break;
            case 3:
                if(banderaParsearArchivo)
                {
                    if((!controller_addEmployee(miLista)))
                    {
                        printf("Error al agregar empleado\n");
                    }
                }
                else
                {
                    printf("Carge el archivo primero\n");
                }
                break;
            case 4:
                if(banderaParsearArchivo)
                {
                    if(!(controller_ListEmployee(miLista)))
                    {
                        printf("No se pudo mostrar la lista\n");
                    }
                    if(!(controller_editEmployee(miLista)))
                    {
                        printf("No se pudo modificar el elemento seleccionado\n");
                    }
                }
                else
                {
                    printf("Carge el archivo primero\n");
                }

                break;
            case 5:
                if(banderaParsearArchivo)
                {
                    if(!(controller_ListEmployee(miLista)))
                    {
                        printf("No se pudo mostrar la lista\n");
                    }
                    if(!(controller_removeEmployee(miLista)))
                    {
                        printf("No se pudo borrar el elemento seleccionado\n");
                    }
                    else
                    {
                        printf("Borrando elemento seleccionado\n");
                    }
                }
                else
                {
                    printf("Carge el archivo primero\n");
                }
                break;
            case 6:
                if(banderaParsearArchivo)
                {
                    if(!(controller_ListEmployee(miLista)))
                    {
                        printf("No se pudo mostrar la lista\n");
                    }
                }
                else
                {
                    printf("Carge el archivo primero\n");
                }
                break;
            case 7:
                if(banderaParsearArchivo)
                {
                    if(!(controller_sortEmployee(miLista)))
                    {
                        printf("No se pudo ordenar la lista\n");
                    }
                }
                else
                {
                    printf("Carge el archivo primero\n");
                }
                break;
            case 8:
                if(banderaParsearArchivo)
                {
                    if(!(controller_saveAsText("data.csv", miLista)))
                       {
                           printf("\nError al guardar, reintente\n");
                       }
                }
                else
                {
                    printf("Carge el archivo primero\n");
                }
                break;
            case 9:
                if(banderaParsearArchivo)
                {
                    if(!(controller_saveAsBinary("data.bin", miLista)))
                    {
                        printf("\nError al guardar, reintente\n");
                    }
                }
                else
                {
                    printf("Carge el archivo primero\n");
                }
                break;
            case 10:
                menu=1;
                 printf("\n\nHasta la proximaa\n\n");
                break;
            default:
                printf("ERROR intente nuevamente");
                break;

        }
    }while(menu!=1);
    return 0;
}
