#include"milibreria.h"//llamamos a la libreria
/*	
	Autor: Oscar Eduardo Fletes Ixta
	Escuela: UVM Campus Lomas Verdes
	Materia: Programcion Estructurada
	CICLO: 01/2022

	Libreria en lenguaje c que muestra el uso de:
		* Declaracion de variables 
		* Variables del tipo char, float, int
		* Uso de la libreria String.h
		* Uso de la libreria stdlib.h
		* Funciones para cadenas de caracteres
		* Funciones con parametros
		* Prototipos de funciones
		* Ciclo do-while
		* Ciclo for
		* Uso de condiciones

	Objetivo:
	Mostrar el uso de funciones, variables de tipo  char, float, int, uso de librerias string.h, stdlib.h, 
	uso de ciclo do-while, ciclo for y condicones, para crear una libreria para validacion de datos.

	Breve descripcion:
	Se crea una libreria para validar datos de cadenas, enteros y decimales 
	*/
void leers(char *mensaje, char s[], int n){//funcon para validar cadenas 
	printf(mensaje);
	fflush(stdin);
	fgets(s,n,stdin);
	//sprintf(text,"%%%d[^\\n]", n);
	//fcanf(stdin,text ,s);
	fflush(stdin);
	if(s[strlen(s)-1] =='\n'){
		s[strlen(s)-1]=0;
	}
}

float leerF(char *mensaje, float inferior, float superior){//funcion para validar variables con decimal
	float valor=superior+1;
	char s[10];
	do{
		printf(mensaje);
		fflush(stdin);
		fgets(s,10,stdin);
		fflush(stdin);
		if(s[strlen(s)-1] =='\n'){
			s[strlen(s)-1]=0;
		}
		if(es_decimal(s)){
			valor=atof(s);
			if(valor<inferior || valor>superior){
				printf("Dato invalido!!! Debe estar entre (%.2f-%.2f). Vuelva a introducirlo: \n",inferior,superior);
			}
		}
		else{
			printf("Dato invalido!!! Debe ser un numero decimal. Vuele a intentarlo:\n");
		}
	}while(valor<inferior || valor>superior);
	return valor;
}

int leerd(char *mensaje, int inferior, int superior){//funcion ára validar numeros enteros 
	int valor=superior+1;
	char s[10];
	do{
		printf(mensaje);
		fflush(stdin);
		fgets(s,10,stdin);
		fflush(stdin);
		if(s[strlen(s)-1] =='\n'){
			s[strlen(s)-1]=0;
		}
		if(es_entero(s)){
			valor=atoi(s);
			if(valor<inferior || valor>superior){
				printf("Dato invalido!!! Debe estar entre (%d-%d). Vuelva a introducirlo: \n",inferior,superior);
			}
		}
		else{ printf("Dato invalido!!! Debe ser un numero entero. Vuele a intentarlo:\n");
		}
	}while(valor<inferior || valor>superior);
	return valor;
}

//funciones de calidacion de enteros y flotantes
/*tomados de http://www.programacionenc.net/index.php?option=com_content&view=article&id=125:verificar-si-el-ingreso
-de-teclado-es-un-entero-o-decimal&catid=31:general&Itemid=41*/
int es_entero(char *cadena){//funcion que ayuda a leerd a que solo sean numeros enteros, si se llega a poner un otro caracter lo marca como dato invalido
	int i, valor;
		for(i=0; i < strlen(cadena); i++){
      		valor = cadena[ i ] - '0';
				if(valor < 0 || valor > 9){
					if(i==0 && valor==-3) continue;
					return 0;
      			}
   		}
   return 1;
}

int es_decimal(char *cadena){//funcion que ayuda a leerd a que solo sean numeros con decimales, si se llega a poner un otro caracter lo marca como dato invalido
   int i, valor;
   int tiene_punto = 0;
   for(i=0; i < strlen(cadena); i++){
		valor = cadena[ i ] - '0';
			if(valor < 0 || valor > 9){
				/* El primer caracter es: - */
				if(i==0 && valor==-3) continue;
					/* Verifica que solo tenga un: . */
					if(valor==-2 && !tiene_punto){ 
						tiene_punto=1;
            			continue;
         			}
    					return 0;
      			}
   }
   return 1;
}
