/***************************************************************************
 *
 * Programa: TP N°3 Archivos
 * Objetivo:
                Se realiza un ABM utilizando el array de peliculas cargado previamente de un archivo binario generado o leido
                y se puede generar una pagina web para visualizar las peliculas.
 * Autor: German Moltoni
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "archivos.h"
#define P 50 // cantidad de peliculas maxima

int main()
{
    EMovie peliculas[P]; //array de peliculas
    char seguir='s';
    int flag=0;
    char nombreBin[]="peliculas.bin";//nombre de archivo binario
    char title[20];
    char textoMenu[]="1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar Pelicula\n4- Generar pagina web\n5- Salir";
    if(cargarDesdeArchivo(nombreBin,peliculas,P))//Si los datos pasados a la funcion son correctos.
    {
        while(seguir=='s')
        {
            //system("cls");
            switch(menu(textoMenu))
            {
                case 1:
                    if(agregarPelicula(peliculas,P))
                        printf("No se ha cargado la pelicula\n");
                    else
                    {
                        printf("La pelicula se agrego correctamente\n");
                        flag=1;
                    }
                    break;
                case 2:
                    if(occupatedMovie(peliculas,P)) // Verifica si hay alguna pelicula cargada para poder borrar
                    {
                        if(borrarPelicula(peliculas,P))
                          printf("La pelicula no se pudo borrar\n");
                        else
                        {
                            printf("La pelicula se borro con exito\n");
                            flag=1;
                        }
                    }
                    else
                        printf("No hay peliculas cargadas para operar\n");
                    break;
                case 3:
                    if(occupatedMovie(peliculas,P))// Verifica si hay alguna pelicula cargada para poder modificar
                    {
                        if(modificarPelicula(peliculas,P))
                            printf("No se ha modificado la pelicula\n");
                         else
                         {
                             printf("La pelicula se modifico correctamente\n");
                             flag=1;
                         }
                    }
                    else
                        printf("No hay peliculas cargadas para operar\n");
                   break;
                case 4:
                    if(occupatedMovie(peliculas,P)) // Verifica si hay alguna pelicula cargada para poder generar la pagina web
                    {
                        while(getString(title,"Nombre de archivo web: ","\nIngrese un nombre Valido: ",0,20) == -1);
                        if(generarPagina(peliculas,P,title))
                            printf("No se ha generado la pagina\n");
                         else
                            printf("La pagina se genero correctamente\n");
                    }
                    else
                        printf("No hay peliculas cargadas para operar\n");
                    break;
                case 5:
                    seguir = 'n';
                    flag=1;
                    break;
                default:
                    printf("Ingrese una opcion correcta\n ");
                    break;
            }
            system("pause");
            system("cls");
            if(flag == 1 && cargarHaciaArchivo(nombreBin,peliculas,P) == 1)// si el flag = 1 y se puede realizar la carga del array en el archivo
                flag=0;
        }
    }
    else
        printf("No se pudo leer ni crear el archivo\n");
    return 0;
}
