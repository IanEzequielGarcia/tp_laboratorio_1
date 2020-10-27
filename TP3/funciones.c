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
    int len,i;
    int cant=0;
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    char id[50];
    FILE* pArchivo;

    do
    {
        printf("1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3.Aniadir Empleado\n4.Modificar Empleado\n5.Dar de baja\n6.Mostrar Empleados\n7.Ordenar Empleados\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9.Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10.salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                    pArchivo=fopen("data.csv","r");
                    len=parser_EmployeeFromText(pArchivo, miLista,empleado);
                    do
                    {
                        cant = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
                        if(cant==4)
                        {
                        empleado[i]=(Employee*)malloc(sizeof(Employee));

                        empleado[i]->id = atoi(id);
                        strcpy(empleado[i]->nombre,nombre);//sizeof(arrayPersonas[i].nombre));
                        empleado[i]->horasTrabajadas=atoi(horasTrabajadas);//sizeof(arrayPersonas[i].apellido));
                        empleado[i]->sueldo = atoi(sueldo);
                        ll_add(miLista,empleado[i]);
                        i++;
                        }
                        else
                        {
                            break;
                        }
                    }while(!feof(pArchivo) && i<len);
                     //ll_add(miLista,empleado);
                     /*for(i=0;i<1000;i++)
                     {
                         printf("%d %s %d %d",empleado[i]->id,empleado[i]->nombre,empleado[i]->horasTrabajadas,empleado[i]->sueldo);
                     }*/
                break;
            case 2:
                pArchivo=fopen("data.csv","rb");
                break;
            case 3:
                pArchivo = fopen("data.csv", "a");//Testeo CSV
                if(pArchivo!=NULL)
                {
                    fprintf(pArchivo,"\n%d,%s,%d,%d",15,"Juan",120,5000);

                }
                break;
            case 4:


                break;
            case 5:
                len=ll_len(miLista);
                printf("repitiendo e2\n");
                for(int i=0;i<len;i++)
                {
                   aux = (Employee*) ll_get(miLista,i);
                   printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
                }
                break;
            case 6:
                    ll_add(miLista,aux);
                    len=ll_len(miLista);
                    printf("repitiendo e2\n");
                    for(int i=0;i<len;i++)
                    {
                       aux = (Employee*) ll_get(miLista,i);
                       printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
                    }
                /*len= ll_len(miLista);
                printf("\n");
                for(int i=0;i<len;i++)
                {
                   aux = (Employee*) ll_get(miLista,i);
                   printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
                }*/
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
            case 8:
                len=ll_len(miLista);
                fwrite(miLista,1,len,pArchivo);
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
