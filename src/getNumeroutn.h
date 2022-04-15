/*
 * getNumeroutn.h
 *
 *  Created on: 15 abr. 2022
 *      Author: brais
 */

#ifndef GETNUMEROUTN_H_
#define GETNUMEROUTN_H_
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNumeroCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int calcularDescuentoLatam(int precioLatam);
int calcularInteresLatam(int precioLatam);
int calcularBitcoinLatam(float precioLatam);
int calcularDescuentoAereo(int precioAereo);
int calcularInteresAereo(int precioAereo);
int caclularBitcoinAereo(int precioAereo);
float mostrarPrecioUnitarioAereo(int precioAereolineas, float km);
float mostrarPrecioUnitarioLatam(int precioLatam, float km);
int mostrarDiferenciaDePrecio(int precioLatam, int precioAereo);
#endif /* GETNUMEROUTN_H_ */
