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
    else
    {
        if(empleadoUno->id<empleadoDos->id)
        {
            compare=-1;
        }
    }
    return compare;
}
