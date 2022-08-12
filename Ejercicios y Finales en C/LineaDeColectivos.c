#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int opciones();

int main(int argc, char *argv[]) {
	int i, menu;
	int numParada, vnumParada[50];
	char barrio, vBarrio[50];
	setlocale (LC_CTYPE, "spanish");
	
	do{
		menu = opciones();
		switch(menu){
			case 1:
				printf("Ingrese el numero de la parada: del 1 al 10\n");
				scanf("%i", &numParada);
				if(numParada > 0 && numParada <=3){
					printf("Su barrio destino es: 'l' Liniers");
					barrio = 'l';
				}
				if(numParada >= 4 && numParada <=5){
					printf("Su barrio destino es: 'f' Flores");
					barrio = 'f';
				}
				if(numParada >= 6 && numParada <=7){
					printf("Su barrio destino es: 'c' Caballito");
					barrio = 'c';
				}
				if(numParada >= 8 && numParada <=10){
					printf("Su barrio destino es: 'p' Palermo");
					barrio = 'p';
				}
				cargaParadas(numParada, barrio, &vnumParada, &vBarrio, &i);
				break;
				case 2:
					informar(&vnumParada, &vBarrio, &i);
					break;
				case 3:
					system("cls");
			        break;
			        default:
			        printf("La opcion es invalida");
			break;
		}
	} while (menu!=3);
}

//Funcion 1
int opciones(){

int menu;
system ("color 02");
printf("\n||\t     MINISTERIO DE TRANSPORTE\t    ||");
printf("\n\t\tMENU\n");
printf("Opcion 1: Ingresar datos de paradas de la línea de colectivos\n");
printf("Opcion 2: Consultas de la información sobre la línea de colectivos\n");
printf("Opcion 3: Salir\n");
scanf("%d",&menu);
system("cls");
return menu;
}

//Funcion 2
void cargaParadas(int numParada, char barrio, int *vnumParada, char *vBarrio, int *i){
	vnumParada[*i] = numParada;
	vBarrio[*i] = barrio;
	
	*i = *i + 1;
}

//Funcion 3
void cantidadParadas(int *vnumParada, char *vBarrio, int *i){
	int x;
	int cantParadasL = 0, cantParadasF = 0, cantParadasC = 0, cantParadasP = 0;
	
	for(x = 0; x < *i; x++){
		
		if(*(vBarrio + x) == 'l'){
			cantParadasL++;
		}
		if(*(vBarrio + x) == 'f'){
			cantParadasF++;
		}
		if(*(vBarrio + x) == 'c'){
			cantParadasC++;
		}
		if(*(vBarrio + x) == 'p'){
			cantParadasP++;
		}
	}
	printf("La cantidad de paradas por Liniers es de: %i\n", cantParadasL);
	printf("La cantidad de paradas por Flores es de: %i\n", cantParadasF);
	printf("La cantidad de paradas por Caballito es de: %i\n", cantParadasC);
	printf("La cantidad de paradas por Palermo es de: %i\n", cantParadasP);
}

//Funcion 4
void recorridoLinea(int *vnumParada, char *vBarrio, int *i){
int j, cant=0, cantl=0, cantf=0, cantp=0, cantc=0;
     
     char barrio, barrioparadai, barrioparadaf;
     
     //Cuento todas las paradas
     for(j = 0;j < *i;j++){ 
			cant++;        
    
             //Muestro los datos de cada parada
          	 printf("Nro de parada %d\t Barrio %c\n",*(vnumParada + j),*(vBarrio + j));
             
             //Cuento la cantidad de paradas por barrio
             switch(*(vBarrio + j)){
				case 'l' : cantl=cantl+1; 
				break;
				case 'c' : cantc=cantc+1; 
				break;
				case 'f' : cantf=cantf+1; 
				break;
				case 'p' : cantp=cantp+1; 
				break;
			}
		
			 //Guardo el barrio de la primera y última parada
			 if (j==0) { 
			 barrioparadai=*(vBarrio + j);
			}
			 
			 if (j==i-1) { 
			 barrioparadaf=*(vBarrio + j);
			}
		}  //Fin del for
      
	    //Informe punto a
        printf("Cantidad de paradas por barrio Liniers: %d\t\n", cantl);
        printf("Cantidad de paradas por barrio Flores: %d\t\n", cantf);
        printf("Cantidad de paradas por barrio Caballito: %d\t\n", cantc);
        printf("Cantidad de paradas por barrio Palermo: %d\t\n", cantp);
        
        if (cant==cantl || cant==cantf || cant==cantc || cant== cantp) {
        printf("Todas las paradas son del mismo barrio\n");
		} else{
		printf("No todas las paradas son del mismo barrio");
		}
        
        //Informe punto b
        if (barrioparadai==barrioparadaf) {
        printf("La línea de colectivo empieza y termina en el mismo barrio %c\n", barrioparadai);
		} else{
		printf("\nLa línea de colectivo no empieza y termina en el mismo barrio");
   }

}

//Funcion 5
void informar(int *vnumParada, char *vBarrio, int *i){
	cantidadParadas(vnumParada, vBarrio, i);
	recorridoLinea(vnumParada, vBarrio, i);
}


