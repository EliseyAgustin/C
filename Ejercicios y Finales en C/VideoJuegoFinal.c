#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int opciones();

int main(int argc, char *argv[]) {
	int i = 0, menu, podmonsh, podmonsr, vpodmonsh[50], vpodmonsr[50];  
	char ganador, vganador[50];
	setlocale (LC_CTYPE, "spanish");
	
	do{
		menu = opciones();
		
		switch(menu){
			case 1:
			printf("Ingrese el poder del monstruo de la Hechicera: \n");
			scanf("%i", &podmonsh);
		    printf("Ingrese el poder del monstruo del rival: \n");
			scanf("%i", &podmonsr);
			if(podmonsh > podmonsr){
			    printf("El ganador del enfrentamiento es la Hechicera\n");
			    ganador = 'h';
			} else{
				printf("El ganador del enfrentamiento es el Rival\n");
				ganador = 'r';
			}
			carga(podmonsh, podmonsr, ganador, &vpodmonsh, &vpodmonsr, &vganador, &i);
			break;
			case 2:
			informe(&vpodmonsh, &vpodmonsr, &vganador, &i);
			break;
			case 3:
			system("cls");
			break;
			default:
			printf("La opcion es invalida");
			break;
		}
	}while (menu!= 3);
}

//Funcion 1
int opciones(){

int menu;
system ("color 02");
printf("\n||\t     BATALLAMONS\t    ||");
printf("\n\t\tMENU\n");
printf("Opcion 1: Ingresar datos de enfrentamiento al videojuego\n");
printf("Opcion 2: Calcular resultados del videojuego\n");
printf("Opcion 3: Salir\n");
scanf("%d",&menu);
system("cls");
return menu;
}

//Funcion 2
void carga(int podmonsh, int podmonsr, char ganador, int *vpodmonsh, int *vpodmonsr, char *vganador, int *i){
	vpodmonsh[*i] = podmonsh; 
	vpodmonsr[*i] = podmonsr;
	vganador[*i] = ganador;
	
	*i = *i + 1;
}

//Funcion 3
void informarGanador(int *vpodmonsh, int *vpodmonsr, char *vganador, int *i){
	int contH = 0, contR = 0;
	int x;
	
	int acumPoderRival = 0, acumPoderHechicera = 0;
	
	for(x = 0; x < *i; x++){
		if(*(vganador + x) == 'r'){
			contR++;
		} else{
			contH++;
		}
		
		acumPoderRival += *(vpodmonsr + x);
		acumPoderHechicera += *(vpodmonsh + x);
	}
	
	float promedioRival = acumPoderRival / (*i);
	float promedioHechicera = acumPoderHechicera / (*i);
	
	if(contR > contH){
		printf("El ganador del juego es el Rival\n");
		printf("El poder promedio es de: %.2f\n", promedioRival);
	} else if(contR == contH){
		printf("Hubo un empate\n");
	} else{
		printf("El ganador del juego es la hechicera\n");
		printf("El poder promedio es de: %.2f\n", promedioHechicera);
	}
}

//funcion 4
void mayorPoder(int *vpodmonsh, int *vpodmonsr, int *i){
	int maxPoderRival = 0;
	int maxPoderHechicera = 0;
	int x;
		
	for(x = 0; x < *i; x++){
		if(maxPoderRival < *(vpodmonsh + x)){
			maxPoderRival = *(vpodmonsr + x);
		}
		
		if(maxPoderHechicera < *(vpodmonsh + x)){
			maxPoderHechicera = *(vpodmonsh + x);
		}
	}
	
	if(maxPoderHechicera < maxPoderRival){
		printf("El mayor poder es de: %i\n", maxPoderRival);
	} else{
		printf("El mayor poder es de: %i\n", maxPoderHechicera);
    }
}

//Funcion 5
void informe(int *vpodmonsh, int *vpodmonsr, char *vganador, int *i){
	
	informarGanador(vpodmonsh, vpodmonsr, vganador, i);
	
	mayorPoder(vpodmonsh, vpodmonsr, i);
}




