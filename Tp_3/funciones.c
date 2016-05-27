#include "funciones.h"
#include <stdio.h>

/** Muestra texto de menu y pide una opcion
 *
 * \param textoMenu es el texto a mostrar
 * \return opcion es la opcion ingresada
 *
 */
int menu(char* textoMenu)
{
    int opcion;
    int test;
    puts(textoMenu);
    printf("Ingrese Opcion: ");
    fflush(stdin);
    test=scanf("%d",&opcion);
    if(test != 1)
        opcion=-1;
    return opcion;
}


/** Inicializa un array de peliculas con estado 0(sin ocupar)
 *
 * \param movies es el array de peliculas
 * \param length es la cantidad de peliculas del array
 * \return flag 0 si hubo error 1 si no lo hubo
 *
 */

int InitArrayMovies(EMovie* movies,int length)
{
    int i;
    int flag=0;
    if(movies != NULL && length>0)
    {
        for(i=0;i<length;i++)
            (movies+i)->state = 0;
        flag=1;
    }
    return flag;
}

/** Busca un lugar libre en el array de peliculas
 *
 * \param movies es el array de peliculas
 * \param length es la cantidad de peliculas del array
 * \return freeMovie -1 si no hay lugar o hay error.
 *
 */

int emptyMovie(EMovie* movies, int length)
{
    int i;
    int freeMovie = -1;
    if(movies != NULL && length>0)
    {
        for(i=0; i< length ; i++)
            {
                if((movies+i)->state == 0)
                {
                    freeMovie = i;
                    break;
                }
            }
    }
    return freeMovie;
}

/**
 * Busca una pelicula por titulo y si se encuentra activa
 * \param movies es el array de peliculas
 * \param length es la cantidad de peliculas del array
 * \param title es el titulo de la pelicula
 * \return movie -1 si hay error o no encontro la pelicula
 *
 */

int findByTitle(EMovie* movies,int length,char* title)
{
    int i;
    int movie=-1;
    if(movies != NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(strcmpi((movies+i)->titulo,title) == 0 && (movies+i)->state == 1)
               {
                   movie=i;
                   break;
               }
        }
    }
    return movie;
}


/** Agrega una pelicula al array de estructuras
 *
 * \param movies es el array de estructuras
 * \param length es la cantidad de componentes del array
 * \return flag 1 error, 0 sin error
 *
 */

int agregarPelicula(EMovie* movies,int length)
{
    char title[20];
    int free;
    int flag=1;
    EMovie movie;
    if(movies != NULL && length>0)
    {
        free=emptyMovie(movies,length);
        if(free>-1)
        {
            while(getString(title,"Ingrese Titulo de Pelicula: ","Ingrese un titulo valido",0,20) == -1);
            if(findByTitle(movies,length,title) == -1)
            {
                strcpy(movie.titulo,title);
                while(getString(movie.genero,"Ingrese Genero de Pelicula: ","Ingrese un Genero valido",0,20) == -1);
                while(getInt(&(movie.duracion),"Ingrese Duracion de Pelicula: ","Ingrese tiempo valido",0,300) == -1);
                while(getString(movie.descripcion,"Ingrese Descripcion de Pelicula: ","Ingrese una descripcion valida",0,240) == -1);
                while(getInt(&(movie.puntaje),"Ingrese Puntaje de Pelicula: ","Ingrese Puntaje de 0 a 10",0,11) == -1);
                while(getString(movie.linkImagen,"Ingrese Link de Imagen de Pelicula: ","Ingrese link valido",1,240) == -1);
                movie.state=1;
                if(!cargarEstructura(movies,free,movie,"Desea Cargar Pelicula?"))
                    flag=0;
            }
            else
            {
                printf("\nSe encontro una pelicula con el mismo nombre\n");
            }
        }
        else
            printf("\nNo hay mas lugar para guardar peliculas\n");
    }
    return flag;
}

/** Modifica una pelicula del array de estructuras
 *
 * \param movies es el array de estructuras
 * \param length es la cantidad de componentes del array
 * \return flag 1 error, 0 sin error
 *
 */


int modificarPelicula(EMovie* movies,int length)
{
    int free;
    int flag=1;
    char title[20];
    char genero[20];
    char descripcion[240];
    char linkImagen[240];
    int puntaje;
    int duracion;
    EMovie movie;
    if(movies != NULL && length>0)
    {
        while(getString(title,"Ingrese Titulo de Pelicula: ","Ingrese un titulo valido ",0,20) == -1);
        free=findByTitle(movies,length,title);
        if(free > -1)
        {
            while(getString(movie.titulo,"Ingrese Titulo de Pelicula: ","Ingrese un titulo valido ",0,20) == -1);
            while(getString(movie.genero,"Ingrese Genero de Pelicula: ","Ingrese un Genero valido",0,20) == -1);
            while(getInt(&movie.duracion,"Ingrese Duracion de Pelicula: ","Ingrese tiempo valido:",0,300) == -1);
            while(getString(movie.descripcion,"Ingrese Descripcion de Pelicula: ","Ingrese una descripcion valida",0,240) == -1);
            while(getInt(&movie.puntaje,"Ingrese Puntaje de Pelicula: ","Ingrese Puntaje de 0 a 10",0,11) == -1);
            while(getString(movie.linkImagen,"Ingrese Link de Imagen de Pelicula: ","Ingrese link valido",1,240) == -1);
            movie.state=1;
            if(!cargarEstructura(movies,free,movie,"Desea Modificar Pelicula?"))
                flag=0;
        }
    }
    return flag;
}


/** Borra una pelicula del array de estructuras
 *
 * \param movies es el array de estructuras
 * \param length es la cantidad de componentes del array
 * \return flag 1 error, 0 sin error
 *
 */
int borrarPelicula(EMovie* movies,int length)
{
    int flag=1;
    int i;
    char title[20];
    if(movies != NULL && length > 0)
    {
        while(getString(title,"Ingrese Titulo de Pelicula: ","Ingrese un titulo valido",0,20) == -1);
        i=findByTitle(movies,length,title);
        if(i>-1)
        {
            if(getChar("Desea Eliminar pelicula?",'s','n') == 's')
            {
               (movies+i)->state=0;
                flag=0;
            }

        }
        else
            printf("La pelicula no fue encontrada\n");
    }
    return flag;
}

/** Crea un archivo html a partir de los datos de las peliculas contenidas en la estructura
 *
 * \param movies es el array de estructuras
 * \param length es la cantidad de componentes del array
 * \param title es el nombre del archivo html
 * \return flag 1 error, 0 sin error
 *
 */

int generarPagina(EMovie* movies,int length,char* title)
{
    int i;
    int flag=1;
    if(movies != NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if((movies+i)->state == 1)
                printf("Titulo:%s\nGenero:%s\nDuracion:%d\nDescripcion:%s\nPuntaje:%d\nLink de Imagen:%s\n\n",((movies+i)->titulo),((movies+i)->genero),((movies+i)->duracion),((movies+i)->descripcion),((movies+i)->puntaje),((movies+i)->linkImagen));
        }
        if(!crearArchivoWeb(title,movies,length))
            flag=0;
    }
    return flag;
}

/** Verifica si alguna de las peliculas del array está activa
 *
 * \param movies es el array de peliculas
 * \param length es la cantidad de peliculas del array
 * \return 0 si no hay peliculas activas, 1 si lo hay
 *
 */

int occupatedMovie(EMovie* movies,int length)
{
    int flag=0;
    int i;
    if(movies != NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if((movies+i)->state == 1)
            {
                flag=1;
                break;
            }
        }
    }
    return flag;
}


/** Carga los datos ingresados en el array de peliculas
 *
 * \param movies es el array de estructuras
 * \param free es la posicion del array donde se guardara la estructura ingresada
 * \param movie es la estructura a cargar
 * \param string es el texto que se muestra para validar el caracter
 * \return 1 si no se realizo la carga 0 si se realizo correctamente la carga
 *
 */

int cargarEstructura(EMovie* movies, int free,EMovie movie,char* string)
{
    int flag=1;
    if(movies!= NULL && free > -1)
    {
       if(getChar(string,'s','n') == 's')
       {
            *(movies+free)=movie;
            flag=0;
       }
    }
    return flag;
}
