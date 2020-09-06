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
    int primerNumero=0;
    int segundoNumero=0;
    int seleccionMenu;
    int loopMenu=0;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    int resultadoFactorizacionr1;
    int resultadoFactorizacionr2;
    float resultadoFloat;

    while(loopMenu==0)
    {
        printf("1.Ingresar 1er operando\n");
        printf("2.Ingresar 2do operando\n");
        printf("3.Calcular todas las operaciones\n");
        printf("4.Mostar resultados\n");
        printf("5. Salir\n");
        scanf("%d",&seleccionMenu);
         switch(seleccionMenu)
        {
            case 1:
                printf("Ingrese el primer numero\n");
                scanf("%d",&primerNumero);
                printf("A=%d\n",primerNumero);
                break;
            case 2:
                printf("Ingrese el segundo numero\n");
                scanf("%d",&segundoNumero);
                printf("B=%d\n",segundoNumero);
                break;
            case 3:
                resultadoSuma= Suma(primerNumero,segundoNumero);
                resultadoResta= Resta(primerNumero,segundoNumero);
                resultadoMultiplicacion= Multiplicacion(primerNumero,segundoNumero);
                resultadoFloat= Division(primerNumero,segundoNumero);
                resultadoFactorizacionr1= Recursividad(primerNumero);
                resultadoFactorizacionr2= Recursividad(segundoNumero);
                break;
            case 4:
                printf("El resultado de la suma es %d \n",resultadoSuma);
                printf("El resultado de la resta es %d \n",resultadoResta);
                printf("El resultado de la Multiplicacion es %d \n",resultadoMultiplicacion);
                if(resultadoFloat==0)
                {
                    printf("No se puede dividir por 0\n");
                }
                else
                {
                    printf("El resultado de la Division es %.2f \n",resultadoFloat);
                }
                printf("El resultado de la factorizacion del primer numero es %d \n",resultadoFactorizacionr1);
                printf("El resultado de la factorizacion del segundo numero es %d \n",resultadoFactorizacionr2);
                break;
            case 5:
                printf("Muchas gracias por usar la pseudoCalculadora, hasta la proxima");
                loopMenu=1;
                break;
        }
    }

    return 0;
}

