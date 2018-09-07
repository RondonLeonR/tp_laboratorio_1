#include <stdio.h>
#include <stdlib.h>


/** \brief Saco el factorial del numero ingresado como parametro
 *
 * \param fact float* La direccion donde guardo el resultado del factorial
 * \param number float Numero a sacar el factorial
 * \return int ---
 *
 */
int fun_factorial(float *fact,float number)
{
    int factor=1;

    for(int i=number ; i>=1;i--)
    {
        if(i>=1){
            factor=factor*i;
            }
    }
    *fact=factor;

    return 0;
}


/** \brief Sumo los dos numeros ingresados como parametro
 *
 * \param sum float* Direccion donde guardo el resultado
 * \param num1 float Primer numero recibido
 * \param num2 float Segundo numero recibido
 * \return int ---
 *
 */
int fun_Sumar(float *sum,float num1,float num2)
{

    *sum=num1+num2;
}

/** \brief Resto los dos numeros ingresados como parametros
 *
 * \param resta float* Direccion donde guardo el resultado
 * \param num1 float Primer parametro recibido
 * \param num2 float Segundo parametro recibido
 * \return int ---
 *
 */
int fun_Resta(float *resta,float num1,float num2)
{
    *resta=num1-num2;
}

/** \brief Divido los dos numeros recibidos como parametros
 *
 * \param div float* Direccion donde guardo el resultado
 * \param num1 float Primer parametro recibido
 * \param num2 float Segundo parametro recibido
 * \return int Devuelvo 1 si se pudo hacer la division, 0 si no.
 *
 */
int fun_Div(float *div,float num1,float num2)
{
    int ret=1;
    if(num2==0)
    {
        ret=0;
    }
    else
    {
        *div=num1/num2;
    }
    return ret;
}

/** \brief Multiplico los dos numero recibidos como parametros
 *
 * \param mult float* Direccion donde guardo el resultado
 * \param num1 float Primer parametro recibido
 * \param num2 float Segundo parametro recibido
 * \return int ---
 *
 */
int fun_Mult(float *mult,float num1,float num2)
{
    *mult=num1*num2;
}

/** \brief Pido un numero
 *
 * \param pResultado float* Direccion donde guardo el numero Ingresado
 * \param mensaje char* Mensaje a mostrar al usuario para pedir el numero
 * \param mensajeError char* Mensaje en caso de Error
 * \param minimo int El valor minimo que puede ingresar el usuario
 * \param maximo int El valor maximo que puede ingresar el usuario
 * \param reintentos int Los intentos que tiene para ingresar un numero
 * \return int Retorna 0 si el numero se cargo con exito
 *
 */
int fun_getNumber(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    float num;

    while(reintentos>0)
    {
        printf(mensaje);
        if(scanf("%f",&num)==1);
        {
            if(num<=maximo&&num>=minimo)
            {
                break;
            }
        }
        fflush(stdin);

        reintentos--;
        printf(mensajeError);
    }

    if(reintentos==0)
    {
        ret=1;
    }
    else
    {
        ret=0;
        *pResultado = num;
    }
    return ret;
}

/** \brief Primera Opcion del menu, Pido el primer numero usando otra funcion
 *
 * \param num1 float* Direccion donde guardo el primer numero
 * \return int ---
 *
 */
int fun_OpcOne(float *num1)
{
    int ret;
    float num;
    ret = fun_getNumber(&num,"Ingrese el 1er Operando: \n","Error. Numero NO valido\n",-1000,1000,3);
        if(ret==0)
        {
            printf("\n\tNumero Ingresado con Exito\n");
            *num1=num;
        }
        else{
            printf("\n\tERROR. Numero NO Ingresado\n\n");
        }
    system("pause");
    return 0;
}

/** \brief Segunda Opcion del menu, Pido el segundo numero usando otra funcion
 *
 * \param num2 float* Direccion donde guardo el segundo numero
 * \return int ---
 *
 */
int fun_OpcTwo(float *num2)
{
    int ret;
    float num;
    ret = fun_getNumber(&num,"Ingrese el 2do Operando: \n","Error. Numero NO valido\n",-1000,1000,3);
        if(ret==0)
        {
            printf("\n\tNumero Ingresado con Exito\n");
            *num2 = num;
        }
        else
        {
            printf("\n\tERROR. Numero NO Ingresado\n\n");
        }
        system("pause");
}

/** \brief Calculo TODAS las operaciones
 *
 * \param sum float* Direccion donde guardo el resultado
 * \param resta float* Direccion donde guardo el resultado
 * \param divi float* Direccion donde guardo el resultado
 * \param multi float* Direccion donde guardo el resultado
 * \param facto1 float* Direccion donde guardo el resultado
 * \param facto2 float* Direccion donde guardo el resultado
 * \param flagDiv int* La bandera devuelve 1 si se pudo hacer la Division, 0 si no
 * \param numOne float El primer numero Ingresado por el Usuario
 * \param numTwo float El segundo numero Ingresado por el Usuario
 * \return int ---
 *
 */
int fun_OpcThree(float *sum,float *resta,float *divi,float *multi,float *facto1,float *facto2,int *flagDiv,float numOne, float numTwo)
{
    float sumAux,restAux,divAux,multAux,factAuxOne,factAuxTwo;

    fun_Sumar(&sumAux,numOne,numTwo);
    *sum=sumAux;
    fun_Resta(&restAux,numOne,numTwo);
    *resta=restAux;
    *flagDiv=fun_Div(&divAux,numOne,numTwo);
    *divi=divAux;
    fun_Mult(&multAux,numOne,numTwo);
    *multi=multAux;
    fun_factorial(&factAuxOne,numOne);
    *facto1=factAuxOne;
    fun_factorial(&factAuxTwo,numTwo);
    *facto2=factAuxTwo;
    printf("\n\n\tOperaciones calculadas.\n\n");
    system("pause");
}

/** \brief Muestro TODOS los resultados de las operaciones
 *
 * \param sum float Direccion donde se encuentra el resultado
 * \param resta float Direccion donde se encuentra el resultado
 * \param divi float Direccion donde se encuentra el resultado
 * \param multi float Direccion donde se encuentra el resultado
 * \param facto1 float Direccion donde se encuentra el resultado
 * \param facto2 float Direccion donde se encuentra el resultado
 * \param flagDiv int Segun el valor de esta variable muestro el resultado de la division
 * \return int
 *
 */
int fun_OpcFour(float sum,float resta,float divi,float multi,float facto1,float facto2,int flagDiv)
{
    system("cls");

    printf("\n\t**********RESULTADOS**********");

    printf("\n\na) El resultado de A+B es: %.2f",sum);
    printf("\nb) El resultado de A-B es: %.2f",resta);
    if(flagDiv!=1)
    {
        printf("\nc) No es posible dividir por cero");
    }
    else
    {
       printf("\nc) El resultado de A/B es: %.2f",divi);
    }
    printf("\nd) El resultado de A*B es: %.2f",multi);
    printf("\ne) El factorial de A es: %.2f y El factorial de B es: %.2f\n\n",facto1,facto2);
    system("pause");
}




