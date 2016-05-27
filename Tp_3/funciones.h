#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    unsigned char descripcion[240];
    int puntaje;
    char linkImagen[240];
    int state;
}EMovie;
int menu(char* textoMenu);
int InitArrayMovies(EMovie* movies,int length);
int emptyMovie(EMovie* movies, int length);
int findByTitle(EMovie* movies,int length,char* title);
int agregarPelicula(EMovie* movies,int length);
int modificarPelicula(EMovie* movies,int length);
int borrarPelicula(EMovie* movies,int length);
int generarPagina(EMovie* movies,int length,char* title);
int occupatedMovie(EMovie* movies,int length);
int cargarEstructura(EMovie* movies, int free,EMovie movie,char* string);
#endif // FUNCIONES_H_INCLUDED
