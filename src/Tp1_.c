/*
 ============================================================================
 Name        : Tp1_.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "getNumeroutn.h"
int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	float km;
	int flagUno=0;
	int flagDos=0;
	int flagTres=0;
	int flagCuatro=0;
	float precioLatam;
	float precioAereolineas;
	int descuentoLatam;
	int recargoLatam;
	float precioUnitarioLatam;
	int descuentoAereo;
	int recargoAereo;
	float precioUnitarioAereo;
	float bitcoinLatam;
	float bitAereo;
	float diferencia;



while(opcion != 6){
	printf("1) Ingresar kilometros: (km= x)\n 2) Ingresar precio de vuelos (Aerolíneas=y, Latam=z)\n 3)Calcular todos los costos \n 4)Informar Resultados \n 5)Carga forzada de datos \n 6)Salir" );
	scanf("%d", &opcion);
	while(opcion<1 || opcion >6){
		printf("ERROR, ingrese un dato entre 1 y 6");
		scanf("%d", &opcion);
		}
	switch(opcion){
		case 1:
			if(flagUno==0){
				utn_getNumeroFlotante(&km,"Ingrese kilometros\n","ERROR, ingrese kilometros\n",0,99999,2);
				printf("Se han ingresado los kilometros\n");
			flagUno= 1;
			}
		break;
		case 2:
			if(flagUno ==1 && flagDos==0){
		utn_getNumeroFlotante(&precioLatam,"Ingrese el precio de vuelo en latam\n","ERROR, ingrese el precio de vuelo en latam mayor a 0",0,500000,2);
		utn_getNumeroFlotante(&precioAereolineas,"Ingrese el precio de vuelo en Aereolineas\n","ERROR, ingrese el precio de vuelo en Aereolineas mayor a 0",0,500000,2);
			if(precioLatam!=0 || precioAereolineas!=0){
				printf("Se ha ingresado los precios\n");
			}
			flagDos=1;

			}
		break;
		case 3:
			if(flagUno ==1 && flagDos==1 && flagTres==0){
				descuentoLatam= calcularDescuentoLatam(precioLatam);
				recargoLatam= calcularInteresLatam(precioAereolineas);
				bitcoinLatam= calcularBitcoinLatam(precioLatam);
				precioUnitarioLatam=mostrarPrecioUnitarioLatam(precioLatam,km);
				descuentoAereo=calcularDescuentoAereo(precioAereolineas);
				recargoAereo=calcularInteresAereo(precioAereolineas);
				bitAereo =calcularBitcoinAereo(precioAereolineas);
				precioUnitarioAereo=mostrarPrecioUnitarioAereo(precioAereolineas,km);
				diferencia=mostrarDiferenciaDePrecio(precioLatam,precioAereolineas);
				flagTres=1;
			}
		break;
		case 4:
			if(flagUno==1 && flagDos==1 && flagTres==1 ){
			printf("\nEl precio de vuelo en latam con debito es de %d\n",descuentoLatam);
			printf("\nEl precio de vuelo en latam con credito es de %d\n", recargoLatam);
			printf("\nEl precio pagando con bitcoin en latam es de %f\n", bitcoinLatam);
			printf("\nEl precio unitario en latam es de %f\n",precioUnitarioLatam);
			printf("\nEl precio de vuelo en aereolineas con debito es de %d\n", descuentoAereo);
			printf("\nEl precio de vuelo en aereolineas con credito es de %d\n", recargoAereo);
			printf("\nEl precio pagando con bitcoin en aereolineas es de %f\n", bitAereo);
			printf("\nEl precio unitario en Aereolineas es de %f\n",precioUnitarioAereo);
			printf("\nLa diferencia de precio es de %f\n", diferencia);
			}
			break;
		case 5:
			km=7090;
			precioAereolineas=162965;
			precioLatam= 159339;
			descuentoLatam= calcularDescuentoLatam(precioLatam);
			recargoLatam= calcularInteresLatam(precioAereolineas);
			bitcoinLatam= calcularBitcoinLatam(precioLatam);
			precioUnitarioLatam=mostrarPrecioUnitarioLatam(precioLatam,km);
			descuentoAereo=calcularDescuentoAereo(precioAereolineas);
			recargoAereo=calcularInteresAereo(precioAereolineas);
			bitAereo =calcularBitcoinAereo(precioAereolineas);
			precioUnitarioAereo=mostrarPrecioUnitarioAereo(precioAereolineas,km);
			diferencia=mostrarDiferenciaDePrecio(precioLatam,precioAereolineas);
			printf("\nEl precio de vuelo en latam con debito es de %d\n",descuentoLatam);
			printf("\nEl precio de vuelo en latam con credito es de %d\n", recargoLatam);
			printf("\nEl precio pagando con bitcoin en latam es de %f\n", bitcoinLatam);
			printf("\nEl precio unitario en latam es de %f\n",precioUnitarioLatam);

			printf("\nEl precio de vuelo en aereolineas con debito es de %d\n", descuentoAereo);
			printf("\nEl precio de vuelo en aereolineas con credito es de %d\n", recargoAereo);
			printf("\nEl precio pagando con bitcoin en aereolineas es de %f\n", bitAereo);
			printf("\nEl precio unitario en Aereolineas es de %f\n",precioUnitarioAereo);

			printf("\nLa diferencia de precio es de %f\n", diferencia);

			break;
		case 6:
			break;

	}
}



	return EXIT_SUCCESS;
}
