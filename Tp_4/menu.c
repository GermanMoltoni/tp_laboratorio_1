#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "ArrayList.h"
#include "lib.h"
#include "input.h"
#include "archivos.h"
/** Menu
 *
 * \param textoMenu es la cadena de caracteres de menu.
 * \return  opcion es la opcion elegida
 *
 */
int menu(char* textoMenu)
{
    int opcion;
    puts(textoMenu);
    printf("Ingrese Opcion: ");
    fflush(stdin);
    if(scanf("%d",&opcion) != 1)
        opcion=-1;
    return opcion;
}

/** Menu del altas de aviones y vuelos
 *
 * \param *aviones es el arraylist que contiene los punteros a los aviones
 * \param *vuelos es el arraylist que contiene los vuelos

 *
 */
void Altas(ArrayList* aviones,ArrayList* vuelos)
{
    int salida=-1;
    char textoMenu[]="1-Alta de Avion\n2-Alta de Vuelo\n3.Volver al menu principal";
    if(aviones != NULL && vuelos != NULL)
    {
        while(salida == -1)
        {
            switch(menu(textoMenu))
            {
                case 1:
                    system("cls");
                    //system("clear");
                    printf("******Alta de Avion******\n");
                    if(!aviones->add(aviones,altaAvion(aviones)))
                    {

                        if(!cargarHaciaArchivo(aviones,"aviones.bin"))
                            printf("El avion ha sido cargado correctamente\n");
                    }
                    else
                        printf("El avion no se ha cargado\n");

                    break;
                case 2:
                    system("cls");
                    //system("clear");
                    if(!aviones->isEmpty(aviones))
                    {
                        printf("******Alta de Vuelo******\n");
                        if(!vuelos->add(vuelos,altaVuelo(aviones,vuelos)))
                            {
                                if(!cargarHaciaArchivo(vuelos,"vuelos.bin"))
                                     printf("El vuelo ha sido cargado correctamente\n");
                            }
                        else
                            printf("No se pudo agregar el Vuelo\n");
                    }
                    else
                        printf("No hay aviones cargados\n");
                    break;
                case 3:
                    salida=0;
                    break;
                default:
                    printf("Opcion Incorrecta\n");
                    break;
            }
            system("pause");
            system("cls");
            //system("clear");
        }
    }
}
/** Menu de modificaciones de aviones y vuelos
 *
 * \param *aviones es el arraylist que contiene los punteros a los aviones
 * \param *vuelos es el arraylist que contiene los punteros a los vuelos
 *
 */
void Modificaciones(ArrayList* aviones,ArrayList* vuelos)
{
    int salida=-1;
    char textoMenu[]="1-Aviones\n2-Vuelos\n3-Volver al menu principal";
    if(aviones != NULL && vuelos != NULL)
    {
        while(salida == -1)
        {
            switch(menu(textoMenu))
            {
                case 1:
                    system("cls");
                    //system("clear");
                    printf("******Modificar Avion******\n");
                    if(!aviones->isEmpty(aviones))
                    {
                        switch(menu("1-Modificar Avion\n2-Reemplazar avion\n"))
                        {
                            case 1:
                                system("cls");
                                //system("clear");
                                if(!modificarAvion(aviones,vuelos))
                                    {
                                        if(!cargarHaciaArchivo(aviones,"aviones.bin"))
                                            printf("El avion ha sido modificado correctamente\n");

                                    }
                                else
                                    printf("El avion no fue modificado\n");
                                break;
                            case 2:
                                system("cls");
                                //system("clear");
                                if(!reemplazarAvion(aviones,vuelos))
                                {
                                    if(!cargarHaciaArchivo(aviones,"aviones.bin"))
                                         printf("El avion se reemplazo correctamente\n");
                                }
                                else
                                    printf("El avion no fue reemplazado\n");
                                break;
                        }
                    }
                    else
                        printf("No hay aviones cargados\n");
                    break;
                case 2:
                    printf("******Modificar Vuelo******\n");
                    system("cls");
                    //system("clear");
                    if(!aviones->isEmpty(aviones))
                    {
                        if(!vuelos->isEmpty(vuelos))
                        {
                            if(!modificarVuelo(vuelos,aviones))
                                {
                                    if(!cargarHaciaArchivo(vuelos,"vuelos.bin"))
                                        printf("El Vuelo ha sido modificado correctamente\n");
                                }
                            else
                                printf("El Vuelo no pudo ser modificado \n");
                        }
                        else
                           printf("Cargar Vuelos para operar\n");
                    }
                    else
                        printf("Cargar Aviones para operar\n");
                    break;
                case 3:
                    salida=0;
                    break;
                default:
                    printf("Opcion incorrecta\n");
                    break;
            }
            system("pause");
            system("cls");
        }
    }
}

/** Menu del bajas de aviones y vuelos ADD
 *
 * \param *aviones es el arraylist que contiene los punteros a los aviones
 * \param *vuelos es el arraylist que contiene los vuelos
 *
 */

void Bajas(ArrayList* aviones,ArrayList* vuelos)
{
    int salida=-1;
    char textoMenu[]="1-Eliminar Avion\n2- Cancelar Vuelo\n3-Eliminar todos los Vuelos\n4-Eliminar todos los Aviones\n5-Volver al menu principal";
    if(aviones != NULL && vuelos != NULL)
    {
        while(salida == -1)
        {
            switch(menu(textoMenu))
            {
                case 1:
                    system("cls");
                    //system("clear");
                    printf("******Baja de Avion******\n");
                    if(!vuelos->isEmpty(vuelos))
                    {
                        if(!bajaAvion(aviones,vuelos))
                        {
                            if(!cargarHaciaArchivo(aviones,"aviones.bin"))
                                printf("El avion ha sido borrado correctamente\n");
                        }

                    }
                    else
                    {
                        printf("Eliminar Vuelos para operar\n");
                    }
                    break;
                case 2:
                    system("cls");
                    //system("clear");
                    if(!vuelos->isEmpty(vuelos))
                    {
                         printf("******Baja de Vuelo******\n");
                         if(suspenderVuelo(vuelos) == -1)
                            printf("El vuelo no ha sido eliminado\n");
                        else
                            {
                                if(!cargarHaciaArchivo(vuelos,"vuelos.bin"))
                                     printf("El vuelo ha sido eliminado\n");
                            }

                    }
                    else
                        printf("No hay Vuelos cargados\n");
                    break;
                case 3:
                    system("cls");
                    if(!vuelos->isEmpty(vuelos))
                    {
                            if(!eliminarVuelos(vuelos))
                            {
                                if(!cargarHaciaArchivo(vuelos,"vuelos.bin"))
                                    printf("Todos los vuelos han sido eliminados\n");
                            }
                    }
                    else
                        printf("No hay vuelos cargados\n");
                    break;
                case 4:
                    system("cls");
                    if(vuelos->isEmpty(vuelos) && !aviones->isEmpty(aviones))
                    {
                        if(!eliminarAviones(aviones))
                        {
                            if(!cargarHaciaArchivo(aviones,"aviones.bin"))
                                printf("Todos los vuelos han sido eliminados\n");
                        }
                    }
                    else
                        printf("Eliminar Vuelos o cargar Aviones para poder operar\n ");
                        break;
                case 5:
                    salida=0;
                    break;
                default:
                    printf("Opcion Incorrecta\n");
                    break;
            }
        system("pause");
        system("cls");
            //system("clear");
        }

    }
}


/** Menu de Listados
 *
 * \param *vuelos es el arraylist que contiene el array de punteros a vuelo
 * \param *aviones es el arraylist que contiene el array de punteros a avion
 *
 */

void Listar(ArrayList* aviones,ArrayList* vuelos)
{
    char textoMenu[]="1-Aviones por Autonomia\n2-Vuelos por Empresa\n3-Vuelos por Estado";
    ArrayList* aux;
    if(aviones != NULL && vuelos != NULL)
    {
        switch(menu(textoMenu))
        {
            case 1:
                system("cls");
                printf("******Lista Nomina de aviones por Autonomia de Vuelo******\n");
                if(!aviones->isEmpty(aviones))
                {
                    aux=al_clone(aviones);
                    aux->sort(aux,comparaAutonomiaAvion,1);
                    printArrayAviones(aux);
                    al_deleteArrayList(aux);
                }
                else
                    printf("No hay aviones cargados\n");
                break;
            case 2:
                system("cls");
                if( !aviones->isEmpty(aviones) &&!vuelos->isEmpty(vuelos))
                {
                    printf("******Listar Nomina de Vuelos Por Empresa******\n");
                    aux=al_clone(aviones);
                    aux->sort(aux,comparaEmpresaAvion,0);
                    printVueloEmpresa(aux,vuelos);
                    al_deleteArrayList(aux);
                }
                else
                    printf("No hay Vuelos o aviones cargados\n");
                break;
            case 3:
                system("cls");
                if( !aviones->isEmpty(aviones) &&!vuelos->isEmpty(vuelos))
                {
                    printf("******Listar Nomina de Vuelos Por  Estado******\n");
                    aux=al_clone(vuelos);
                    aux->sort(aux,comparaEstadoVuelos,0);
                    listarSegunEstado(aux,aviones);
                }
                else
                    printf("No hay Vuelos o aviones cargados\n");

                break;
            default:
                printf("Opcion Incorrecta\n");
                break;
        }
        system("pause");
        system("cls");
        //system("clear")
    }
}
