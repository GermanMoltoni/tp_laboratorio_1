#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "ArrayList.h"
typedef struct{
    char matricula[20];
    char fabricante[40];
    char modelo[20];
    char empresa[40];
    int autonomia;
    int capacidadMax;
} eAvion;
typedef struct{
    char matriculaAvion[20];
    char origen[50];
    char destino[50];
    char estado[20];
    int idVuelo;
    int horaSalida;
    int minutosSalida;
    int horaLlegada;
    int minutosLlegada;
} eVuelo;

eAvion* altaAvion(ArrayList* aviones);
eVuelo* altaVuelo(ArrayList* aviones,ArrayList* vuelos);
int modificarAvion(ArrayList* aviones,ArrayList* vuelos);
int modificarVuelo(ArrayList* vuelos,ArrayList* aviones);
int buscarMatricula(ArrayList* aviones,char* matricula);
int buscarIdVuelo(ArrayList* vuelos,int idVuelo);
int bajaAvion(ArrayList* aviones,ArrayList* vuelos);
int reemplazarAvion(ArrayList* aviones,ArrayList* vuelos);
int eliminarVuelos(ArrayList* vuelos);
int eliminarAviones(ArrayList* aviones);
int comparaEstadoVuelos(void* vueloA,void* vueloB);
int comparaEmpresaAvion(void* avionA,void* avionB);
int comparaAutonomiaAvion(void* avionA,void* avionB);
void printVueloEmpresa(ArrayList* aviones,ArrayList* vuelos);
void listarSegunEstado(ArrayList* vuelos,ArrayList* aviones);
char* validarEstado(void);
int salir(ArrayList* vuelos,ArrayList* aviones);
void printArrayVuelos(ArrayList* vuelos,char* estado);
void printArrayAviones(ArrayList* aviones);
int verificarUsoAvion(ArrayList* vuelos,char* matricula,char*uso);
#endif // FUNCIONES_H_INCLUDED
