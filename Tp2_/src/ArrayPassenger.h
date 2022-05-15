/*
 * pasajeros.h
 *
 *  Created on: 14 may. 2022
 *      Author: brais
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#ifndef PASAJEROS_H_
#define PASAJEROS_H_
#define LEN 3
#define TAM 51
typedef struct{
	int id;
	char name[TAM];
	char lastName[TAM];
	float price;
	char flyCode[10];
	int typePassenger;
	int	statusFlight;
	int isEmpty;
}ePasajeros;


#endif /* PASAJEROS_H_ */
int initPassengers(ePasajeros* list,int len);
int addPassenger(ePasajeros* list, int len, int* id, int indice);
int findPassengerById(ePasajeros* list, int len,int id);
int removePassenger(ePasajeros* list, int len, int id);
int sortPassengers(ePasajeros* list, int len, int order);
int printPassenger(ePasajeros* list, int length);
int sortPassengers(ePasajeros* list, int len, int order);
void passengerModificarMenu(ePasajeros* list ,int tamTexto);
int pasajeroImprimir(ePasajeros* list);
int imprimirArrayPasajero(ePasajeros* list,int tam);
int buscarLibre(ePasajeros* list, int tam);
int pasajeroOrdenarPorApellidoTipo (ePasajeros* array,int tamanio);
int informarPassengers(ePasajeros* list,int len);
int agruparPasajeros(ePasajeros* list, int len, int order);

