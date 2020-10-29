#include "funciones.h"
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
void Menu(Employee* empleado[],LinkedList* miLista,Employee* aux)
{
    int menu=0;
    int opcion;
    int index;
    int len;
    int sueldoInt,horasTrabajadasInt;
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    char id[50];
    int i=0;
    int banderaParsearArchivo=0;
    FILE* pArchivo;

    do
    {
        printf("1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3.Aniadir Empleado\n4.Modificar Empleado\n5.Dar de baja\n6.Mostrar Empleados\n7.Ordenar Empleados\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9.Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10.salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                    pArchivo=fopen("data.csv","r");
                    if(pArchivo==NULL)
                    {
                        printf("Archivo incorrecto");
                        break;
                    }
                    //llamar al parser desde el controlador

                    if(!(parser_EmployeeFromText(pArchivo, miLista)))
                    {
                       printf("No se pudo cargar el archivo");
                    }
                    banderaParsearArchivo=1;
                break;
            case 2:
                pArchivo=fopen("data.csv","rb");
                break;
            case 3:
                if(banderaParsearArchivo)
                {
                    len=ll_len(miLista);
                    i=len+1;
                    empleado[i]=employee_new();
                    employee_setId(empleado[i],i);
                    ll_add(miLista,empleado[i]);
                }
                else
                {
                    printf("Carge el archivo primero");
                }
                break;
            case 4://no anda
                if(banderaParsearArchivo)
                {
                printf("Quien va a modificar?");
                scanf("%d",&index);
                i=index-1;
                if(!(empleado[i]=(Employee*)malloc(sizeof(Employee))))
                {
                    printf("No hay espacio!");
                    break;
                }
                employee_setId(empleado[i],i);
                printf("Ingrese nombre");
                fflush(stdin);
                scanf("%[^\n]",nombre);
                employee_setNombre(empleado[i],nombre);
                printf("Ingrese sueldo");
                fflush(stdin);
                scanf("%s",sueldo);
                sueldoInt=atoi(sueldo);
                employee_setSueldo(empleado[i],sueldoInt);

                printf("Ingrese horas trabajadas");
                fflush(stdin);
                scanf("%s",horasTrabajadas);
                horasTrabajadasInt=atoi(horasTrabajadas);
                employee_setHorasTrabajadas(empleado[i],horasTrabajadasInt);
                }
                //Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)

                //empleado[i]->horasTrabajadas=atoi(horasTrabajadas);
                //USAR SETTER

                break;
            case 5://NO ANDA EL MOSTRAR, CHECKEAR SI EXISTE EL QUE QUIERE BORRARSE
                //int elementoBorrado;
                printf("Quien va a borrar?");
                scanf("%d",&index);
                //1elementoBorrado=employee_getId(miLista,index-1);
                ll_remove(miLista,index-1);
                len=ll_len(miLista);
                printf("Borrando elemento seleccionado\n");
                //aux = (Employee*) ll_get(miLista,index-1);
                //printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);

                break;
            case 6:
                    len=ll_len(miLista);
                    printf("\nLOS PIBES\n");
                    for(int i=0;i<len;i++)
                    {
                       aux = (Employee*) ll_get(miLista,i);
                       printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
                    }
                    printf("\n");
                break;
            case 7:
                ll_sort(miLista,employee_CompareByName,1);//1 menor a mayor 0 mayor a menor
                len=ll_len(miLista);
                printf("Ordenados por Nombre\n");
                for(int i=0;i<len;i++)
                {
                   aux = (Employee*) ll_get(miLista,i);
                   printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
                }
                ll_sort(miLista,employee_CompareById,1);//1 menor a mayor 0 mayor a menor
                printf("Ordenados por id\n");
                for(int i=0;i<len;i++)
                {
                   aux = (Employee*) ll_get(miLista,i);
                   printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
                }
                break;
            case 8://no funciona
                controller_saveAsText(pArchivo, miLista);
                break;
            case 9:

                break;
            case 10:
                menu=1;
                fclose(pArchivo);
                break;
            default:
                printf("ERROR intente nuevamente");
                break;

        }
    }while(menu!=1);
}
