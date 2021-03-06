#include "ArrayEmployees.h"


void LoadEmployees(eEmployee eEmployeeArray[],int cant)
{
    int hayEspacio;

    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
    int id;
    hayEspacio=SearchForFree(eEmployeeArray,cant);
    if(hayEspacio!=-1)
    {
        id=hayEspacio;
        printf("Ingrese su nombre\n");
       fflush(stdin);
        scanf("%[^\n]",name);
        printf("Ingrese su apellido\n");
       fflush(stdin);
        scanf("%[^\n]",lastName);
        printf("Ingrese su sector\n");
        scanf("%d",&sector);
        while(sector<0)
        {
            printf("Ingrese un sector mayor a 0\n");
            scanf("%d",&sector);
        }
        printf("Ingrese su salario\n");
        scanf("%f",&salary);
        while(salary<0)
        {
            printf("Ingrese un salario mayor a 0\n");
            scanf("%f",&salary);
        }
        isEmpty=0;
    }
    else
    {
        printf("\nNO HAY MAS ESPACIO\n\n");
    }
    addEmployee(eEmployeeArray,name,lastName,salary,sector,isEmpty,id);

}
eEmployee addEmployee(eEmployee eEmployeeArray[],char nombre[],char apeliido[],float salario,int Asector,int AisEmpty,int Aid)
{
    strcpy(eEmployeeArray[Aid].name,nombre);
    strcpy(eEmployeeArray[Aid].lastName,apeliido);
    eEmployeeArray[Aid].salary=salario;
    eEmployeeArray[Aid].sector=Asector;
    eEmployeeArray[Aid].isEmpty=AisEmpty;
    eEmployeeArray[Aid].id=Aid;

    return eEmployeeArray[Aid];
}
void PrintEmployees(eEmployee elEmpleado[TAM],int cant)
{
    OrderBySector(elEmpleado,cant);
    int i;
    int bandera=0;
    float contador=0;
    int numeroEmpleados=0;
    int superaPromedio=0;
    float promedio=0;

    printf("\nORDENADO POR SECTOR!!\n");
    printf("   ID    NOMBRE   SECTOR\n");
    for(i=0;i<cant;i++)
    {
        if(elEmpleado[i].isEmpty==0&&elEmpleado[i].id!=-1)
        {
            printf("%4d%10s%4d\n",elEmpleado[i].id,elEmpleado[i].lastName,elEmpleado[i].sector);
            bandera=1;
        }
    }
    OrderByName(elEmpleado,cant);
    for(i=0;i<cant;i++)
    {
        if(elEmpleado[i].isEmpty==0&&elEmpleado[i].id!=-1)
        {
            contador+=elEmpleado[i].salary;
            numeroEmpleados++;
        }
    }
    promedio=contador/numeroEmpleados;
    for(i=0;i<cant;i++)
    {
        if(elEmpleado[i].isEmpty==0)
        {
            if(elEmpleado[i].salary>promedio)
            {
                superaPromedio++;
            }
        }
    }
    printf("el total de sueldos es %.2f, el promedio %.2f, y la cantidad que supera el promedio: %d \n",contador, promedio, superaPromedio);
    if(bandera==0)
    {
        printf("No hay empleados que mostrar");
    }
}
void OrderByName(eEmployee ordenarEmpleado[TAM],int cant)
{
    int i;
    int j;
    char auxString[64];
    int auxInt;
    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if((strcmp(ordenarEmpleado[i].lastName,ordenarEmpleado[j].lastName)>0)&&(ordenarEmpleado[i].isEmpty==0&&ordenarEmpleado[j].isEmpty==0))
            {
                strcpy(auxString,ordenarEmpleado[i].lastName);
                strcpy(ordenarEmpleado[i].lastName,ordenarEmpleado[j].lastName);
                strcpy(ordenarEmpleado[j].lastName,auxString);

                auxInt=ordenarEmpleado[i].sector;
                ordenarEmpleado[i].sector=ordenarEmpleado[j].sector;
                ordenarEmpleado[j].sector=auxInt;
            }
        }
    }
    printf("\nORDENADO POR APELLIDO!!\n");
    printf("   ID    NOMBRE   SECTOR\n");
    for(i=0;i<TAM;i++)
    {
        if((ordenarEmpleado[i].isEmpty==0)&&(ordenarEmpleado[i].id!=-1))
        {
            printf("%4d%10s%4d\n",ordenarEmpleado[i].id,ordenarEmpleado[i].lastName,ordenarEmpleado[i].sector);
        }
    }
}
void OrderBySector(eEmployee ordenarEmpleado[TAM],int cant)
{
    int i;
    int j;
    char auxString[64];
    int auxInt;
    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if((ordenarEmpleado[i].sector>ordenarEmpleado[j].sector)&&(ordenarEmpleado[i].isEmpty==0&&ordenarEmpleado[j].isEmpty==0))
            {
                strcpy(auxString,ordenarEmpleado[i].lastName);
                strcpy(ordenarEmpleado[i].lastName,ordenarEmpleado[j].lastName);
                strcpy(ordenarEmpleado[j].lastName,auxString);

                auxInt=ordenarEmpleado[i].sector;
                ordenarEmpleado[i].sector=ordenarEmpleado[j].sector;
                ordenarEmpleado[j].sector=auxInt;
            }
        }
    }
}
void InitEmployees(eEmployee iniEmpleado[],int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        iniEmpleado[i].id=-1;
        iniEmpleado[i].isEmpty=1;
    }
}
int SearchForFree(eEmployee libreEmployee[],int cant)
{
    int i;
    int haylibre=-1;

    for(i=1;i<cant;i++)
    {
        if(libreEmployee[i].id==-1&&libreEmployee[i].isEmpty!=0)
        {
            haylibre=i;
            libreEmployee[i].isEmpty=0;
            break;
        }
    }
    return haylibre;
}
void RemoveEmployee(eEmployee noEmpleado[TAM])
{
    int i;
    int eleccion;
    printf("   ID    NOMBRE   SECTOR\n");
    for(i=0;i<TAM;i++)
    {
        if(noEmpleado[i].id!=-1)
        {
            printf("%4d%10s%4d\n",noEmpleado[i].id,noEmpleado[i].lastName,noEmpleado[i].sector);
        }
    }
    printf("Elija el id del empleado a dar de baja");
    scanf("%d",&eleccion);
    for(i=0;i<TAM;i++)
    {
        if(noEmpleado[i].id==eleccion)
        {
            noEmpleado[i].id=-1;
            noEmpleado[i].isEmpty=1;
            noEmpleado[i].salary=0;
            noEmpleado[i].sector=-1;
        }
    }

}
void ModifyEmployee(eEmployee moEmpleado[TAM])
{
    int i;
    int eleccion;
    int menu;
    int encontrado;
    printf("   ID    NOMBRE   SECTOR\n");
    for(i=0;i<TAM;i++)
    {
        if(moEmpleado[i].id!=-1)
        {
            printf("%4d%10s%4d\n",moEmpleado[i].id,moEmpleado[i].lastName,moEmpleado[i].sector);
        }
    }
    printf("Elija el id del empleado a modificar\n");
    scanf("%d",&eleccion);
    encontrado=findEmployeeById(moEmpleado,eleccion);
    if(encontrado==1)
    {
        printf("Que va a modificar?\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                printf("Ingrese el nuevo nombre\n");
               fflush(stdin);
                scanf("%[^\n]",moEmpleado[eleccion].name);
                break;
            case 2:
                printf("Ingrese el nuevo Apellido\n");
               fflush(stdin);
                scanf("%[^\n]",moEmpleado[eleccion].lastName);
                break;
            case 3:
                printf("Ingrese el nuevo Salario\n");
                scanf("%f",&moEmpleado[eleccion].salary);
                break;
            case 4:
                printf("Ingrese el nuevo Sector\n");
                scanf("%d",&moEmpleado[eleccion].sector);
                break;
            default:
                printf("\nIntente con las opciones entre 1 y 4\n");
                break;
        }

    }
    else
    {
        printf("\nEse ID no coincide con ninguno en nuestro sistema, carge otro y reintente\n");

    }

}
void Menu(eEmployee eEmployeeArray[])
{
    int menu;
    int banderaCaseOne=0;

    do
    {
        printf("1.Aniadir Empleado\n2.Modificar Empleado\n3.Dar de baja\n4.Mostrar Empleados\n10.salir\n");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                LoadEmployees(eEmployeeArray,TAM);
                banderaCaseOne=1;
                break;
            case 2:
                if(banderaCaseOne==1)
                {
                    ModifyEmployee(eEmployeeArray);
                }
                else
                {
                 printf("\nDebe cargar algun empleado primero\n");
                }
                break;
            case 3:
                if(banderaCaseOne==1)
                {
                    RemoveEmployee(eEmployeeArray);
                }
                else
                {
                 printf("\nDebe cargar algun empleado primero\n");
                }
                break;
            case 4:
                if(banderaCaseOne==1)
                {
                    PrintEmployees(eEmployeeArray,TAM);
                    printf("\n");
                }
                else
                {
                 printf("\nDebe cargar algun empleado primero\n");
                }

                break;
        }
    }while(menu!=10);
}
int findEmployeeById(eEmployee idEmployee[],int idBuscada)
{
    int i;
    int encontrado=-1;
    for(i=0;i<TAM;i++)
    {
        if(idEmployee[i].id==idBuscada&&idEmployee[i].isEmpty==0)
        {
            encontrado=1;
            break;
        }
    }
    return encontrado;
}
