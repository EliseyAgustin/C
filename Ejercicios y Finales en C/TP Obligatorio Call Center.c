#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

void carga(int, int , int , int , int *, int *, int *, int *);
void informe(int, int *, int *, int *,int *);

int main(){
	char cod_z;
    int i, resp, cod, stock, cant_P, retiro;
	int cant_cod[50], cant_p[50], cant_codz[50], cant_retiro[50];
    for(i=0;i<50;i++)
         cant_cod[i]=0;
    
	do{
	printf("\n||\t      CALL CENTER\t    ||");
	printf("\n\t\tMENU\n");
	printf("\nOpcion 1: Ingresar stock de producto en planta");
	printf("\nOpcion 2: Ingresar pedidos de Call Center del dia");
	printf("\nOpcion 3: Generar Informe para el Sector de Logistica y Produccion al finalizar el dia\n");
	printf("Opcion 4: SALIR\n");
	fflush(stdin);
	scanf("%i", &resp);
	system("cls");
	switch(resp){
		case 1:
			printf("Ingrese el stock disponible en la fabrica: ");
			scanf("%i", &stock);
			break;
		case 2:
			printf("Ingrese el codigo de cliente: ");
			scanf("%i", &cod);
			fflush(stdin);
			printf("Ingrese la cantidad de unidades del pedido: ");
			scanf("%i", &cant_P);
			fflush(stdin);
			printf("Ingrese el codigo de la zona: 'N'=Norte, 'S'=Sur, 'O'=Oeste, 'C'=Centro) ");
			scanf("%s", &cod_z);
			fflush(stdin);
			printf("Ingrese 1 si lo viene a buscar o 2 si se lo enviamos: ");
			scanf("%i", &retiro);
			carga(cod, cant_P, cod_z, retiro, cant_cod, cant_p, cant_codz, cant_retiro);
			break;
		case 3:
			informe(stock, cant_cod, cant_p, cant_codz, cant_retiro);
			break;
		case 4:
			system("cls");
			break;
			default:
			printf("Error de eleccion");
			break;
		}
	}
	while(resp!=4);
}

void carga(int cod, int cant_P, int cod_z, int retiro, int *cant_cod, int *cant_p, int *cant_codz, int *cant_retiro){
	
	int i=0;
	while(i<50 && *(cant_cod+i)!=0)
	       i++;
	if(i==50)
	{  
	    printf("No se puede agregar mas valores");  
		 }	 
	else
	{
	*(cant_cod+i)=cod;
	*(cant_p+i)=cant_P;
	*(cant_codz+i)=cod_z;
	*(cant_retiro+i)=retiro;
	}
	
	
}

void informe(int stock, int *cant_cod, int *cant_p, int *cant_codz, int *cant_retiro){
    int stock_in=stock;
	int j=0, cant_S=0, cant_N=0, cant_C=0, cant_O=0;
	printf("\n---------------------------");
	printf("\nC.Cliente  Cantidad  Zona  ");
	printf("\n---------------------------");
	
	while (*(cant_cod+j)!=0 && j<50)
	{
	       stock=stock-*(cant_p+j);
	       if (*(cant_retiro+j))
	       {
		    switch (*(cant_codz+j))
		    {
			case 'N':
				     cant_N=cant_N+*(cant_p+j);
				     break;
			case 'S':
				     cant_S=cant_S+*(cant_p+j);
				     break;
			case 'O':
				     cant_O=cant_O+*(cant_p+j);
				     break;
			case 'C':
				     cant_C=cant_C+*(cant_p+j);
				     break;
				     
			         }
		              printf("\n%9d %8d %6d",*(cant_cod+j));
		              j++;
		             } 
	}
	
	printf("\nEl informe es %i: ",stock);
	printf("\nLa cantidad de pedidos por zona Norte es: %i",cant_N);
	printf("\nLa cantidad de pedidos por zona Sur es: %i",cant_S);
	printf("\nLa cantidad de pedidos por zona Oeste es: %i",cant_O);
	printf("\nLa cantidad de pedidos por zona Centro es: %i",cant_C);
	if(stock>=0){
    printf("\nStock Suficiente");
	}else{
		 printf("\nStock Insuficiente, debera producir %i",stock_in);
		}
		
}

