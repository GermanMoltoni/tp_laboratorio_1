/***************************************************************************
 *
 * Programa: TP N°2 Array de estructuras
 * Objetivo:
                Ingresar los datos de 20 personas
                Dar baja por dni
                Mostrar lista de personas ordenadas alfabeticamente.
                Graficar edades.
 * Autor: German Moltoni
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define ELEMENTOS 20 // cantidad de personas a ingresar en el array de estructura

int main()
{
    char seguir='s';
    int opcion=0;
    char nombre[ELEMENTOS];
    int edad;
    long int dni;
    int minMenu= 1;// minima opcion que se puede ingresar en el menu
    int maxMenu = 5;//maxima opcion que se puede ingresar en el menu
    int aux;
    char textoMenu[]={"1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n5- Salir"};
    ePersona personas[ELEMENTOS];//array de estructura EPersona que contiene los datos de cada persona
    iniciarArray(personas,ELEMENTOS);//inicializa los datos del array con un estado 0 indicando la baja logica
    while(seguir=='s')
    {
       opcion=menu(textoMenu,minMenu,maxMenu);
       switch(opcion)
        {
            case 1:
                if( obtenerEspacioLibre(personas,ELEMENTOS) != -1)// si hay espacio libre para ingresar datos
                {
                    system("cls");
                    printf("*Carga de datos*\n");
                    printf("Ingresar Nombre:");
                    fflush(stdin);
                    gets(nombre);
                    validarNombre(nombre);
                    printf("\nIngrese Edad: ");
                    scanf("%d", &edad);
                    edad=validarEdad(edad);
                    printf("Ingrese DNI: ");
                    scanf("%ld",&dni);
                    dni=validarDni(dni);
                    dni=validarDupDni(personas,ELEMENTOS,dni); //valida que el dni ingresado no exista en el array con otro dado de alta
                    ingresarPersona(personas,ELEMENTOS,nombre,edad,dni);
                }
                else
                {
                    printf("\nNo hay mas espacio para guardar datos");
                }
                break;
            case 2:
                    system("cls");
                    printf("Eliminar Persona\n");
                    printf("Ingrese DNI: ");
                    scanf("%ld",&dni);
                    dni=validarDni(dni);
                    aux=buscarPorDni(personas,ELEMENTOS,dni);
                    if(aux >-1) // si existe el dni pregunto si deseo dar baja logica
                    {
                      mostrarEstructura(personas[aux]);
                      printf("Desea Eliminar la persona?");
                      if(validarCaracter() == 'S')
                         {
                             borrarPersona(personas,aux);
                             printf("\n");
                         }
                         else
                         {
                             printf("\nNo se elimino la persona\n");
                         }
                    }
                    else
                    {
                        printf("\n No se encontro el dni ingresado\n");
                    }
                break;
            case 3:
                    printf("Ordenar Alfabeticamente");
                    system("cls");
                    ordenarNombres(personas,ELEMENTOS);
                    for(aux=0;aux<ELEMENTOS;aux++)
                    {
                       mostrarEstructura(personas[aux]);
                    }
                break;
            case 4:
                    system("cls");
                    printf("Grafico de edades\n");
                    graficar(personas,ELEMENTOS);
                break;
            case 5:
                system("cls");
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}
