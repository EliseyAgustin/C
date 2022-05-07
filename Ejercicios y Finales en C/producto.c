#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*DESARROLLE UN ALGORITMO PARA CALCULAR EL IMPORTE DE UNA VENTA EN UN SUPERMERCADO.
 EL USUARIO DEBE INGRESAR EL NOMBRE DEL PRODUCTO, EL PRECIO POR UNIDAD Y EL NÚMERO DE UNIDADES.
  EL PROGRAMA MOSTRARÁ POR PANTALLA EL NOMBRE DEL PRODUCTO, EL NÚMERO DE UNIDADES VENDIDAS Y EL PRECIO TOTAL.*/
int main(){
	char producto[10];
	float precio_unidad, precio_total;
	
		
	
		printf("Ingresar nombre de producto\n");
		scanf("%s",&producto);
		printf("Ingresar numero de unidades\n");
		scanf("%f",&num_uni);
		printf("Ingresar precio por unidad\n");
		scanf("%f",&precio_unidad);
		
		
			
			precio_total=precio_unidad*num_uni;
			
		
				printf("Usted compro una cantidad de %.f",&num_total);
				printf(" de %s",&producto);
				printf(" y le salio un total de $%f\n",&precio_total);
					
			
system("pause");
	
	
	
	
	return 0;
}
