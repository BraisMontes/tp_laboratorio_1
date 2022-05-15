/*
 * pasajeros.c
 *
 *  Created on: 14 may. 2022
 *      Author: brais
 */
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Utn.h"
#include<string.h>
#include <ctype.h>
int initPassengers(ePasajeros* list, int len){
	int retorno = -1;
	 if(list != NULL && len>0){
		 retorno = 0;
		 for(int i=0;i<len;i++){
			 list[i].isEmpty=1;
		 }
	 }
	 return retorno;
	}
int addPassenger(ePasajeros* list, int len, int* id, int indice){
	int retorno = -1;

	ePasajeros bufferPasajeros;
	if(list != NULL && len >0 && id > 0 && list->isEmpty == 1){
		if(utn_getNombre(bufferPasajeros.name,TAM,"\n Ingrese Nombre\n","\n Nombre invalido\n",2)==0 && utn_getNombre(bufferPasajeros.lastName,TAM,"\nIngrese apellido\n", "\n Apellido ingresado invalido\n",2)==0 && getAlfanumerico(bufferPasajeros.flyCode ,"\nIngrese codigo de vuelo\n","Codigo de vuelo ingresado incorrecto\n",TAM,2) == 0 && getNumeroFlotante(&bufferPasajeros.price,"\n Ingrese precio de vuelo", "\n Precio ingresado invalido\n",0,999999,2)==0 && utn_getNumero(&bufferPasajeros.typePassenger, "\nTipo de pasajero,\n1)Menor\n2)Mayor","\n Tipo de pasajero incorrecto\n",1,2,2)==0 && utn_getNumero(&bufferPasajeros.statusFlight, "\n Estado de vuelo\n1)Activo\n2)Demorado\n","\nEstado de vuelo incorrecto",1,2,2)==0){
				retorno = 0;
				list->id = *id;
				list->isEmpty = 0;
				list[indice]= bufferPasajeros;
				(*id)++;

			}

	}
	return retorno;
}
int findPassengerById(ePasajeros* list, int len,int id){
	int indice =-1;
		if(list != NULL && len>0){
			for(int i=0;i<len;i++){
				if(list[i].id== id && list[i].isEmpty == 0){
					indice = i;
					break;
				}
			}
		}
		return indice;
	}
int removePassenger(ePasajeros* list, int len, int id){
	int retorno = -1;

	if (list != NULL && list->isEmpty == 0 && len>0){
		for(int i=0;i<len;i++){
			if(list[i].id == id && list[i].isEmpty == 0){

				list->isEmpty = 1;
			}
		}
			retorno = 0;
		}

	return retorno;
}
int sortPassengers(ePasajeros* list, int len, int order){
	int retorno=-1;


	return retorno;
}
int printPassenger(ePasajeros* list, int length){
	int respuesta=-1;
	if(list != NULL && length > 0){
		respuesta=0;
		for(int i=0;i<length;i++){
			pasajeroImprimir(&list[i]);
		}
	}
	return respuesta;

}
void passengerModificarMenu(ePasajeros* list ,int tamTexto){
	int opcion;
	do{
		if(utn_getNumero(&opcion,"Ingrese numero de la opcion que quiere modificar\n1)Nombre\n2)Apellido\n3)Precio\n4)Tipo de pasajero\n5)Codigo de vuelo\n","Opcion no valida",1,5,2)==0){
			switch(opcion){
			case 1:
				if(utn_getNombre(list->name,tamTexto,"Ingrese nombre","Error nombre ingresado invalido",2)==0){
					printf("Modificacion en proceso");

				}
				break;

			case 2:
				if(utn_getNombre(list->lastName,tamTexto,"Ingrese Apellido","Error apellido ingresado invalido",2)==0){

						printf("Modificacion en proceso");

				}
				break;
			case 3:
				if(getNumeroFlotante(&list->price,"Ingrese precio","ERROR",1.0,99999.9,2)==0){
					printf("Modificacion en proceso");
				}
				break;
			case 4:
				if(utn_getNumero(&list->typePassenger, "\nTipo de pasajero,\n1)Menor\n2)Mayor","\n Tipo de pasajero incorrecto\n",1,2,2)==0){
					printf("Modificacion en proceso");
				}
				break;
			case 5:
				if(utn_getNumero(&list->statusFlight, "\n Estado de vuelo\n1)Activo\n2)Demorado\n","\nEstado de vuelo incorrecto",1,2,2)==0){
					printf("Modificacion en proceso");
				}
				break;
			}
		}

	}while(opcion != 5);
}
int pasajeroImprimir(ePasajeros* list){
	int retorno = -1;
	if(list != NULL && list->isEmpty == 0){
		retorno = 0;
		printf("ID: %s - %s - %f - %d - %d", list->lastName, list->lastName, list->price,list->typePassenger,list->statusFlight);
	}
	return retorno;
}

int buscarLibre(ePasajeros* list, int tam){
int indice=-1;
	if(list != NULL && tam>0){
		for(int i=0;i<tam;i++){
			if(list[i].isEmpty==1){
				indice=i;
				break;
			}
		}
	}
	return indice;
}
int pasajeroOrdenarPorApellidoTipo (ePasajeros* array,int tamanio){

	int retorno = -1;
	int flagSwap;
	int i;
	ePasajeros bufferSwap;


	if (array != NULL && tamanio >0){

			do {
				  flagSwap = 0;

				  for (i = 0 ; i< tamanio - 1; i++)
				  {
						if (array[i].isEmpty == 1 || array[i + 1].isEmpty == 1 ){

								continue;
						}

							if(strncmp(array[i].lastName, array[i + 1].lastName,tamanio) > 0)
							/*  en esta parte va lo que queremos ordenar array[i].loQueQueresQrdenar*/
							{
								flagSwap = 1;
								bufferSwap = array[i];
								array[i] = array[i + 1];
								array[i + 1] = bufferSwap;

							} // FIN DEL IF
					else if (strncmp(array[i].lastName, array[i + 1].lastName,tamanio) == 0 &&  array[i].typePassenger > array[i + 1].typePassenger)

							{	// COMPARACION DE STRING 									Comparacion de CHAR
									flagSwap = 1;
									bufferSwap = array[i];
									array[i] = array[i + 1];
									array[i + 1] = bufferSwap;
							}

				  }// FIN DEL FOR

				  tamanio --;

			}while (flagSwap);

			retorno = 0;
	}

	return retorno;
}
int agruparPasajeros(ePasajeros* list, int len, int order){

	int estaOk = -1;
	ePasajeros auxPasajero;

	if(list != NULL){
		for(int i = 0; i < len -1; i++){
			for(int j = i + 1; j < len; j ++){
				estaOk = 0;

				if(list[i].isEmpty == 0 && list[j].isEmpty == 0){

					switch(order){
						case 0:
							if(list[i].typePassenger < list[j].typePassenger || (list[i].typePassenger == list[j].typePassenger && (strcmp(list[i].lastName, list[j].lastName)) < 0)){
								auxPasajero = list[i];
								list[i] = list[j];
								list[j] = auxPasajero;
							}
							break;
						case 1:
							if(list[i].typePassenger > list[j].typePassenger || (list[i].typePassenger == list[j].typePassenger && (strcmp(list[i].lastName, list[j].lastName)) > 0)){
								auxPasajero = list[i];
								list[i] = list[j];
								list[j] = auxPasajero;
							}
							break;
						default:
							printf("No es un orden valido.\n");
					}
				}
			}
		}
	}
	return estaOk;
}

