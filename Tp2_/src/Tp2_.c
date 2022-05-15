 /*
 ============================================================================
 Name        : Tp2_.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Utn.h"
#include<string.h>
#include <ctype.h>
#define LEN 3
#define TAM 51
int main(void) {
	setbuf(stdout,NULL);
int auxId=100;
int opcionMenu;
int flagOpcion=0;
int flagOpcionDos=0;
int flagOpcionTres=0;
int indice;
int verificoAlta;
int verificoBaja;
int verificoIdBaja;
int order;
int acumPrecioPasajes=0;
int contPrecioPasajes=0;
int promedioPrecioPasajes;
int respuesta=0;
int verificoModificacion;
ePasajeros passengers[LEN];

if(initPassengers(passengers,LEN)==0){
	do{
		printf("Elija una opcion \n1)Alta de pasajero\n2)Modificar pasajero\n3)Baja de pasajero\n4)Informar pasajeros\n5)Salir");
		scanf("%d",&opcionMenu);

		switch(opcionMenu){
		case 1:
			if(flagOpcion == 0){
				printf("\nAltas Pasajeros\n");
				indice = buscarLibre(passengers, LEN);
				if(indice == -1)
				{
					printf("\nNo se pudo realizar el alta\n");
				}
				else{
					while(respuesta != 1){
						verificoAlta = addPassenger(passengers,LEN,&auxId,indice);
						 	 if(verificoAlta != -1){
						 		 printf("\nSe realizo el alta\n");
						 		 acumPrecioPasajes = acumPrecioPasajes + passengers[indice].price;
								contPrecioPasajes++;
						 	 }
						printf("Desea seguir ingresando datos? 0-Si   1-No");
						scanf("%d",&respuesta);
					}
				}

				flagOpcion=1;
			}
			break;
		case 2:
			if(flagOpcion == 1 && flagOpcionDos== 0){
				if(utn_getNumero(&auxId,"\nIngrese el id que desea dar modificar\n","\nId ingresado invalido \n",100,103,2)==0){
					verificoModificacion = findPassengerById(passengers,LEN,auxId);
							if(verificoModificacion == 0){
								printPassenger(passengers,LEN);
								passengerModificarMenu(passengers,TAM);
								flagOpcionDos=1;
							}
			}

			}
			break;
		case 3:
			if(flagOpcion == 1 && flagOpcionDos == 1 && flagOpcionTres== 0){

			if(utn_getNumero(&auxId,"\nIngrese el id que desea dar de baja\n","\nId ingresado invalido \n",100,103,2)==0){
				verificoIdBaja = findPassengerById(passengers,LEN,auxId);
				if(verificoIdBaja == 0){
				verificoBaja = removePassenger(passengers,LEN,auxId);
					if(verificoBaja == 0 ){
						printf("\nBaja realizada con exito\n");
					}
					else{
						printf("\nID ingresado incorrecto\n");
					}
				}
			}

				flagOpcionTres=1;
			}
			break;
		case 4:
	if(flagOpcion == 1 && flagOpcionDos == 1 && flagOpcionTres== 1){
		if(utn_getNumero(&order,"\nIngrese 0 si quiere de menor a mayor o 1 si quiere de menor a mayor\n","\nnumero ingresado invalido \n",0,1,2)==0){
			if(agruparPasajeros(passengers,TAM,order)== 0){
				printPassenger(passengers,LEN);
			}
		}
		printf("\nEl total de los precios de los pasajes es de: %d\n", acumPrecioPasajes);
		promedioPrecioPasajes= acumPrecioPasajes / contPrecioPasajes;
		printf("\nEl promedio de los precios de los pasajes es de: %d\n",promedioPrecioPasajes);
		if(passengers[indice].price > promedioPrecioPasajes){
			printf("\nPasajeros que superan el precio promedio %f\n",passengers[indice].price);
		}
		for(int i=0;i>LEN;i++){
		printf("\nPasajeros por codigo de vuelo %s\n", passengers[i].flyCode);
		if(passengers[i].statusFlight == 1){
			printf("%d\n", passengers[i].statusFlight);

		}
		}
	}
	break;
		case 5:
			break;

		}
	}while(opcionMenu != 5);
}
	return EXIT_SUCCESS;
}
