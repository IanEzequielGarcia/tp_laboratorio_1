#include "funciones.h"
#include "stdio.h"
int Suma(int numeroUno,int numeroDos)
{
    int resultado;
    resultado=numeroUno+numeroDos;
    return resultado;
}
int Resta(int numeroUno,int numeroDos)
{
    int resultado;
    resultado=numeroUno-numeroDos;
    return resultado;
}
int Multiplicacion(int numeroUno,int numeroDos)
{
    int resultado;
    resultado=numeroUno*numeroDos;
    return resultado;
}
float Division(int numeroUno,int numeroDos)
{
    float resultado;
    if(numeroUno!=0 && numeroDos!=0)
    {
        resultado=(float)numeroUno/numeroDos;
    }
    else
    {
        return 0;
    }
    return resultado;
}
int Recursividad(int numeroUno)
{
 int resultado;

    if(numeroUno == 0)
    {
        resultado = 1;
    }
    else
    {
        /*for(;numero>0;numero--)
        {
            resultado = numero * (numero-1);
        }*/
         resultado = numeroUno*Recursividad(numeroUno - 1);
    }

    return resultado;

}
