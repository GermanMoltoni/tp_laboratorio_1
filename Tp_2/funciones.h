#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * \param lista el array se pasa como parametro.
 * \param cantidad largo de array
 * \return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[],int cantidad);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * \param lista el array se pasa como parametro.
 * \param cantidad largo de array
 * \param dni el dni a ser buscado en el array.
 * \return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[],int cantidad, long int dni);

/**
 *  Valida dni entre 0 a 99.999.999
 * \param dni el dni a ser validado.
 * \return el dni validado
 *
 */
long int validarDni(long int dni);


/**
 *  Valida la edad  mayor a 0 y menor o igual a 100 años
 * \param edad la edad a validar
 * \return edad validada.
 *
 */
int validarEdad(int edad);

/**
 * Valida  el ingreso unico de dni
 * \param lista el array se pasa como parametro.
 * \param cantidad largo de array
 * \param dni el dni a verificar
 * \return dni validado
 *
 */
long int validarDupDni(ePersona lista[],int cantidad,long int dni);

/**
 * Muestra texto de menu, toma y valida opcion ingresada
 * \param textoMenu es el texto a mostrar con opciones
 * \param minOpcion esla opcion minima que se puede elegir
 * \param maxOpcion esla opcion maxima que se puede elegir
 * \return opcion validada.
 *
 */
int menu(char textoMenu[],int minOpcion,int maxOpcion);

/**
 * Valida que no se ingrese un espacio vacio en el nombre
 * \param nombre es el nombre a validar
 * \return
 *
 */
void validarNombre(char nombre[]);
/**
 *  Ingresa datos al array de estructura
 * \param lista es el array en donde se opera
 * \param cantidad es el largo del array.
 * \param nombre es la nombre de la persona a guardar
 * \param edad es la edad de la persona a guardar
 * \param dni es el dni de la persona a guardar
 *
 */
void ingresarPersona(ePersona lista[],int cantidad, char nombre[],int edad, long int dni);

/**
 * Obtengo array ordenado alfabeticamente
 * \param lista es el array a ordenar
 * \param cantidad es el largo del array
 *
 */

void ordenarNombres(ePersona lista[], int cantidad);
/**
 * Muestra el array de estructuras.
 * \param lista es el array a mostrar
 *
 */
void mostrarEstructura(ePersona lista);

/**
 * Pide y Verifica si se ingresa s o n
 * \param
 * \return caracter s o n
 *
 */

char validarCaracter();

/**
 * Realiza baja logica en estructura
 * \param lista es el array a operar
 * \param indice es la posicion dar de baja
 *
 */

void borrarPersona(ePersona lista[],int indice);

/**
 * realiza grafico de edades
 * \param lista es el array a graficar
 * \param cantidad son los elementos que componen la estructura
 *
 */

void graficar(ePersona lista[], int cantidad);

/**
 * Inicia el array con un estado, dni y edad con valores invalidos menores a cero
 * \param lista es el array a operar
 * \param cantidad es el largo del array
 *
 */
void iniciarArray(ePersona lista[], int cantidad);
#endif // FUNCIONES_H_INCLUDED
