#include <stdlib.h>
#include "Employee.h"
#include <string.h>

int employee_CompareByName(Employee* empleadoUno,Employee* empleadoDos)
{
    return strcmp(empleadoUno->nombre,empleadoDos->nombre);

}
int employee_CompareById(Employee* empleadoUno,Employee* empleadoDos)
{
    int compare=0;
    if(empleadoUno->id>empleadoDos->id)
    {
        compare=1;
    }
    else                                    //USAR GETTERS Y SETTERS
                                            //NO USAR ->
    {
        if(empleadoUno->id<empleadoDos->id)
        {
            compare=-1;
        }
    }
    return compare;
}

int employee_getId(Employee* this,int* id)
{
    int getteo=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        getteo = 1;
    }
    return getteo;
}

int employee_setId(Employee* this,int id)
{
    int setteo=0;
    if(this!=NULL && id!=-1)
    {
        this->id=id;
        setteo = 1;
    }
    return setteo;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int setteo=0;
    if(this!=NULL && *nombre!='\0')
    {
        strcpy(this->nombre,nombre);
        setteo=1;
    }
    return setteo;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int getteo=0;
    if(this!=NULL && *nombre!='\0')
    {
        strcpy(nombre,this->nombre);
        getteo = 1;
    }
     return getteo;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int setteo=0;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        setteo = 1;
    }
    return setteo;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int getteo=0;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        getteo = 1;
    }
    return getteo;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int setteo=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        setteo = 1;
    }
    return setteo;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int getteo=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        getteo = 1;
    }
    return getteo;
}
Employee* employee_new()
{
    int sueldoInt,horasTrabajadasInt;
    char nombre[128];
    char horasTrabajadas[50];
    char sueldo[50];

    Employee* nuevoEmpleado;

    if(!(nuevoEmpleado=(Employee*)malloc(sizeof(Employee))))
    {
        printf("No hay espacio!");
    }
    else
    {
        printf("Ingrese nombre ");
        fflush(stdin);
        scanf("%[^\n]",nombre);
        employee_setNombre(nuevoEmpleado,nombre);
        printf("Ingrese sueldo ");
        fflush(stdin);
        scanf("%s",sueldo);
        sueldoInt=atoi(sueldo);
        employee_setSueldo(nuevoEmpleado,sueldoInt);

        printf("Ingrese horas trabajadas ");
        fflush(stdin);
        scanf("%s",horasTrabajadas);
        horasTrabajadasInt=atoi(horasTrabajadas);
        employee_setHorasTrabajadas(nuevoEmpleado,horasTrabajadasInt);
    }
   return nuevoEmpleado;
}
/*Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

}*/
