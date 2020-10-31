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
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).//----
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).//----
    10. Salir //listo
*****************************************************/
void Menu(Employee* empleado[],LinkedList* miLista,Employee* aux)
{
    int menu=0;
    int opcion;
    int index;
    int len;
    int sueldoInt,horasTrabajadasInt;
    char nombre[128];
    char horasTrabajadas[64];
    char sueldo[64];
    char id[64];
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
                        printf("Archivo incorrecto\n");
                        break;
                    }
                    //llamar al parser desde el controlador

                    if(!(parser_EmployeeFromText(pArchivo, miLista)))
                    {
                       printf("No se pudo cargar el archivo");
                    }
                    banderaParsearArchivo=1;
                    fclose(pArchivo);
                break;
            case 2:
               pArchivo=fopen("data.csv","rb");
                if(pArchivo==NULL)
                {
                    printf("Archivo incorrecto\n");
                    break;
                }
                if(!(parser_EmployeeFromBinary(pArchivo, miLista)))
                {
                   printf("No se pudo cargar el archivo");
                }
                banderaParsearArchivo=1;
                fclose(pArchivo);
                break;
            case 3:
                if(banderaParsearArchivo)
                {
                    len=ll_len(miLista);
                    printf("%s","aaaaa");
                    i=len+1;
                    //strcpy(id[0],i);
                    //id[0]=i;
                    printf("Ingrese nombre");
                    fflush(stdin);
                    scanf("%[^\n]",nombre);
                    printf("Ingrese sueldo");
                    fflush(stdin);
                    scanf("%s",sueldo);
                    printf("Ingrese horas trabajadas");
                    fflush(stdin);
                    scanf("%s",horasTrabajadas);
                    aux=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
                    empleado[i]=aux;
                    ll_add(miLista,empleado[i]);

                }
                else
                {
                    printf("Carge el archivo primero");
                }
                break;
            case 4://no anda Probar set o pop y push
                if(banderaParsearArchivo)
                {
                    printf("Quien va a modificar?");
                    scanf("%s",id);
                    index=atoi(id);
                    //employee_setId(empleado[i],i);
                    printf("Ingrese nombre");
                    fflush(stdin);
                    scanf("%[^\n]",nombre);
                    //employee_setNombre(empleado[i],nombre);
                    printf("Ingrese sueldo");
                    fflush(stdin);
                    scanf("%s",sueldo);
                    //sueldoInt=atoi(sueldo);
                    //employee_setSueldo(empleado[i],sueldoInt);

                    printf("Ingrese horas trabajadas");
                    fflush(stdin);
                    scanf("%s",horasTrabajadas);
                    //horasTrabajadasInt=atoi(horasTrabajadas);
                    //employee_setHorasTrabajadas(empleado[i],horasTrabajadasInt);
                    aux=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
                    ll_set(miLista,index-1,aux);
                }
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
                controller_saveAsBinary(pArchivo, miLista);
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
