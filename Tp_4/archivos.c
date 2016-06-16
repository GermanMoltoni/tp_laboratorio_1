#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "ArrayList.h"
#include "menu.h"

#include <string.h>
/** Cierra el archivo
 *
 * \param *aux es el arraylist donde se cargaran los datos leidos
 * \param *nombre es el puntero al nombre del archivo
 *  \return -1 ERROR / 0 OK
 */
int cerrarArchivo(FILE *pArch)
{
    int flag=0;
    if(fclose(pArch) == 0)
        flag=1;
    return flag;
}

/** Carga los datos al archivo
 *
 * \param *aux es el arraylist donde se leeran los datos a cargar en el archivo
 * \param *nombre es el puntero al nombre del archivo
 *  \return -1 ERROR / 0 OK
 */

int cargarHaciaArchivo(ArrayList* aux,char *nombre)
{
    FILE* pArch;
    int i;
    int cont=0;
    long int tamanio;
    int flag=-1;
    pArch=fopen(nombre,"wb");
    if(aux != NULL)
    {
        if(pArch != NULL)
        {
            if(strcmp("aviones.bin",nombre) == 0)
                    tamanio=sizeof(eAvion);
            else if(strcmp("vuelos.bin",nombre) == 0)
                    tamanio=sizeof(eVuelo);
            for(i=0;i<al_len(aux);i++)
            {
                if(fwrite(*(aux->pElements +i),tamanio,1,pArch) == 1)
                        cont++;
                    else
                      printf("ERROR, no se pudo escribir el archivo\n");
            }
        }
        if(!(pArch=cerrarArchivo(pArch)))
            printf("ERROR, no se pudo cerrar el archivo\n");
        else if(cont != al_len(aux))
            printf("No se cargaron todos los datos");
        else
            flag=0;
    }

    return flag;
}



/** Carga los datos desde el archivo
 *
 * \param *aux es el arraylist donde se cargaran los datos leidos
 * \param *nombre es el puntero al nombre del archivo
 *  \return -1 ERROR / 0 OK
 */
int cargarDesdeArchivo(ArrayList* aux,char* nombre)
{
    int flag=-1;
    eAvion* avion;
    eVuelo* vuelo;
    int length,i;
    FILE* pArch;
    if(aux != NULL)
    {
        if((pArch=fopen(nombre,"rb")) != NULL)
        {
            if(fseek(pArch,0L,SEEK_END) == 0)// me posiciono en el fin del archivo
            {
                length=ftell(pArch);// obtengo la cantidad bytes del archivo desde el comienzo a la posicion en la que se encuentra
                rewind(pArch);// me posiciono nuevamente en el comienzo de archivo
                if(length != 0)
                {
                    if(strcmp("aviones.bin",nombre) == 0)
                    {
                        length=length/sizeof(eAvion);
                        avion=(eAvion*)malloc(sizeof(eAvion)*length);
                        while(!feof(pArch))//mientras no sea fin de archivo
                        {
                            if(fread(avion,sizeof(eAvion),length,pArch) != length)
                                {
                                    if(!feof(pArch))
                                        break;
                                }
                        }
                        if(cerrarArchivo(pArch))
                        {
                            for(i=0;i<length;i++)
                                al_add(aux,avion+i);
                            flag=1;
                        }
                    }
                    else if(strcmp("vuelos.bin",nombre) == 0)
                    {
                        length=length/sizeof(eVuelo);
                        vuelo=(eVuelo*)malloc(sizeof(eVuelo)*length);
                        while(!feof(pArch))//mientras no sea fin de archivo
                        {
                            if(fread(vuelo,sizeof(eVuelo),length,pArch) != length)
                                {
                                    if(!feof(pArch))
                                        break;
                                }
                        }
                        if(cerrarArchivo(pArch))
                        {
                            for(i=0;i<length;i++)
                                al_add(aux,vuelo+i);
                            flag=0;
                        }
                    }
                }

            }
        }
        else
        {
            cerrarArchivo(pArch);
            pArch=fopen(nombre,"wb");
            if(aux != NULL)
                cerrarArchivo(pArch);

        }

    }
    else
        printf("ERROR con los datos pasados\n");
    return flag;
}
