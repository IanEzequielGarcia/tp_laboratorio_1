#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int cant;
    int sueldoInt,horasTrabajadasInt;
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    char id[50];
    int i=0;
    int sePudo=0;
    Employee* EmpleadoAux[TAM];

    do//llamar al parser desde el controlador
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        if(cant==4)
        {
            if(!(EmpleadoAux[i]=(Employee*)malloc(sizeof(Employee))))
            {
                printf("No hay espacio!");
            }
            else
            {
                employee_setId(EmpleadoAux[i],i+1);
                employee_setNombre(EmpleadoAux[i],nombre);
                horasTrabajadasInt=atoi(horasTrabajadas);
                employee_setHorasTrabajadas(EmpleadoAux[i],horasTrabajadasInt);
                sueldoInt=atoi(sueldo);
                employee_setSueldo(EmpleadoAux[i],sueldoInt);
                ll_add(pArrayListEmployee,EmpleadoAux[i]);
                i++;
                sePudo=1;
            }
        }
    }while(!feof(pFile));
    fclose(pFile);
    return sePudo;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int cant;
    int sueldoInt,horasTrabajadasInt;
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    char id[50];
    int i=0;
    int sePudo=0;
    Employee* EmpleadoAux[TAM];

    do//llamar al parser desde el controlador
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        if(cant==4)
        {
            if(!(EmpleadoAux[i]=(Employee*)malloc(sizeof(Employee))))
            {
                printf("No hay espacio!");
            }
            else
            {
                employee_setId(EmpleadoAux[i],i+1);
                employee_setNombre(EmpleadoAux[i],nombre);
                horasTrabajadasInt=atoi(horasTrabajadas);
                employee_setHorasTrabajadas(EmpleadoAux[i],horasTrabajadasInt);
                sueldoInt=atoi(sueldo);
                employee_setSueldo(EmpleadoAux[i],sueldoInt);
                ll_add(pArrayListEmployee,EmpleadoAux[i]);
                i++;
                sePudo=1;
            }
        }
    }while(!feof(pFile));
    fclose(pFile);
    return sePudo;
}
