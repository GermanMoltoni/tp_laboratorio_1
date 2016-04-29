#include "funciones.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void iniciarArray(ePersona lista[], int cantidad)
{
    int i;
    for(i = 0; i< cantidad; i++)
        {
            lista[i].estado=0;
            lista[i].dni=-1;
            lista[i].edad=0;
        }
}

int menu(char textoMenu[],int minOpcion,int maxOpcion)
{
    int opcion;
    puts(textoMenu);
    printf("Ingrese Opcion--> ");
    scanf("%d",&opcion);
    while(opcion<minOpcion || opcion>maxOpcion)
    {
        printf("\nERROR,reingrese Opcion correcta: ");
        scanf("%d",&opcion);
    }
    return opcion;
}

void validarNombre(char nombre[])
{
    while(strlen(nombre) == 0)
    {
        printf("ERROR,reingrese Nombre: ");
        fflush(stdin);
        gets(nombre);
    }
}

int validarEdad(int edad)
{
    while(edad >100 || edad < 0)
        {
            printf("\nERROR,reingrese edad: ");
            scanf("%d",&edad);
        }
    return edad;
}

long int validarDni (long int dni)
{
    while(dni > 99999999 || dni <0)
        {
            printf("\nERROR,reingrese dni:  ");
            scanf("%ld",&dni);
        }
    return dni;
}
int buscarPorDni(ePersona plista[],int cantidad, long int dni)
{
    int i;
    long int indiceDni = -1;
    for(i=0; i< cantidad ; i++)
        {
            if(plista[i].dni == dni && plista[i].estado == 1)
            {
                indiceDni = i;
                break;
            }
        }
    return indiceDni;
}

long int validarDupDni(ePersona lista[],int cantidad,long int dni)
{
   while(buscarPorDni(lista,cantidad,dni) >=0)
    {
        printf("\nEl dni ya fue ingresado");
        dni=validarDni(-1);
    }
    return dni;
}

int obtenerEspacioLibre(ePersona lista[], int cantidad)
{
    int i;
    int libre = -1;
    for(i=0; i< cantidad ; i++)
        {
            if(lista[i].estado == 0)
            {
                libre = i;
                break;
            }
        }
    return libre;
}

void ingresarPersona(ePersona lista[],int cantidad, char nombre[],int edad, long int dni)
{
    int libre;
    libre=obtenerEspacioLibre(lista,cantidad);
    strcpy(lista[libre].nombre,nombre);
    lista[libre].edad=edad;
    lista[libre].dni=dni;
    lista[libre].estado=1;
}

char validarCaracter()
{
    char caracter='n';
    printf("\t S/N: ");
    caracter=getche();
    caracter=toupper(caracter);
    while(!((caracter == 'S') || (caracter == 'N')))
    {
        printf("\nERROR,Ingrese S o N: ");
        caracter=getche();
        caracter=toupper(caracter);
    }
    return caracter;
}
void borrarPersona(ePersona lista[],int indice)
{
    if(lista[indice].estado == 1)
        lista[indice].estado=0;
}
void ordenarNombres(ePersona lista[],int cantidad)
{
    int i;
    int j;
    ePersona auxPersona;
    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)> 0)
            {
                auxPersona=lista[j];
                lista[j]=lista[i];
                lista[i]=auxPersona;
            }

        }
    }
}

void mostrarEstructura(ePersona lista)
{
    if(lista.estado == 1)
        printf("\nNombre: %s\tEdad: %d\tDni: %ld\n",lista.nombre,lista.edad,lista.dni);
}

void graficar(ePersona lista[], int cantidad)
{
    int i;
    int edad18=0;
    int edad19a35=0;
    int edadMay35=0;
    int array18[cantidad];
    int array19a35[cantidad];
    int arrayMay35[cantidad];
    for(i=0; i<cantidad;i++)
    {
        array18[i]= 0;
        array19a35[i]= 0;
        arrayMay35[i]= 0;
    }

    for(i=0; i<cantidad;i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad>0 && lista[i].edad <= 18)
                array18[edad18++]='*';
            if(lista[i].edad >= 19 && lista[i].edad<= 35)
                array19a35[edad19a35++]='*';
            if(lista[i].edad > 35 && lista[i].edad<=100)
                arrayMay35[edadMay35++]='*';
        }

    }
    for(i=cantidad-1;i>=0;i--)
    {
        if(array18[i] != 0 || array19a35[i] != 0 || arrayMay35[i] != 0 )
            printf("%d|\t%c\t%c\t%c\n",i+1,array18[i],array19a35[i],arrayMay35[i]);
    }
    printf("\t18\t19-35\t>35\n");

}

