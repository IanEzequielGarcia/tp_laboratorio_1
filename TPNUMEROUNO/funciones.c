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
long int Recursividad(int numeroUno)
{
 long int resultado;
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
void MostrarResultados(int banderaOperaciones,float resultadoSuma,float resultadoResta,
                       float resultadoMultiplicacion,float resultadoFloat,long int resultadoFactorizacionr1,long int resultadoFactorizacionr2)
{
        if(banderaOperaciones==0)
        {
            printf("\nPor favor, primero seleccione la opcion 3 y haga las operaciones\n\n");
        }
        else
        {
            printf("\nEl resultado de la suma es %.2f \n",resultadoSuma);
            printf("El resultado de la resta es %.2f \n",resultadoResta);
            printf("El resultado de la Multiplicacion es %.2f \n",resultadoMultiplicacion);
            if(resultadoFloat==0)
            {
                printf("No se puede dividir por 0\n");
            }
            else
            {
                printf("El resultado de la Division es %.2f \n",resultadoFloat);
            }
            // validacion factorizaciones
            if(resultadoFactorizacionr1==0)
            {
                printf("A debe ser 0 o positivo para factorizar\n");
            }
            else
            {
                printf("El resultado de la factorizacion del primer numero es %ld \n",resultadoFactorizacionr1);
            }
            if(resultadoFactorizacionr2==0)
            {
                printf("B debe ser 0 o positivo para factorizar\n");
            }
            else
            {
                printf("El resultado de la factorizacion del segundo numero es %ld \n\n",resultadoFactorizacionr2);
            }
        }
}
