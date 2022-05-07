#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdlib.h>
float acobrar(int , int ,char );
float devolver(float, float);
void pantalla(float, float);

int main(){
	char vehiculo[10];
	char continuar[3]={"si"};
	int dia, prueba;
	char horario;
	float ientregado;
	float iacobrar;
	float vuelto;
	int tpases, tpasesauto;
	float tpesos;
	tpases=0;
	tpesos=0;
	tpasesauto=0;
	
	while (!strcmp("si",continuar)){
	printf("\t\t\nIngrese el tipo de vehiculo: ");
	fflush(stdin);
	gets(vehiculo);
	printf("\t\t\nIngrese el dia: ");
	fflush(stdin);
	scanf("%d",&dia);
	printf("\t\t\nIngrese el horario: ");
	fflush(stdin);
	scanf("%c",&horario);
	printf("\t\t\nIngrese el importe entregado: ");
	fflush(stdin);
	scanf("%f",&ientregado);
	if (!strcmp("moto",vehiculo)){
		                          iacobrar=acobrar(5,dia,horario);
		                          vuelto=devolver(iacobrar,ientregado);
								  }
    if (!strcmp("auto",vehiculo)){
    	                           iacobrar=acobrar(10,dia,horario);
    	                           vuelto=devolver(iacobrar,ientregado);
    	                           if (horario=='a') tpasesauto++;
								   }
    if (!strcmp("camioneta",vehiculo)){
				                  iacobrar=acobrar(15,dia,horario);
								  vuelto=devolver(iacobrar,ientregado);
								  }    
    if (!strcmp("camion",vehiculo)){
	                              iacobrar=acobrar(20,dia,horario);
	                              vuelto=devolver(iacobrar,ientregado);
								  }
pantalla(iacobrar,vuelto);
tpases++;
tpesos=iacobrar+tpesos;
system("pause");
system("cls");
printf("\t\Continua vendiendo?: ");
fflush(stdin);
gets(continuar);
system("cls");
}								 
 printf("\t\tTotal pases auto en horario pico: %d\n",tpasesauto);
 printf("\t\tTotal pases: %d\n",tpases);
 printf("\t\tTotal pesos: %.2f\n",tpesos);
 system("pause");
 }
 float acobrar(int base, int d, char h){
       switch(d){
	   	         case 1
	   	              if (h=='a'){
						          return base*1,2;
						            }
								    else {
								    	return base*0,8;
								    	}
									    break;
                 case 2
	   	              if (h=='a'){
						          return base*1,2;
						            }
								    else {
								    	return base*0,8;
								    	}
									    break;
	             case 3
	   	              if (h=='a'){
						          return base*1,2;
						            }
								    else {
								    	return base*0,8;
								    	}
									    break;	
	             case 4
	   	              if (h=='a'){
						          return base*1,2;
						            }
								    else {
								    	return base*0,8;
								    	}
									    break;
                 case 5
	   	              if (h=='a'){
						          return base*1,2;
						            }
								    else {
								    	return base*0,8;
								    	}
									    break;	
                 case 6
                    return base*0,8;
                    break;
                 case 7
                       return base*0,8;
                       break;
                       
                       
                       }
      }
float devolver(float ac,float e){
	  return (e-ac);
	  }
void pantalla (float ac,float v){
	 system("cls");
	 printf("\t\tEl importe a cobrar es: %.2f\n",ac);
	  printf("\t\tSu vuelto es: %.2f\n",v);
	  }
                  
              				  	
	
	




