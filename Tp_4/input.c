#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"
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
    printf("%s", message);
    fflush(stdin);
    if(scanf("%d", &auxInt) == 1 && auxInt > lowLimit && auxInt < hiLimit)
    {
        *input = auxInt;
        flag = 0;
    }
    else
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
    char auxChar[hiLimit];
    int flag=-1;
    printf("%s", message);
    fflush(stdin);
    gets(auxChar);
    if(strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit )
    {
        strcpy(input, auxChar);
        flag=0;
    }
    else
        printf("%s\n", eMessage);
    return flag;
}

/**
* \brief Solicita hora en  cadena de caracteres al usuario, la convierte a entero y la valida
* \param *vuelo es el puntero a la estructura donde se guardaran los datos de la hora
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error

* \param op es la opcion de 1 horario de salida o  0 horario de llegada
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getHour(eVuelo* vuelo,char message[],char eMessage[],int op)
{
     char auxChar[50];
    int resp;
    int i;
    char input[20];
    char input2[20];
    printf("%s", message);
    fflush(stdin);
    resp = scanf("%s", auxChar);
    if(resp == 1 && strlen(auxChar) == 5)
    {
        for(i = 0; i<=strlen(auxChar); i++)
        {
            if(auxChar[i] != ':' && i <2)
            {
                input[i]=auxChar[i];
            }
            else if(i == 2)
                input[i]='\0';
           if(i>2)
            {
                input2[i-3]=auxChar[i];
            }
            else if(i == 5)
            {
                input2[i-2]='\0';
            }
        }
        if(atoi(input)>= 0 && atoi(input) <= 23)
            {
                if(op == 1)
                        vuelo->horaSalida=atoi(input);
                else
                    vuelo->horaLlegada=atoi(input);
                if(atoi(input2)>= 0 && atoi(input2) <= 59)
                    {
                        if(op == 1)
                             vuelo->minutosSalida=atoi(input2);
                        else
                            vuelo->minutosLlegada=atoi(input2);
                        return 0;
                    }
            }

    }
   printf("%s", eMessage);
        return -1;
}
