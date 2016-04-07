/***************************************************************************
 *
 * Programa: TP N°1 Calculadora
 * Objetivo:
                Ingresar dos datos, A y B, a partir de un menu de opciones
                se elige la operación deseada.El usuario será alertado si introduce un dato erroneo.
 * Autor: German Moltoni
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float x; // numero A
    float y; // numero B
    unsigned short int flagA=0; // Bnadera de ingreso variable x
    unsigned short int flagB=0; // Bandera de ingreso variable y
    float resultado; //recibe el resultado de la operacion realizada
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("Ingrese la opcion-->");
        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
            case 1:
                printf("Ingrese Un numero A: ");
                scanf("%f",&x); //Se ingresa numero A en x
                flagA=1; // Bandera A de ingreso de dato en 1
                break;
            case 2:
                printf("Ingrese Un numero B: ");
                scanf("%f",&y);//Se ingresa numero B en x
                flagB=1; // Bandera B de ingreso de dato en 1
                break;
            case 3:
                if(validarIngreso(flagA,flagB))
                {
                    printf("La suma de A+B es:%.2f\n",sumar(x,y));
                }
                break;
            case 4:
                if(validarIngreso(flagA,flagB))
                {
                    printf("La resta de A-B es:%.2f\n",restar(x,y));
                }
                break;
            case 5:
                if(validarIngreso(flagA,flagB))
                {
                    if( y != 0 )    //Se verifica que el dividendo sea diferente de cero
                    {
                        printf("La Division de A/B es:%.2f\n",dividir(x,y));
                    }
                    else
                    {
                        printf("ERROR, B tiene que ser distinto de 0\n");
                    }
                }
                break;
            case 6:
                if(validarIngreso(flagA,flagB))
                {
                    printf("La Division de A*B es:%.2f\n",multiplicar(x,y));
                }
                break;
            case 7:
                if(validarFactorial(x,flagA))//verifica si el dato ingresado es correcto
                {
                    printf("El Factorial de  %.0f! es:  %ld\n",x,factorial(x));
                }
                break;
            case 8:
                if(flagA) //Si se encuentra el dato A ingresado
                {
                    if(validarFactorial(x,flagA)) //Verifica si el dato ingresado es correcto
                    {
                       printf("El Factorial de  %.0f! es:  %lld\n",x,factorial(x));

                    }
                }

                if(validarIngreso(flagA,flagB))
                {
                    printf("La suma de A+B es:%.2f\n",sumar(x,y));
                    printf("La resta de A-B es:%.2f\n",restar(x,y));
                    if( y != 0 )
                    {
                        printf("La Division de A/B es:%.2f\n",dividir(x,y));
                    }
                    else
                    {
                        printf("ERROR, B tiene que ser distinto de 0\n");

                    }
                printf("La Division de A*B es:%.2f\n",multiplicar(x,y));
                }

                break;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("La opcion ingresada no es correcta\n");
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
