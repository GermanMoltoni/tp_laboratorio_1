#include <stdio.h>
#include "funciones.h"

/** Cierra archivo
 *
 * \param pArch puntero a archivo
 * \return  flag 0 si hay error 1 si no lo hay
 *
 */

int cerrarArchivo(FILE *pArch)
{
    int flag=0;
    if(fclose(pArch) == 0)
        flag=1;
    return flag;
}

/** Carga los datos del archivo, si no lo encuentra inicializa la estructura y crea el archivo
 *
 * \param name es el nombre que recibe el archivo
 * \param movies es el array de estructuras que se va a guardar en el archivo creado o leer en el archivo existente
 * \param pArch es el puntero al archivo donde se guardaran datos
 * \return flag 0 si hay error 1 si no lo hubo
 *
 */


int cargarDesdeArchivo(char* name,EMovie* movies,int length)
{
    int flag=0;
    FILE* pArch;
    if(movies != NULL && name!=NULL && length>0)
    {
        if(!leerBin(name,movies,length,pArch))//LLama a leerBin para leer el archivo, si no existe pide crearlo
        {
            if(InitArrayMovies(movies,length))
            {
                if(cargarHaciaArchivo(name,movies,length,pArch))//Llama a la funcion que crea y carga los datos en el archivo binario
                    flag=1;
            }
            else
                printf("ERROR,no se pudo inicializar el array\n");
        }
        else
            flag=1;
    }
    return flag;
}

/** Carga estructura movie en archivo
 *
 * \param name es el nombre del archivo
 * \param movies es el array de estructuras a cargar en el archivo
 * \param length es la cantidad de peliculas contenidas en el array
 * \return 0 si hay error 1 si no lo hubo
 *
 */

int cargarHaciaArchivo(char* name,EMovie* movies,int length)
{
    FILE* pArch;
    int flag=0;
    pArch=fopen(name,"wb");
    if(movies != NULL && length>0)
    {
        if(pArch != NULL)
        {
            if(fwrite(movies,sizeof(EMovie),length,pArch) == length)
                flag=1;
            else
                printf("ERROR, no se pudo escribir el archivo\n");
        }

        if(!(pArch=cerrarArchivo(pArch)))
            printf("ERROR, no se pudo cerrar el archivo\n");
    }
    return flag;
}

/** Lee archivo binario y lo carga en una estructura movies
 *
* \param name es el nombre del archivo
 * \param movies es el array de estructuras donde se guardaran los datos que contiene el archivo
 * \param pArch es el puntero al archivo donde se leeran los datos
 * \return flag 0 si hay error 1 si no lo hay
 */

int leerBin(char* nombre,EMovie* movies,int length,FILE* pArch)
{
    int flag=0;
    if(movies != NULL && nombre!=NULL && length>0)
    {
        if((pArch=fopen(nombre,"rb")) != NULL)
        {
            if(fread(movies,sizeof(EMovie),length,pArch) == length)
                {
                    flag=1;
                    if(!(flag=cerrarArchivo(pArch)))
                        printf("ERROR, no se pudo cerrar el archivo\n");
                }
            else
                printf("El archivo no pudo ser leido\n");
        }
    }
    else
        printf("ERROR con los datos pasados\n");
    return flag;
}

/** Crea archivo html con datos de la estructura movie y dos bloques de archivos index1.html, index2.html
 *
 * \param name es el nombre que recibe el archivo html a generar
 * \param movies es el array de estructuras que contiene las peliculas
 * \param length es la cantidad de peliculas que contiene el array
 * \return 1 si hubo error, 0 si no lo hubo
 *
 */

int crearArchivoWeb(char* name,EMovie* movies,int length)
{
    FILE* pArch;
    FILE* pAux1;
    FILE* pAux2;
    long int i;
    int flag=1;
    strcat(name,".html");
    if(movies!=NULL && length >0)
    {
        pAux1 = fopen("index1.html", "r");
        pAux2 = fopen("index2.html", "r");
        if(pAux1 != NULL && pAux2 != NULL)
        {
            pArch = fopen(name, "w");
            if(pArch != NULL )
            {
                if(fileCopy(pAux1,pArch))
                {
                    for(i=0;i<length;i++)
                    {
                        if((movies+i)->state == 1)
                        {
                            fputs("\n\t\t\t<article class='col-md-4 article-intro'>\n\t\t\t\t<a href='#'>",pArch);
                            fprintf(pArch,"\n\t\t\t\t\t<img class='img-responsive img-rounded' src='%s' alt=''>",((movies+i)->linkImagen));
                            fprintf(pArch,"\n\t\t\t\t</a>\n\t\t\t\t<h3>\n\t\t\t\t\t<a href='#'>%s</a>\n\t\t\t\t</h3>\n",((movies+i)->titulo));
                            fprintf(pArch,"\t\t\t\t<ul>\n\t\t\t\t\t<li>Género:%s</li>\n\t\t\t\t\t<li>Puntaje:%d</li>\n\t\t\t\t\t<li>Duración:%d</li>\n\t\t\t\t</ul>\n",((movies+i)->genero),((movies+i)->puntaje),((movies+i)->duracion));
                            fprintf(pArch,"\t\t\t\t<p>%s</p>\n\t\t\t</article>\n",((movies+i)->descripcion));
                        }
                    }
                    if(fileCopy(pAux2,pArch))
                    {
                        if(!cerrarArchivo(pArch))
                            printf("No se cerro el archivo %s\n",name);
                        else
                            flag=0;
                    }
                }
             }
             else
                 printf("Ocurrio un error con el archivo %s",name);
        }
    }
    return flag;
}


/** Copia contenido de un achivo en otro,
 *
 * \param pAux es el puntero al archivo desde el que se copian los datos
 * \param pArch es el puntero al archivo al que se copian los datos
 * \return 1 si no hubo error, 0 si hubo
 *
 */

int fileCopy(FILE* pAux,FILE* pArch)
{
    char* auxText;
    long int length;
    int flag=0;
    if(pAux!= NULL && pArch != NULL)// verifico que no sean null los punteros a archivos
    {
        if(fseek(pAux,0L,SEEK_END) == 0)// me posiciono en el fin del archivo
        {
            length=ftell(pAux);// obtengo la cantidad bytes del archivo desde el comienzo a la posicion en la que se encuentra
            rewind(pAux);// me posiciono nuevamente en el comienzo de archivo
            auxText=(char*)malloc(length);//reservo espacio en memoria para los bytes leidos
            if(auxText != NULL)
            {
                while(!feof(pAux))//mientras no sea fin de archivo
                {
                    fgets(auxText,length,pAux);//guardo la cadena del archivo en auxText
                    fputs(auxText,pArch);//copio en Parch la cadena de Auxtext

                }
                if(cerrarArchivo(pAux))
                    flag=1;
            }
        }
    }
    return flag;
}


