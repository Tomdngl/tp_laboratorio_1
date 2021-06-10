#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getString(char* cadena, int longitud);
static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esFlotante(char* cadena, int limite);
static int getFloat(float* pResultado);
static int esNombre(char* cadena,int longitud);
static int getNombre(char* pResultado,int longitud);

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un maximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */

static int getString(char* cadena, int longitud)
{
	int rtn=-1;
	char bufferString[4096]; //MEJORAR CUANDO APRENDA MEMORIA DINAMICA

	if(cadena != NULL && longitud>0){
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1]=='\n')
			{
			bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= longitud){
				strncpy(cadena, bufferString, longitud);
				rtn=0;
			}
		}
	}
	return rtn;
}


/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{
    int rtn=-1;
    char bufferString[64]; //MEJORAR CON MEMORIA DINAMICA
    if(pResultado != NULL &&
    		!getString(bufferString, sizeof bufferString) &&
			esNumerica(bufferString, sizeof(bufferString))){
    		rtn = 0;
    		*pResultado = atoi(bufferString);
    	}
    return rtn;
    }

/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(!getString(buffer,sizeof(buffer)) &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int rtn=-1;
    char bufferString[64]; //MEJORAR CON MEMORIA DINAMICA
    if(pResultado != NULL &&
    		!getString(bufferString, sizeof bufferString) &&
			esFlotante(bufferString, sizeof(bufferString))){
    		rtn = 0;
    		*pResultado = atof(bufferString);
    	}
    return rtn;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int rtn = 1;
	int i;
	for(i=0;i<limite && cadena[i] != '\0';i++){
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-')){
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			rtn=0;
			break;
		}
	}

	return rtn;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena, int limite)
{
	int rtn = 1;
		int i;
		for(i=0;i<limite && cadena[i] != '\0';i++){
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}
			if((cadena[i] > '9' || cadena[i] < '0') && cadena[i]!='.')
			{
				rtn=0;
				break;
			}
		}
		return rtn;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int rtn = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++){
			if(i==0 && (cadena[i] == ' ')){
				rtn = 0;
				break;
		}
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && cadena[i]!=' ')
			{
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int rtn = -1;
	int bufferInt;

	do{
		printf("%s", mensaje);
		if(!getInt(&bufferInt) &&
				bufferInt >= minimo &&
				bufferInt <= maximo){
			*pResultado=bufferInt;
			rtn=0;
			break;
		}
		printf("%s", mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return rtn;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int rtn = -1;
	float bufferFloat;

	do{
		printf("%s", mensaje);
		if(!getFloat(&bufferFloat)&&
				bufferFloat>=minimo &&
				bufferFloat<=maximo){
			*pResultado=bufferFloat;
			rtn=0;
			break;
		}
		printf("%s", mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return rtn;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(!getNombre(bufferString,sizeof(bufferString)) && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
