#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "lib.h"
#include "archivos.h"
int menu(char* textoMenu);
void menuAltas(ArrayList* aviones,ArrayList* vuelos);
void menuModificaciones(ArrayList* aviones,ArrayList* vuelos);
void menuListar(ArrayList* aviones,ArrayList* vuelos);
#endif // FUNCIONES_H_INCLUDED


