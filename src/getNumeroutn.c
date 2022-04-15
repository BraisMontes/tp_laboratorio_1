/*
 * getNumeroutn.c
 *
 *  Created on: 15 abr. 2022
 *      Author: brais
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	int bufferInt;
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) //validacion de parametros
		{
			do{
				printf("%s", mensaje);// cualquier tipo de string en el msj
				scanf ("%d", &bufferInt);// guardamos la respuesta en el buffer
				if (bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s", mensajeError);
					reintentos --;
				}
			}while(reintentos >= 0 );

		}

		return retorno;
	}

	int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
	{
		int retorno = -1;
		float bufferFloat;
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) //validacion de parametros
		{
			do{
				printf("%s", mensaje);// cualquier tipo de string en el msj
				scanf ("%f", &bufferFloat);// guardamos la respuesta en el buffer
				if (bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s", mensajeError);
					reintentos --;
				}
			}while(reintentos >= 0 );

		}

		return retorno;
	}
int utn_getNumeroCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
	{
		int retorno = -1;
		char bufferChar;
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) //validacion de parametros
		{
			do{
				printf("%s", mensaje);// cualquier tipo de string en el msj
				fflush(stdin);
				scanf ("%c", &bufferChar);// guardamos la respuesta en el buffer
				if (bufferChar >= minimo && bufferChar <= maximo)
				{
					*pResultado = bufferChar;
					retorno = 0;
					break;
				}
					else
					{
						printf("%s", mensajeError);
						reintentos --;
					}

				}while(reintentos >= 0 );

			}

		return retorno;
	}
int calcularDescuentoLatam(int precioLatam){
	int porcentajeLatam;
	int descuentoLatam;

	porcentajeLatam =	 precioLatam*10/100;
	descuentoLatam = precioLatam - porcentajeLatam;
	return descuentoLatam;
}
int calcularInteresLatam(int precioLatam){
	int porcentaje;
	int interesLatam;

	porcentaje= precioLatam*25/100;
	interesLatam= precioLatam+ porcentaje;
	return interesLatam;

}
int calcularDescuentoAereo(int precioAereo){
	int porcentajeAereo;
	int descuentoAereo;

	porcentajeAereo = precioAereo*10/100;
	descuentoAereo = precioAereo- porcentajeAereo;
	return descuentoAereo;
}
int calcularInteresAereo(int precioAereo){
	int porcentaje;
	int interesAereo;

	porcentaje= precioAereo*25/100;
	interesAereo= precioAereo+ porcentaje;
	return interesAereo;
}
float calcularBitcoinLatam(float precioLatam){
	float bitcoin;
	bitcoin= precioLatam/4606954.55;
	return bitcoin;
}
float calcularBitcoinAereo(float precioAereo){
	float bitcoin;
	bitcoin= precioAereo/4606954.55;
	return bitcoin;
}
float mostrarPrecioUnitarioAereo(int precioAereo,float km){
	float precioUnitario;
	precioUnitario= precioAereo/km;
		return precioUnitario;
}
float mostrarPrecioUnitarioLatam(int precioLatam,float km){
	float precioUnitario;
	precioUnitario= precioLatam/km;
		return precioUnitario;
}
int mostrarDiferenciaDePrecio(int precioLatam, int precioAereo){
	int diferenciaPrecio;
	diferenciaPrecio = precioLatam- precioAereo;
	if(diferenciaPrecio<0){
		diferenciaPrecio *= -1;
	}
	return diferenciaPrecio;
}
