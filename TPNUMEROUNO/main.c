/*
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
*/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float primerNumero=0;
    float segundoNumero=0;
    int factorizarPrimerNumero=0;
    int factorizarSegundoNumero=0;
    int seleccionMenu;
    int loopMenu=0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    int resultadoFactorizacionr1;
    int resultadoFactorizacionr2;
    float resultadoFloat;
    int banderaOperaciones=0;

    while(loopMenu==0)
    {
        printf("A=%.2f\n",primerNumero);
        printf("B=%.2f\n",segundoNumero);
        printf("1.Ingresar 1er operando\n");
        printf("2.Ingresar 2do operando\n");
        printf("3.Calcular todas las operaciones\n");
        printf("4.Mostar resultados\n");
        printf("5. Salir\n\n");
        scanf("%d",&seleccionMenu);
        switch(seleccionMenu)
        {
            case 1:
                printf("Ingrese el primer numero\n");
                scanf("%f",&primerNumero);
                factorizarPrimerNumero=primerNumero;
                break;
            case 2:
                printf("Ingrese el segundo numero\n");
                scanf("%f",&segundoNumero);
                factorizarSegundoNumero=segundoNumero;
                break;
            case 3:
                if(primerNumero==0&&segundoNumero==0)
                {
                    printf("\nPor favor, ingrese un valor para A o B primero y reintente \n\n");
                    break;
                }
                else
                {
                resultadoSuma= Suma(primerNumero,segundoNumero);
                resultadoResta= Resta(primerNumero,segundoNumero);
                resultadoMultiplicacion= Multiplicacion(primerNumero,segundoNumero);
                resultadoFloat= Division(primerNumero,segundoNumero);
                resultadoFactorizacionr1= Recursividad(factorizarPrimerNumero);
                resultadoFactorizacionr2= Recursividad(factorizarSegundoNumero);

                banderaOperaciones=1;
                break;
                }
            case 4:
                if(banderaOperaciones==0)
                {
                    printf("\nPor favor, primero seleccione la opcion 3 y haga las operaciones\n\n");
                    break;
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
                    if(resultadoFactorizacionr1==0||resultadoFactorizacionr2==0)
                    {
                        printf("haga el factorial de un numero mayor a 0\n");
                    }
                    else
                    {
                        printf("El resultado de la factorizacion del primer numero es %d \n",resultadoFactorizacionr1);
                        printf("El resultado de la factorizacion del segundo numero es %d \n\n",resultadoFactorizacionr2);
                    }
                    break;
                case 5:
                    printf("\nMuchas gracias por usar la pseudoCalculadora, hasta la proxima\n");
                    loopMenu=1;
                    break;
                }

        }
    }

    return 0;
}

