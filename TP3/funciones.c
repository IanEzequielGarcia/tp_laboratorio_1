#include "funciones.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).//listo
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).//listo
     3. Alta de empleado //listo
     4. Modificar datos de empleado //listo
     5. Baja de empleado //listo
     6. Listar empleados //listo
     7. Ordenar empleados //listo
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).//listo
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).//listo
    10. Salir //listo
*****************************************************/
void Menu(Employee* empleado[],LinkedList* miLista,Employee* aux)
{
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
                    controller_editEmployee(miLista);
                }
                else
                {
                    printf("Carge el archivo primero\n");
                }
                //USAR SETTER
                break;
            case 5://esto anda de maravilla
                if(banderaParsearArchivo)
                {
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
                        printf("No se pudo mostrar\n");
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
                    controller_sortEmployee(miLista);
                }
                else
                {
                    printf("Carge el archivo primero\n");
                }
                break;
            case 8://no funciona
                if(!(controller_saveAsText("data.csv", miLista)))
                   {
                       printf("\nError al guardar en el archivo\n");
                   }
                break;
            case 9:
                controller_saveAsBinary("data.bin", miLista);
                break;
            case 10:
                menu=1;
                break;
            default:
                printf("ERROR intente nuevamente");
                break;

        }
    }while(menu!=1);
}
