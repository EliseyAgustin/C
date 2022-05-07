#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int ValPresion(int X,int Y);
int ValPulsaciones(int A);
int ValTemperatura(int B);
int ValEdad(int C);
int NroTurno();

int main(){

	int edad,p_s,p_d,temp,puls;
	char PregUno[3], PregDos[3], PregTres[3];
	int contAptos=0,contNaptos=0,SumaEdad=0,promedioEdad=0;
	int ValidacionEdad, ValidacionPres, ValidacionTemp, ValidacionPuls, inicio;

	
	printf("Desea ingresar un nuevo donante? ( 0 -> No / 1 -> Si) \n");
	fflush(stdin);
	scanf("%i",&inicio);
	
	while(inicio!=0){
	
		printf("Ingrese edad \n");
		fflush(stdin);
		scanf("%i",&edad);
		
		ValidacionEdad = ValEdad(edad);
	
		printf("Ingrese la presion sistolica \n");
		fflush(stdin);
		scanf("%i",&p_s);
	
		printf("Ingrese presion diastolica \n");
		fflush(stdin);
		scanf("%i",&p_d);
		
		ValidacionPres = ValPresion(p_s,p_d);
	
		printf("Ingrese la tempearatura \n");
		fflush(stdin);
		scanf("%i",&temp);
		
		ValidacionTemp = ValTemperatura(temp);
	
		printf("Ingrese las pulsaciones \n");
		fflush(stdin);
		scanf("%i",&puls);
		
		ValidacionPuls = ValPulsaciones(puls);  // donde guardo el valor 0 o 1, en una variable
	
		printf("Tiene algun tipo de enfermedad? (si / no) \n");
		fflush(stdin);
		scanf("%s",&PregUno);
	
		printf("Tuvo relaciones de riesgo? (si / no) \n");		
		fflush(stdin);
		scanf("%s",&PregDos);
	
		printf("Tiene tatuajes? (si / no) \n");
				fflush(stdin);
		scanf("%s",&PregTres);
		
		// !strcmp(PregUno,"no") el valor de la comparacion es cero si PregUno es igual a "no", entonces niego el valor 0 con ! y me da 1 (verdadero)
	
		if( !strcmp(PregUno,"no") && strcmp(PregDos,"no")==0 && strcmp(PregTres,"no")==0 && (ValidacionEdad == 1)  && (ValidacionPres == 1)  && (ValidacionTemp == 1) && (ValidacionPuls == 1) ){
			printf("Su numero de turno es: %i\n",NroTurno()   );
			contAptos++;
			SumaEdad = SumaEdad + edad;			
		}else{
			printf("\nNo apto\n\n");
			contNaptos++;
		}
	
		printf("Desea seguir ingresando donantes? ( 0 -> No / 1 -> Si) \n");
		fflush(stdin);
		scanf("%i",&inicio);
	
	}
		printf("\ncantidad de aptos %i \n",contAptos);
		printf("\ncantidad de no aptos %i \n",contNaptos);	
	if( (contAptos != 0)  )
	    {
		promedioEdad= SumaEdad / contAptos;
		printf("\nEl promedio de edad de los aptos es %i \n",promedioEdad);	
		}
	
		printf("\n Fin del programa. \n\n");	
	
	
	system("pause");
	return 0;
}

int ValPresion(int X,int Y){
	if( (X > 14) || (Y < 7) ) return 0;
	else return 1;  // la negacion de esa condicion es x<=14 && y >=7
}

int ValPulsaciones(int A){
	if( (A > 90) || (A < 50) ) return 0;
	else return 1;
}

int ValTemperatura(int B){
	if( B > 36 ) return 0;
	else return 1;
}

int ValEdad(int C){
	if( C < 18 ) return 0;
	else return 1;
}

int NroTurno(){    // funcion sin parametros
	static int Turno=0;
	Turno++;
	return Turno;
}
		

		
		
	
	
	
















