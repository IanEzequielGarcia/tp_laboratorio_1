#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id); //(x)
int employee_getId(Employee* this,int* id);//(x)

int employee_setNombre(Employee* this,char* nombre); //(x)
int employee_getNombre(Employee* this,char* nombre); //(x?)

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas); //(x)
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);//(x)

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_CompareByName(Employee* e1, Employee* e2); //(x)
int employee_CompareById(Employee* e1, Employee* e2);   //(x)

#endif // employee_H_INCLUDED
