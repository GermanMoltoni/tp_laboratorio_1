#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "ArrayList.h"
#include "menu.h"
#include "input.h"
#include "archivos.h"
/***************************************************************************
 *
 * Programa: TP N°4 Arraylist
 * Objetivo:
                Se realiza un ABM y listado de vuelos y aviones.
                - Agregar:
                            - Avion
                            - Vuelo
                - Modificar:
                            -Avion
                                    -Modificar datos
                                    -Reemplazar avion
                            -Vuelo
                -Baja:
                            -Avion
                            -Vuelo
                            -Todos los Vuelos
                            -Todos los Aviones
                -Listar:
                            -Aviones por Autonomia
                            -Vuelos por Empresa
                            -Vuelos por Estado

 * Autor: German Moltoni
 *
 */
int main(void)
{
    int salida=1;
    char textoMenu[]="1.ALTAS\n2.MODIFICACIONES\n3.BAJAS\n4.LISTAR\n5.SALIDA\n";
    ArrayList* vuelos=al_newArrayList();
    ArrayList* aviones=al_newArrayList();
    cargarDesdeArchivo(aviones,"aviones.bin");
    cargarDesdeArchivo(vuelos,"vuelos.bin");
    while(salida)
    {
          switch(menu(textoMenu))
         {
            case 1:
                system("cls");
                //system("clear");
                printf("ALTAS\n");
                Altas(aviones,vuelos);
                break;
            case 2:
                system("cls");
                //system("clear");
                printf("MODIFICACIONES\n");
                Modificaciones(aviones,vuelos);
                break;
            case 3:
                system("cls");
                //system("clear");
                printf("BAJAS\n");
                Bajas(aviones,vuelos);
                break;
            case 4:
                system("cls");
                //system("clear");
                printf("****LISTAR*****\n");
                Listar(aviones,vuelos);
                break;
            case 5:
                system("cls");
                //system("clear");
                salir(vuelos,aviones);
                salida=0;
                break;
            default:
                printf("Opcion Incorrecta\n");
        }
        system("cls");
    }
    return 0;
}
