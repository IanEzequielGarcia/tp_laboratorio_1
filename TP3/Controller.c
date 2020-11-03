#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int sePudo=0;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");

    if(pArchivo!=NULL)
    {
        if(parser_EmployeeFromText(pArchivo, pArrayListEmployee))
        {
           sePudo++;
        }
    }
    fclose(pArchivo);

    return sePudo;
}
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int sePudo=0;
    FILE* pArchivo;
    pArchivo=fopen(path,"rb");
    if(pArchivo!=NULL)
    {
        if(parser_EmployeeFromBinary(pArchivo, pArrayListEmployee))
        {
           sePudo++;
        }
    }
    fclose(pArchivo);
    return sePudo;
}
int controller_addEmployee(LinkedList* pArrayListEmployee)//hacer funcion
{
    int len,i;
    char nombre[128];
    char horasTrabajadas[64];
    char sueldo[64];
    char id[64];
    int sePudo=0;
    Employee* empleado[TAM];
    Employee* aux;

    len=ll_len(pArrayListEmployee);
    i=len+1;
    sprintf(id, "%d", i);
    printf("Ingrese nombre ");
    fflush(stdin);
    scanf("%[^\n]",nombre);
    ValidarString(nombre);
    printf("Ingrese sueldo ");
    fflush(stdin);
    scanf("%s",sueldo);
    ValidarInt(sueldo);
    printf("Ingrese horas trabajadas ");
    fflush(stdin);
    scanf("%s",horasTrabajadas);
    ValidarInt(horasTrabajadas);
    aux=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
    empleado[i]=aux;
    ll_add(pArrayListEmployee,empleado[i]);
    sePudo=1;
    return sePudo;
}
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux=NULL;

    int sePudo=1;
    char nombre[128];
    char horasTrabajadas[64];
    char sueldo[64];
    int index;
    int opcion;
    int sueldoInt,horasTrabajadasInt;

    printf("Que indice va a modificar? ");
    scanf("%d",&index);
    index--;
    aux=(Employee*)ll_get(pArrayListEmployee,index);
    if(employee_getId(aux,&index))
    {
        printf("Que quiere modificar?\n1.Nombre\n2.Sueldo\n3.Horas Trabajadas\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("Ingrese nombre ");
                fflush(stdin);
                scanf("%[^\n]",nombre);
                ValidarString(nombre);
                employee_setNombre(aux,nombre);
                break;
            case 2:
                printf("Ingrese sueldo ");
                fflush(stdin);
                scanf("%s",sueldo);
                ValidarInt(sueldo);
                sueldoInt=atoi(sueldo);
                employee_setSueldo(aux,sueldoInt);
                break;
            case 3:
                printf("Ingrese horas trabajadas ");
                fflush(stdin);
                scanf("%s",horasTrabajadas);
                ValidarInt(horasTrabajadas);
                horasTrabajadasInt=atoi(horasTrabajadas);
                employee_setHorasTrabajadas(aux,horasTrabajadasInt);
                break;
        }

    }
    else
    {
        sePudo=0;
    }

    return sePudo;
}
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux=NULL;

    int index;
    int id;
    int sePudo=0;

    printf("Quien va a borrar?");
    scanf("%d",&index);
    index--;//hacerlo con getters
    id=index;
    aux=(Employee*)ll_get(pArrayListEmployee,index);
    if(employee_getId(aux,&index))
    {
        ll_remove(pArrayListEmployee,id);
        ll_len(pArrayListEmployee);
        sePudo=1;
    }
    return sePudo;
}
int controller_ListEmployee(LinkedList* pArrayListEmployee)//hacer otra funcion para mostrar un solo empleado
{
    int len=0;
    int sePudo=0;

    Employee* aux=NULL;
    len=ll_len(pArrayListEmployee);
    for(int i=0;i<len;i++)
    {
       aux = (Employee*) ll_get(pArrayListEmployee,i);
       printf("(%6d) %6d %15s %8d %6d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
    }
    printf("\n");
    sePudo=1;

    return sePudo;
}
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int sePudo=0;//hacerle if a sort
    int opcion;
    printf("De que forma los quiere ordenar?\n1.Nombre(menor a mayor)\n2.id(menor a mayor)\n3.Salario(menor a mayor)\n4.Horas trabajadas(menor a mayor)\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
        case 1:
            if(!(ll_sort(pArrayListEmployee,(void*)employee_CompareByName,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por Nombre\n");
                controller_ListEmployee(pArrayListEmployee);
                sePudo=1;
            }
            break;
        case 2:

            if(!(ll_sort(pArrayListEmployee,(void*)employee_CompareById,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por id\n");
                controller_ListEmployee(pArrayListEmployee);
                sePudo=1;
            }
            break;
        case 3:
            if(!(ll_sort(pArrayListEmployee,(void*)employee_CompareBySalary,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por sueldo\n");
                controller_ListEmployee(pArrayListEmployee);
                sePudo=1;
            }
            break;
        case 4:
            if(!(ll_sort(pArrayListEmployee,(void*)employee_CompareByWorkingHours,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por horas trabajadas\n");
                controller_ListEmployee(pArrayListEmployee);
                sePudo=1;
            }
            break;
    }
    return sePudo;
}
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    Employee* empleado=NULL;
    FILE* pAux;
    int len;
    int i=0;
    int aux;
    int devolver=0;
    pAux=fopen(path,"w");

    if(pAux!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        aux=len-1;
        while(!feof(pAux))
        {
            empleado=employee_new();
            if(aux==i)
            {
                empleado=(Employee*) ll_get(pArrayListEmployee,i);
                fprintf(pAux,"%d,%s,%d,%d",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
                devolver=1;
                break;
            }
            else
            {
                empleado=(Employee*) ll_get(pArrayListEmployee,i);
                fprintf(pAux,"%d,%s,%d,%d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
                i++;
            }
        }
    }
    fclose(pAux);
    return devolver;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* empleado=NULL;
    FILE* pAux;
    int len;
    int i=0;
    int aux;
    int devolver=0;
    pAux=fopen(path,"wb");

    if(pAux!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        aux=len-1;
        while(!feof(pAux))
        {
            empleado=employee_new();
            if(aux==i)
            {
                empleado=(Employee*) ll_get(pArrayListEmployee,i);
                fprintf(pAux,"%d,%s,%d,%d",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
                devolver=1;
                break;
            }
            else
            {
                empleado=(Employee*) ll_get(pArrayListEmployee,i);
                fprintf(pAux,"%d,%s,%d,%d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
                i++;
            }
        }
    }
    fclose(pAux);
    return devolver;
}

