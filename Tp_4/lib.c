#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "input.h"
#include "ArrayList.h"


/** Realiza  alta de un avion, solicita Matricula, Modelo, fabricante, capacidad maxima de pasajeros, autonomia de vuelo
 * \return  NULL si no se pudo agregar avion / *avion  puntero al avion creado
 */
eAvion* altaAvion(ArrayList* aviones)
{
    int salida=1;
    eAvion* avion=NULL;
    if(aviones != NULL)
    {
        avion=malloc(sizeof(eAvion));
        if(avion != NULL)
        {
            while(getString(avion->matricula,"Ingresar Matricula de Avion: ","ERROR",0,20)== -1);
            do
            {
                if(buscarMatricula(aviones,avion->matricula) == -1)
                    salida=0;
                else
                {
                    printf("Matricula Repetida\n");
                    while(getString(avion->matricula,"Ingresar Matricula de Avion: ","ERROR",0,20)== -1 );
                }
            }
            while(salida);
            while(getString(avion->modelo,"Ingresar Modelo de Avion: ","ERROR",0,20)== -1);
            while(getString(avion->fabricante,"Ingresar Fabricante de Avion: ","ERROR",0,40)== -1);
            while(getInt(&(avion->autonomia),"Ingresar Autonomia de vuelo(Km) : ","ERROR",0,65000)== -1);
            while(getString(avion->empresa,"Ingresar Empresa a la que pertenece el Avion: ","ERROR",0,40)== -1);
            while(getInt(&(avion->capacidadMax),"Ingresar Capacidad maxima de pasajeros: ","ERROR",1,700)== -1);
        }
    }
    return avion;
}

/** Alta de vuelo a partir de matricula de avion. Solicita horario de partida, llegada, origen, destido y estado del vuelo
 *
 * *aviones es el arraylist que contiene los punteros a los aviones
 * *vuelos es el arraylist que contiene los punteros a los vuelos
 * \return *vuelo es el puntero al vuelo cargado \ÊNULL error
 *
 */

eVuelo* altaVuelo(ArrayList* aviones,ArrayList* vuelos)
{
    char matricula[20];
    int salida=1;
    eVuelo* vuelo= NULL;
    while(getString(matricula,"Ingresar Matricula de Avion: ","ERROR",0,20)== -1);
    if(buscarMatricula(aviones,matricula)!= -1)
    {
        vuelo=malloc(sizeof(eVuelo));
        if(vuelo != NULL)
        {
             strcpy(vuelo->matriculaAvion,matricula);
             while(getInt(&(vuelo->idVuelo),"Ingresar Numero de Vuelo: ","ERROR",0,9999) == -1 );
             do
             {
                 if(buscarIdVuelo(vuelos,vuelo->idVuelo) == -1)// verifica si encuentra o no el numero de vuelo
                     salida=0;// no lo encontro
                 else
                 {
                     printf("Numero de Vuelo Repetido\n");
                     while(getInt(&(vuelo->idVuelo),"Ingresar Numero de Vuelo: ","ERROR",0,9999) == -1 );
                 }
             }
             while(salida);
             while(getString(vuelo->origen,"Ingresar Origen: ","ERROR",0,50) == -1);
             while(getString(vuelo->destino,"Ingresar Destino: ","ERROR",0,50)== -1);
             while(getHour(vuelo,"Ingrese Hora de Salida (HH:MM) : ","ERROR",1)== -1);
             while(getHour(vuelo,"Ingrese Hora de Llegada (HH:MM) : ","ERROR",0)== -1);
             strcpy(vuelo->estado,validarEstado());
        }
        else
            printf("No hay espacio para mas vuelos\n");
    }
    else
        printf("\nMatricula Invalida\n");
    return vuelo;
}

/** Modifica los datos del avion ingresando matricula
 * \param *aviones es el arraylist que contiene los punteros a los aviones
  * *vuelos es el arraylist que contiene los punteros a los vuelos
 * \return 0 ok -1 error
 */
int modificarAvion(ArrayList* aviones,ArrayList* vuelos)
{
    eAvion* avion;
    int retorno=-1;
    char matricula[20];
    if(aviones != NULL)
    {
        while(getString(matricula,"Ingresar Matricula de Avion: ","ERROR",0,20)== -1);

        avion=(eAvion*)aviones->get(aviones,buscarMatricula(aviones,matricula));
        if(avion != NULL)
        {
            if(verificarUsoAvion(vuelos,matricula,"Modificar")  == -1)
            {
                while(getString(avion->modelo,"Ingresar Modelo de Avion: ","ERROR",0,20)== -1);
                while(getString(avion->fabricante,"Ingresar Fabricante de Avion: ","ERROR",0,40)== -1);
                while(getInt(&(avion->autonomia),"Ingresar Autonomia de vuelo (Km) : ","ERROR",0,65000)== -1);
                while(getString(avion->empresa,"Ingresar Empresa a la que pertenece el Avion: ","ERROR",0,40)== -1);
                while(getInt(&(avion->capacidadMax),"Ingresar Capacidad maxima de pasajeros: ","ERROR",0,900)== -1);
                retorno=0;
            }

        }
        else
            printf("Matricula no encontrada\n");
    }
    return retorno;
}

/** Reemplaza un avion ingresando matricula con los datos de un nuevo avion. remove y push
 *
 * \param *aviones es el arraylist que contiene los punteros a los aviones
 * \param *vuelos es el arraylist que contiene los punteros a los vuelos
 * \return 0 ok -1 error
 *
 */

int reemplazarAvion(ArrayList* aviones,ArrayList* vuelos)
{
    int retorno=-1;
    int aux;
    char matricula[20];
    eAvion* avion;
    if(aviones != NULL && vuelos != NULL)
    {
        while(getString(matricula,"Ingresar Matricula : ","ERROR",0,20) == -1);
        aux=buscarMatricula(aviones,matricula);
         if(aux != -1)
        {
            if(verificarUsoAvion(vuelos,matricula,"Reemplazar") == -1)
            {
                avion=(eAvion*)aviones->get(aviones,retorno);
                printf("Matricula: %s\nModelo: %s\nFabricante: %s\nCapacidad Maxima de Pasajeros: %d\nAutonomia de Vuelo:%d\nEmpresa: %s \n\n",avion->matricula,avion->modelo,avion->fabricante,avion->capacidadMax,avion->autonomia,avion->empresa);
                printf("Avion Eliminado,Ingrese un nuevo Avion\n");
                strcpy(avion->matricula," ");
                if(!aviones->set(aviones,retorno,altaAvion(aviones)))
                    retorno=0;
            }
        }

        else
            printf("Matricula no encontrada\n");
    }
    return retorno;
}
/** Modifica datos del Vuelo Ingresando Nro de vuelo
 *
 * \param *vuelos es el arraylist que contiene el array de punteros a vuelo
 * \param *aviones es el arraylist que contiene el array de punteros a avion
 * \return  -1 error / 0 ok
 *
 */

int modificarVuelo(ArrayList* vuelos,ArrayList* aviones)
{
    int idVuelo,salida=1;
    eVuelo* vuelo;
    int retorno=-1;
    if(aviones != NULL && vuelos != NULL)
    {
        while(getInt(&idVuelo,"Ingresar Numero de Vuelo: ","ERROR",0,9999) == -1);
        idVuelo=buscarIdVuelo(vuelos,idVuelo);
        if( idVuelo != -1)
        {
            vuelo=vuelos->get(vuelos,idVuelo);
            if(vuelos != NULL)
            {
                while(getString(vuelo->origen,"Ingresar Origen: ","ERROR",0,50) == -1);
                while(getString(vuelo->destino,"Ingresar Destino: ","ERROR",0,50)== -1);
                while(getHour(vuelo,"Ingrese Hora de Salida (HH:MM) : ","ERROR",1)== -1);
                while(getHour(vuelo,"Ingrese Hora de Llegada (HH:MM) : ","ERROR",0)== -1);
                while(getString(vuelo->matriculaAvion,"Ingresar Matricula de Avion: ","ERROR",0,20)== -1);
                do
                {
                    if(buscarMatricula(aviones,vuelo->matriculaAvion) == -1)
                    {
                        printf("Ingrese matricula valida\n");
                        while(getString(vuelo->matriculaAvion,"Ingresar Matricula de Avion: ","ERROR",0,20)== -1 );
                    }
                    else
                        salida=0;
                }
                while(salida);
                strcpy(vuelo->estado,validarEstado());
                retorno=0;
            }
        }
        else
            printf("No se encontro numero de Vuelo\n");
    }
    return retorno;
}

//----------------------BUSQUEDA--------------------------
/** Busca la matricula  solicitada
 *
 * \param *aviones es el arraylist que contiene los punteros a aviones
 * \return -1 error / index del avion que contiene la matricula
 *
 */

int buscarMatricula(ArrayList* aviones,char* matricula)
{
    int i;
    int retorno=-1;
    eAvion* auxAvion;
    if(aviones != NULL)
    {
         for(i=0;i<aviones->len(aviones);i++)
         {
             auxAvion=(eAvion*)aviones->get(aviones,i);
             if(auxAvion != NULL)
             {
                 if(strcmp(matricula,auxAvion->matricula) == 0)
                 {
                     retorno=i;
                     break;
                 }
             }
         }
    }
    return retorno;
}

/** Busca un vuelo por numero de vuelo
 *
 * \param *aviones es el arraylist que contiene los punteros a los aviones
 * \param idVuelo es el numero de vuelo a buscar
 * \return -1 error / idVuelo es el index del vuelo buscado.
 *
 */

int buscarIdVuelo(ArrayList* vuelos,int idVuelo)
{
    eVuelo* vuelo;
    int i;
    int retorno=-1;
    if(vuelos != NULL)
    {
         for(i=0;i<vuelos->len(vuelos);i++)
         {
             vuelo=(eVuelo*)vuelos->get(vuelos,i);
             if(vuelo != NULL)
             {
                 if(idVuelo == vuelo->idVuelo)
                 {
                        retorno=vuelos->indexOf(vuelos,vuelo);
                         break;
                 }
             }
         }
    }
    return retorno;
}


//-------BAJAS----------------
/** Da de baja un avion y lo muestra
 *
 * \param *aviones es el arraylist que contiene el array de punteros a aviones
 * \param *vuelos es el arraylist que contiene el array de punteros a vuelo
 * \return -1 error / 0 Ok
 *
 */

int bajaAvion(ArrayList* aviones,ArrayList* vuelos)
{
    eAvion* avion;
    int retorno=-1;
    int index;
    int salida=1;
    char matricula[20];
    if(aviones != NULL )
    {
         while(getString(matricula,"Ingresar Matricula de Avion: ","ERROR",0,20)== -1 );
         do
         {
            index=buscarMatricula(aviones,matricula);
            if(index == -1)
            {
                printf("Ingrese matricula valida\n");
                while(getString(matricula,"Ingresar Matricula de Avion: ","ERROR",0,20)== -1 );
            }
            else
                salida=0;
        }
        while(salida);
        if(verificarUsoAvion(vuelos,matricula,"Eliminar") == -1)
        {
           avion=aviones->pop(aviones,index);
            printf("******Avion Eliminado******\n");
            printf("Matricula| %s\tModelo| %s\tFabricante| %s\tCapacidad Maxima de Pasajeros| %d\tAutonomia de Vuelo|%d\tEmpresa| %s \n\n",avion->matricula,avion->modelo,avion->fabricante,avion->capacidadMax,avion->autonomia,avion->empresa);
            retorno=0;
        }
    }
    return retorno;
}

/** Verifica si se utiliza la matricula de un avion en un vuelo
 *
 * \param *aviones es el arraylist que contiene el array de punteros a aviones
 * \param *vuelos es el arraylist que contiene el array de punteros a vuelo
 * \return -1 error / 0 Ok
 *
 */

int verificarUsoAvion(ArrayList* vuelos,char* matricula,char*uso)
{
    int aux=-1;
    int i;
    eVuelo* vuelo;
    if(vuelos!= NULL)
    {
        for(i=0;i<vuelos->len(vuelos);i++)
        {
            vuelo=(eVuelo*)vuelos->get(vuelos,i);
            if(strcmp(vuelo->matriculaAvion,matricula) == 0)
            {
                printf("Dar de Baja Vuelo %d para %s el Avion\n",vuelo->idVuelo,uso);
                aux=0;
            }
        }
    }
    return aux;
}



 /** Suspende un vuelo, lo elimina y , lo devuelve para ser mostrado VER POR QUE NO MUESTRA
 * \param  *vuelos es el arraylist que contiene el array de punteros a vuelo
 * \return -1 error 0 ok
 *
 */
int suspenderVuelo(ArrayList* vuelos)
{
    eVuelo* vuelo;
    int retorno=-1;
    int idVuelo;
    int salida=1;
    int index;
    if(vuelos != NULL)
    {
        while(getInt(&idVuelo,"Ingresar Numero de Vuelo: ","ERROR",0,9999) == -1 );
        do
        {
            index=buscarIdVuelo(vuelos,idVuelo);
            if(index != -1)
                {
                    salida=0;
                }
            else
            {
                printf("Numero de Vuelo No encontrado\n");
                while(getInt(&idVuelo,"Ingresar Numero de Vuelo: ","ERROR",0,9999) == -1 );
            }
        }
        while(salida);
        vuelo=(eVuelo*)vuelos->pop(vuelos,index);
        if(!vuelos->contains(vuelos,vuelo) )
        {
            printf("Numero de Vuelo| %d\nOrigen| %s\tPartida| %d:%d\nDestino| %s|\tLlegada| %d:%d\n",vuelo->idVuelo,vuelo->origen,vuelo->horaSalida,vuelo->minutosSalida,vuelo->destino,vuelo->horaLlegada,vuelo->minutosLlegada);
            printf("Estado| %s\n",vuelo->estado);
            printf("***********El vuelo se borro correctamente********\n");

            retorno=0;
        }
    }
    return retorno;
}

/** Elimina el contenido del array de vuelos
 *
 * \param *vuelos es el arraylist que contiene el array de punteros a vuelos
 * \return (0) Ok / (-1) error
 */

int eliminarVuelos(ArrayList* vuelos)
{
    if(vuelos != NULL)
    {
        vuelos->clear(vuelos);
        return 0;
    }
    return -1;
}
/** Elimina el contenido del array de aviones
 *
 * \param *aviones es el arraylist que contiene el array de punteros a aviones
 * \return (0) Ok / (-1) error
 */
int eliminarAviones(ArrayList* aviones)
{
    if(aviones != NULL)
    {
        aviones->clear(aviones);
        return 0;
    }
    return -1;
}


/** Compara el estado de los vuelos
 *
 * \param
 * \param
 * \return -1 si A<B / 1 si B<A / 0 si son iguales
 *
 */

int comparaEstadoVuelos(void* vueloA,void* vueloB)
{
    eVuelo* vA=(eVuelo*)vueloA;
    eVuelo* vB=(eVuelo*)vueloB;
    if(strcmp(vA->estado,vB->estado) < 0)
        return -1;
    if(strcmp(vA->estado,vB->estado) > 0)
        return 1;
    return 0;
}

/** Compara empresa de aviones
 *
 * \param *avionA es el puntero a un avion
 * \param *avionB es el puntero a un avion
 * \return -1 si A<B / 1 si B<A / 0 si son iguales
 *
 */

int comparaEmpresaAvion(void* avionA,void* avionB)
{
    eAvion* vA=(eAvion*)avionA;
    eAvion* vB=(eAvion*)avionB;
    if(strcmp(vA->empresa,vB->empresa) < 0)
        return -1;
    if(strcmp(vA->empresa,vB->empresa) > 0)
        return 1;
    return 0;
}


/** Compara la autonomía entre aviones
 *
 * \param *avionA es el puntero a un avion
 * \param *avionB es el puntero a un avion
 * \return -1 si A>B / 1 si B<A / 0 si son iguales
 *
 */

int comparaAutonomiaAvion(void* avionA,void* avionB)
{
    eAvion* vA=(eAvion*)avionA;
    eAvion* vB=(eAvion*)avionB;
    if(vA->autonomia<vB->autonomia)
        return -1;
    else if(vA->autonomia>vB->autonomia)
        return 1;
    return 0;
}


/** Imprime los punteros a AVIONES encontrados en el array del arraylist
 *
 * \param *aviones es el arraylist que contiene los punteros a los aviones
 *
 */

void printArrayAviones(ArrayList* aviones)
{
    int i;
    eAvion* avion;
    if(aviones!= NULL)
    {
        for(i=0;i<aviones->len(aviones);i++)
        {
            avion=(eAvion*)aviones->get(aviones,i);
            if(avion != NULL)
                printf("Matricula: %s\nModelo: %s\nFabricante: %s\nCapacidad Maxima de Pasajeros: %d\nAutonomia de Vuelo:%d\nEmpresa: %s \n\n",avion->matricula,avion->modelo,avion->fabricante,avion->capacidadMax,avion->autonomia,avion->empresa);
        }
    }
}

/** Imprime los punteros a vuelo encontrados en el array del arraylist
 *
 * \param *vuelos es el arraylist que contiene los punteros a los vuelos
 *
 */

void printArrayVuelos(ArrayList* vuelos,char* estado)
{
    int i;
    eVuelo* vuelo;
    if(vuelos!= NULL)
    {
        for(i=0;i<vuelos->len(vuelos);i++)
        {
            vuelo=(eVuelo*)vuelos->get(vuelos,i);
            if(vuelo != NULL)
               {
                    if(strcmp("ARRIVO",estado) == 0)
                        printf("Numero de Vuelo| %d\nOrigen| %s\tDestino| %s|\tLlegada| %d:%d\tEstado| %s\n",vuelo->idVuelo,vuelo->origen,vuelo->destino,vuelo->horaLlegada,vuelo->minutosLlegada,vuelo->estado);
                    else if(strcmp("PARTIDA",estado) == 0)
                        printf("Numero de Vuelo| %d\nOrigen| %s\tSalida| %d:%d\tDestino| %s|\tEstado| %s\n",vuelo->idVuelo,vuelo->origen,vuelo->horaSalida,vuelo->minutosSalida,vuelo->destino,vuelo->estado);
                    else if(strcmp("CANCELADO",estado) == 0 || strcmp("DEMORADO",estado) == 0)
                        printf("Numero de Vuelo| %d\nOrigen| %s\tDestino| %s|\tEstado| %s\n",vuelo->idVuelo,vuelo->origen,vuelo->destino,vuelo->estado);

               }
        }
    }
}

/** Imprime Las Empresas de los aviones junto a los datos del vuelo
 *
 * \param *vuelos es el arraylist que contiene los punteros a los vuelos
 * \param *aviones es el arraylist que contiene los punteros a los aviones
 *
 */

void printVueloEmpresa(ArrayList* aviones,ArrayList* vuelos)
{
    eVuelo* vuelo;
    eAvion* avion;
    int i,j;
    if(aviones != NULL && vuelos != NULL)
    {
        for(i=0;i<aviones->len(aviones);i++)
        {
            avion=(eAvion*)aviones->get(aviones,i);
            for(j=0;j<vuelos->len(vuelos);j++)
            {
                vuelo=(eVuelo*)vuelos->get(vuelos,j);
                if(strcmp(avion->matricula,vuelo->matriculaAvion) == 0)
                    printf("Empresa| %s\tNumero de Vuelo| %d\tAvion| %s\tOrigen| %s\t Salida| %d:%d\tDestino| %s Estado| %s\n",avion->empresa,vuelo->idVuelo,avion->modelo,vuelo->origen,vuelo->horaSalida,vuelo->minutosSalida,vuelo->destino,vuelo->estado);
            }
        }
    }
}



/** Realiza una sublista segun el estado ingresado
 *
 * \param *vuelos es el arraylist que contiene el array de punteros a vuelo
 * \return 0 Ok / -1 Error
 *
 */

void listarSegunEstado(ArrayList* vuelos,ArrayList* aviones)
{
    int from=-1;
    int to=0;
    ArrayList* aux;
    eVuelo* vuelo;
    char estado[20];
    int i,j;
    if(vuelos!= NULL)
    {
        strcpy(estado,validarEstado());
        for(i=0;i<=vuelos->len(vuelos);i++)
        {
            vuelo=(eVuelo*)al_get(vuelos,i);
            if(strcmp(vuelo->estado,estado) == 0)
            {
                from=i;
                break;
            }
        }
        if(from != -1)
        {
            for(j=from+1;j<=vuelos->len(vuelos);j++)
            {
                vuelo=(eVuelo*)al_get(vuelos,i);
                if( strcmp(vuelo->estado,estado) != 0 )
                {
                    to=j;
                    break;
                }
                else
                    to=i;
            }

            aux=vuelos->subList(vuelos,from,to);
            if(aux != NULL)
            {
                printArrayVuelos(aux,estado);
                al_deleteArrayList(aux);
            }
        }
        else
            printf("No hay aviones para el estado elegido\n");

    }
}


/** Solicita un estado y lo valida   ARRIVO - PARTIDA - CANCELADO- DEMORADO
 *
 * \return *estado  es el validado
 *
 */

char* validarEstado(void)
{
    char estado[20];
    int salida=1;
    while(getString(estado,"Ingresar Estado: ","ERROR",3,20)== -1 );
    do
    {
        strupr(estado);
        if(strcmp(estado,"ARRIVO") == 0)
            salida=0;
        else if(strcmp(estado,"PARTIDA") == 0)
            salida=0;
        else if(strcmp(estado,"DEMORADO") == 0)
            salida=0;
        else if(strcmp(estado,"CANCELADO") == 0)
            salida=0;
        else
        {
            printf("Ingrese un estado Correcto  -Arrivo-Partida-Cancelado-Demorado-\n");
            while(getString(estado,"Ingresar Estado: ","ERROR",3,20)== -1 );
        }
    }
    while(salida);
    return estado;
}


/** Libera la memoria ocupada por los arraylist pasados y los array de punteros contenidos en los mismos
 *
 * \param *vuelos es el arraylist que contiene el array de punteros a vuelo
 * \param *aviones es el arraylist que contiene el array de punteros a avion
 * \return
 *
 */

int salir(ArrayList* vuelos,ArrayList* aviones)
{
    int retorno=-1;
    int i;
    if(vuelos != NULL && aviones != NULL)
        {
            if(!al_deleteArrayList(aviones))
            {
                for(i=0;i<aviones->len(aviones);i++)
                    free(*((aviones->pElements)+1));
                for(i=0;i<vuelos->len(vuelos);i++)
                    free(*((vuelos->pElements)+1));
                printf("Libero Memoria de Elementos utilizados\n");
                printf("Arraylist de aviones eliminado\n");
                if(!al_deleteArrayList(vuelos))
                {
                    printf("Arraylist de vuelos eliminado\n");
                    retorno=0;
                }
            }
        }
    return retorno;
}









