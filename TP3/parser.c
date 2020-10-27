#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee,int i)
{
    /*int cant;
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    char id[50];
    cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
    if(cant==4)
    {
    empleado=(Employee*)malloc(sizeof(Employee));
    employee_setId(empleado,i+1);
    //empleado[i]->id = atoi(id);
    employee_setNombre(empleado,nombre);
    //strcpy(empleado[i]->nombre,nombre);//sizeof(arrayPersonas[i].nombre));
    employee_setHorasTrabajadas(empleado,horasTrabajadas);
    //empleado[i]->horasTrabajadas=atoi(horasTrabajadas);//sizeof(arrayPersonas[i].apellido));
    employee_setSueldo(empleado,sueldo);
    //empleado[i]->sueldo = atoi(sueldo);
    */
    return 1;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
