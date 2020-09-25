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
    long int resultadoFactorizacionr1;
    long int resultadoFactorizacionr2;
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
                    printf("\nOperaciones realizadas\n\n");
                    break;
                }
            case 4:
                MostrarResultados(banderaOperaciones,resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoFloat,resultadoFactorizacionr1,resultadoFactorizacionr2);
                break;
            case 5:
                printf("\nMuchas gracias por usar la pseudoCalculadora, hasta la proxima\n");
                loopMenu=1;
                break;
            default:
                printf("\nERROR! Por favor elija una opcion entre 1 y 5\n");
                break;

        }
    }

    return 0;
}

