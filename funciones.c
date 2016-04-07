
/** \brief Recibe dos numeros para realizar la suma de los mismos.
 *
 * \param x es el primer numero
 * \param y es el segundo numero
 * \return resultadoSuma El resultado de la suma de los numeros recibidos.
 *
 */

float sumar(float x, float y)
{
	float resultadoSuma;
	resultadoSuma = x + y;
	return resultadoSuma;
}
/** \brief  Recibe dos numeros para realizar la resta de los mismos.
 *
 * \param x es el primer numero
 * \param y es el segundo numero
 * \return resultadoResta El resultado de la resta de los numeros recibidos.
 *
 */

float restar(float x, float y)
{
	float resultadoResta;
	resultadoResta = x - y;
	return resultadoResta;
}
/** \brief Recibe dos numeros para realizar la division de los mismos.
 *
 * \param x es el primer numero
 * \param y es el segundo numero
 * \return resultadoDivision El resultado de la division de los numeros recibidos.
 *
 */

float dividir(float x, float y)
{
    float resultadoDivision;

    resultadoDivision= x / y;
    return resultadoDivision;
}
/** \brief Recibe dos numeros para realizar la multiplicarlos entre si.
 * \param x es el primer numero
 * \param y es el segundo numero
 * \return resultadoMultiplicacion El resultado de la multiplicacion de los numeros recibidos.
 *
 */

float multiplicar(float x, float y)
{
	float resultadoMultiplicacion;
	resultadoMultiplicacion = x * y;
	return resultadoMultiplicacion;
}
/** \brief Recibe un numero entero para realizar el factorial utilizando llamadas recursivas a la misma funcion.
 *
 * \param x es el numero al cual se le calcula el factorial.
 * \return resultadoFactorial Es el resultado del factorial de x.
 *
 */

long long int factorial(long long int x)
{
    long long int resultadoFactorial;
    if(!x)
    {
        return 1;
    }
    else
    {
        resultadoFactorial=x*factorial(x-1);
        return resultadoFactorial;
    }
}

/** \brief De acuerdo al dato faltante muestra el error cometido por el usuario.
 *
 * \param flagA bandera de dato x
 * \param flagB bandera de dato y
 * \return 1 si el dato es correcto
 * \return 0 si el dato es faltante o contiene un error
 *
 */



unsigned int validarIngreso(unsigned int flagA, unsigned int flagB)
{
    if(flagA && flagB )
    {
        return 1;
    }
    else if(!flagA && flagB)
    {
        printf("ERROR, Falta el numero A para poder operar\n");
        return 0;
    }
    else
    {
        if(flagA && !flagB)
        {
            printf("ERROR,Falta el numero B para poder operar\n");
            return 0;
        }
        else
        {
            printf("ERROR,Falta A y B para poder operar\n");
            return 0;
        }
    }

}
/** \brief Verifica el ingreso y tipo de dato en la variable x,debe contener un numero entero y mayor o igual a cero.
 *
 * \param x es el numero al que se le  realiza el factorial
 * \param flagA es la bandera que indica si se ingreso un dato o no.
 * \return 0 en el caso de que el numero no haya sido ingresado o no es entero.
 * \return 1 en el caso de que el numero sea entero mayor o igual a cero.
 *
 */

unsigned int validarFactorial(float x,unsigned int flagA)
{
    float rtdo;
    if(flagA)
    {
      rtdo = x -(int) x;
        if(rtdo!=0)
        {
            printf("ERROR,Se debe ingresar un numero entero para poder operar\n");
            return 0;
        }
        else
        {
        return 1;
        }
    }
    else
    {
        printf("ERROR, Falta ingresar A para poder Operar\n");
        return 0;
    }

}
