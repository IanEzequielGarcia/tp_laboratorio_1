#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
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


int main()
{
    LinkedList* miLista;
    Employee* aux;
    int len;

    miLista = ll_newLinkedList();//lamar al constructor
    len= ll_len(miLista);
    printf("Cantidad %d\n",len);

    Employee* empleado[TAM];
    Menu(empleado,miLista,aux);

/*
    // ADD
    Employee* empleadoUno;

    empleadoUno=(Employee*)malloc(sizeof(Employee));
    empleadoUno->id=1;
    empleadoUno->sueldo=500;
    empleadoUno->horasTrabajadas=8;
    strcpy(empleadoUno->nombre,"Juan");

    Employee* empleadoDos;

    empleadoDos=(Employee*)malloc(sizeof(Employee));
    empleadoDos->id=4;
    empleadoDos->sueldo=800;
    empleadoDos->horasTrabajadas=10;
    strcpy(empleadoDos->nombre,"Carlos");

    Employee* empleadoTres;

    empleadoTres=(Employee*)malloc(sizeof(Employee));
    empleadoTres->id=12;
    empleadoTres->sueldo=200;
    empleadoTres->horasTrabajadas=4;
    strcpy(empleadoTres->nombre,"Pepe");

    Employee* empleadoCuatro;

    empleadoCuatro=(Employee*)malloc(sizeof(Employee));
    empleadoCuatro->id=54;
    empleadoCuatro->sueldo=400;
    empleadoCuatro->horasTrabajadas=6;
    strcpy(empleadoCuatro->nombre,"Maria");

    ll_add(miLista,empleadoUno);
    ll_add(miLista,empleadoDos);
    ll_add(miLista,empleadoTres);
    ll_add(miLista,empleadoCuatro);

    //hacerlo para que lo tome desde el archivo
    //y no de un hardcodeo
    len= ll_len(miLista);
    printf("Cantidad %d\n",len);//muestra la cant de empleados
    //GET
    printf("\n");

    for(int i=0;i<len;i++)
    {
       aux = (Employee*) ll_get(miLista,i);
       printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
    }


    //BORRAR
    printf("\n");

    int index;
    index=2;//HARCODEO, CAMBIAR DESPUES
    ll_remove(miLista,index-1);
    len=ll_len(miLista);
    printf("Borrando elemento 2\n");
    for(int i=0;i<len;i++)
    {
       aux = (Employee*) ll_get(miLista,i);
       printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
    }

    //INDEXOF
    printf("\n");

    index = (Employee*) ll_indexOf(miLista,empleadoUno);
    printf("INDEXOF e1 %d\n",index);

    index = (Employee*) ll_indexOf(miLista,empleadoTres);
    printf("INDEXOF e3 %d\n",index);


    //SET
    printf("\n");

    ll_set(miLista,2,empleadoDos);

    len=ll_len(miLista);
    printf("Empleado2 reemplazando a E3\n");
    for(int i=0;i<len;i++)
    {
       aux = (Employee*) ll_get(miLista,i);
       printf("(%d)%d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
    }
     //PUSH
     ll_push(miLista,2,empleadoCuatro);

    len=ll_len(miLista);
    printf("Empleado4 clavandose en index 2\n");
    for(int i=0;i<len;i++)
    {
       aux = (Employee*) ll_get(miLista,i);
       printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
    }
    //ADD
    ll_add(miLista,empleadoDos);

    len=ll_len(miLista);
    printf("repitiendo e2\n");
    for(int i=0;i<len;i++)
    {
       aux = (Employee*) ll_get(miLista,i);
       printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
    }
    //POP
    ll_pop(miLista,3);

    len=ll_len(miLista);
    printf("pop elemento 3\n");
    for(int i=0;i<len;i++)
    {
       aux = (Employee*) ll_get(miLista,i);
       printf("(%d) %d %s %d %d\n",i+1,aux->id,aux->nombre,aux->sueldo,aux->horasTrabajadas);
    }
    //SORT
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


*/
    return 0;
}
