#include <stdio.h>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
int cerrarArchivo(FILE *pArch);
int cargarDesdeArchivo(char* name,EMovie* movies,int length);
int cargarHaciaArchivo(char* name,EMovie* movies,int length);
int leerBin(char* nombre,EMovie* movies,int length,FILE* pArch);
int crearArchivoWeb(char* name,EMovie* movies,int length);
int fileCopy(FILE* pAux,FILE* pArch)
#endif // FUNCIONES_H_INCLUDED
