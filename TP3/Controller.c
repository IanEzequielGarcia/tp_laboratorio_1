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
    pArchivo=fopen("data.csv","r");

    if(path!=NULL)
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
    pArchivo=fopen("data.bin","rb");
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


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int len,i;
    char nombre[128];
    char horasTrabajadas[64];
    char sueldo[64];
    char id[64];
    int sePudo=0;
    int validacion;
    Employee* empleado[TAM];
    Employee* aux;

    len=ll_len(pArrayListEmployee);
    i=len+1;
    sprintf(id, "%d", i);
    printf("Ingrese nombre ");
    fflush(stdin);
    scanf("%[^\n]",nombre);
    validacion=ValidarString(nombre);
    while(validacion)
    {
        printf("ReIngrese el nombre\n");
        fflush(stdin);
        scanf("%s",nombre);
        validacion=ValidarString(nombre);
    }
    printf("Ingrese sueldo ");
    fflush(stdin);
    scanf("%s",sueldo);
    validacion=ValidarInt(sueldo);
    while(validacion)
    {
        printf("REingrese el sueldo\n");
        scanf("%s",sueldo);
        validacion=ValidarInt(sueldo);
    }
    printf("Ingrese horas trabajadas ");
    fflush(stdin);
    scanf("%s",horasTrabajadas);
    validacion=ValidarInt(horasTrabajadas);
    while(validacion)
    {
        printf("REingrese las horas trabajadas\n");
        scanf("%s",horasTrabajadas);
        validacion=ValidarInt(horasTrabajadas);
    }
    aux=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
    empleado[i]=aux;
    ll_add(pArrayListEmployee,empleado[i]);
    sePudo=1;
    return sePudo;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;

    char nombre[128];
    char horasTrabajadas[64];
    char sueldo[64];
    char id[64];
    int index;
    int validacion;

    printf("Quien va a modificar? ");
    scanf("%s",id);
    index=atoi(id);

    printf("Ingrese nombre ");
    fflush(stdin);
    scanf("%[^\n]",nombre);
    validacion=ValidarString(nombre);
    while(validacion)
    {
        printf("ReIngrese el nombre\n");
        fflush(stdin);
        scanf("%s",nombre);
        validacion=ValidarString(nombre);
    }
    printf("Ingrese sueldo ");
    fflush(stdin);
    scanf("%s",sueldo);
    validacion=ValidarInt(sueldo);
    while(validacion)
    {
        printf("REingrese el sueldo\n");
        scanf("%s",sueldo);
        validacion=ValidarInt(sueldo);
    }
    printf("Ingrese horas trabajadas ");
    fflush(stdin);
    scanf("%s",horasTrabajadas);
    validacion=ValidarInt(horasTrabajadas);
    while(validacion)
    {
        printf("REingrese las horas trabajadas\n");
        scanf("%s",horasTrabajadas);
        validacion=ValidarInt(horasTrabajadas);
    }
    aux=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
    ll_set(pArrayListEmployee,index-1,aux);

    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;

    int index;
    int i;
    int len;
    int sePudo=0;
    printf("Quien va a borrar?");
    scanf("%d",&index);
    index--;
    len=ll_len(pArrayListEmployee);
    for(i=0;i<len;i++)
    {
        if(i==index)
        {
            aux = (Employee*) ll_get(pArrayListEmployee,index);
            printf("(%6d) %6d %15s %8d %6d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
            ll_remove(pArrayListEmployee,index);
            len=ll_len(pArrayListEmployee);
            sePudo=1;
        }
    }
    return sePudo;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
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
    int sePudo=0;

    ll_sort(pArrayListEmployee,employee_CompareByName,1);//1 menor a mayor 0 mayor a menor
    printf("Ordenados por Nombre\n");
    controller_ListEmployee(pArrayListEmployee);
    ll_sort(pArrayListEmployee,employee_CompareById,1);//1 menor a mayor 0 mayor a menor
    printf("Ordenados por id\n");
    controller_ListEmployee(pArrayListEmployee);
    sePudo++;
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

