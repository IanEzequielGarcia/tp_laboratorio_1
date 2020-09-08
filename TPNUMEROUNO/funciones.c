#include "funciones.h"
#include "stdio.h"
float Suma(float numeroUno,float numeroDos)
{
    float resultado;
    resultado=numeroUno+numeroDos;
    return resultado;
}
float Resta(float numeroUno,float numeroDos)
{
    float resultado;
    resultado=numeroUno-numeroDos;
    return resultado;
}
float Multiplicacion(float numeroUno,float numeroDos)
{
    float resultado;
    resultado=numeroUno*numeroDos;
    return resultado;
}
float Division(float numeroUno,float numeroDos)
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
    if(numeroUno<0)
    {
        return 0;
    }
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
