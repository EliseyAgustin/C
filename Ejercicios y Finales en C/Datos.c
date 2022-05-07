#include <stdio.h>
#include <conio.h>



int main() 
{

char nombre [20];
char apellido [20];
int telefono [10];
int edad;

printf("ingrese su nombre \n");
scanf("%c",&nombre);

printf("ingrese su telefono\n");
fflush(stdin);
scanf("%d,&edad");

printf("ingrese su edad\n");
fflush(stdin);
scanf("%d", &edad);

printf("su nombre es %s\n"), nombre;
printf("su apellido es %s\n"), edad;
printf("su edad es%d\n"), edad;
printf("su telefono es%d\n"), telefono;

getch();


	return 0;
}
