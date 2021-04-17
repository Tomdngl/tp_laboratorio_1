/*
 * utn_get.h
 *
 *      Author: Tomas Dangelo
 */

#ifndef UTN_GET_H_
#define UTN_GET_H_
/**
 * @fn int utn_getNumeroFloat(float*, char*, char*, int, int, int)
 * @brief Esta función permite pedir al usuario un número de tipo flotante, validarlo y enviarlo a la variable que queramos a traves de un puntero.
 *
 * @param pResultado Es la variable en la cual se guardará el numero en el caso de ser válido.
 * @param mensaje Es el mensaje que se mostrara al usuario para pedir el número.
 * @param mensajeError Es el mensaje en caso de que se presente un error.
 * @param min Es el número mínimo que puede ingresar el usuario.
 * @param max Es el número máximo que puede ingresar el usuario.
 * @param reintentos Es la cantidad de reintentos que tiene el usuario.
 * @return La función en caso de salir correctamente nos va a devolver el valor 0. En el caso de error -1.
 */
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max, int reintentos);

/**
 * @fn int utn_getNumeroFloat(float*, char*, char*, int, int, int)
 * @brief Esta función permite pedir al usuario un número de tipo entero, validarlo y enviarlo a la variable que queramos a traves de un puntero.
 *
 * @param pResultado Es la variable en la cual se guardará el numero en el caso de ser válido.
 * @param mensaje Es el mensaje que se mostrara al usuario para pedir el número.
 * @param mensajeError Es el mensaje en caso de que se presente un error.
 * @param min Es el número mínimo que puede ingresar el usuario.
 * @param max Es el número máximo que puede ingresar el usuario.
 * @param reintentos Es la cantidad de reintentos que tiene el usuario.
 * @return La función en caso de salir correctamente nos va a devolver el valor 0. En el caso de error -1.
 */
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, float min, float max, int reintentos);
#endif /* UTN_GET_H_ */
