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
    int primerNumero;
    int segundoNumero;
    int tipoOperacion;
    int loopPregunta=0;
    int resultadoInt;
    float resultadoFloat;

    printf("Ingrese el primer numero\n");
    scanf("%d",&primerNumero);
    printf("Ingrese el segundo numero\n");
    scanf("%d",&segundoNumero);

    while(loopPregunta==0)
    {
        printf("Ingrese el tipo de operacion\n");
        printf("1.Calcular la suma (A+B)\n");
        printf("2.Calcular la resta (A-B)\n");
        printf("3.Calcular la multiplicacion (A*B)\n");
        printf("4.Calcular la division (A/B)\n");
        printf("5.Calcular el factorial (A!)\n");
        printf("6.Salir\n");
        scanf("%d",&tipoOperacion);

        switch(tipoOperacion)
        {
            case 1:
                resultadoInt= Suma(primerNumero,segundoNumero);
                printf("El resultado de la suma es %d \n",resultadoInt);
                break;
            case 2:
                resultadoInt= Resta(primerNumero,segundoNumero);
                printf("El resultado de la resta es %d \n",resultadoInt);
                break;
            case 3:
                resultadoInt= Multiplicacion(primerNumero,segundoNumero);
                printf("El resultado de la Multiplicacion es %d \n",resultadoInt);
                break;
            case 4:
                 resultadoFloat= Division(primerNumero,segundoNumero);
                 printf("El resultado de la Division es %.2f \n",resultadoFloat);
                 break;
            case 5:
                resultadoInt= Recursividad(primerNumero);
                printf("El resultado de la factorizacion del primer numero es %d \n",resultadoInt);
                break;
            case 6:
                loopPregunta=1;
                break;
        }
    }

    return 0;
}
