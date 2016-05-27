#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char* message,char* eMessage, int lowLimit, int hiLimit)
{
    int auxInt;
    int flag = -1;
    int test;
    printf("%s", message);
    fflush(stdin);
    test = scanf("%d", &auxInt);
    if(test == 1 && auxInt > lowLimit && auxInt < hiLimit)
    {
        *input = auxInt;
        flag = 0;
    }
    if(flag == -1)
        printf("%s\n", eMessage);
    return flag;
}

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char* message,char* eMessage, int lowLimit, int hiLimit)
{
    int resp;
    char auxChar[hiLimit];
    int flag=-1;
    printf("%s", message);
    fflush(stdin);
    gets(auxChar);
    if((strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit ) )
    {
        strcpy(input, auxChar);
        flag=0;
    }
    else
        printf("%s\n", eMessage);
    return flag;
}

/**
* \brief Solicita un caracter y lo valida
* \param text es el texto a mostrar
* \param char1 caracter 1 a evaluar
* \param char2 caracter 2 a evaluar
* \return caracter es el caracter validado
*
*/
char getChar(char* text,char ch1, char ch2)
{
    printf("%s S/N: ",text);
    char caracter;
    int test;
    test=scanf("%c",&caracter);
    while( test == 0 || !((caracter == ch1) || (caracter == ch2)))
    {
        printf("\nERROR,Ingrese S o N: ");
        test=scanf("%c",&caracter);
    }
    return caracter;
}
