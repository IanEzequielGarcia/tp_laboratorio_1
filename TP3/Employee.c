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
int employee_CompareBySalary(Employee* empleadoUno,Employee* empleadoDos)
{
    int compare=0;
    if(empleadoUno->sueldo>empleadoDos->sueldo)
    {
        compare=1;
    }
    else                                    //USAR GETTERS Y SETTERS
                                            //NO USAR ->
    {
        if(empleadoUno->sueldo<empleadoDos->sueldo)
        {
            compare=-1;
        }
    }
    return compare;
}
int employee_CompareByWorkingHours(Employee* empleadoUno,Employee* empleadoDos)
{
    int compare=0;
    if(empleadoUno->horasTrabajadas>empleadoDos->horasTrabajadas)
    {
        compare=1;
    }
    else                                    //USAR GETTERS Y SETTERS
                                            //NO USAR ->
    {
        if(empleadoUno->horasTrabajadas<empleadoDos->horasTrabajadas)
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
    if(this!=NULL && nombre!=NULL)
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
    Employee* nuevoEmpleado=NULL;
    nuevoEmpleado=(Employee*)malloc(sizeof(Employee));
   return nuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* EmpleadoAux;
    int sueldoInt;
    int horasTrabajadasInt;
    int idInt;

    EmpleadoAux=employee_new();

    if(EmpleadoAux!=NULL)
    {
        idInt=atoi(idStr);
        employee_setId(EmpleadoAux,idInt);
        employee_setNombre(EmpleadoAux,nombreStr);
        sueldoInt=atoi(sueldoStr);
        employee_setSueldo(EmpleadoAux,sueldoInt);
        horasTrabajadasInt=atoi(horasTrabajadasStr);
        employee_setHorasTrabajadas(EmpleadoAux,horasTrabajadasInt);
    }

    return EmpleadoAux;
}
int ValidarInt(char NumeroIngresado[])
{
    int i;
    int longitud;
    int resultado;
    longitud=strlen(NumeroIngresado);
    for(i=0;i<longitud;i++)
    {
       if(isdigit(NumeroIngresado[i])!=0)
       {
           resultado=1;
       }
       else
       {
           do
           {
            printf("REingrese numero ingresado\n");
            scanf("%s",NumeroIngresado);
            resultado=ValidarInt(NumeroIngresado);
           }while(resultado!=1);
       }
    }
    return resultado;
}
int ValidarString(char StringIngresado[])
{
    int i;
    int longitud;
    int resultado;
    longitud=strlen(StringIngresado);
    for(i=0;i<longitud;i++)
    {
       if(isalpha(StringIngresado[i])!=0)
       {
           resultado=1;
       }
       else
       {
            do
            {
                printf("ReIngrese la palabra\n");
                fflush(stdin);
                scanf("%s",StringIngresado);
                resultado=ValidarString(StringIngresado);
            }while(resultado!=1);
       }
    }
    return resultado;
}
