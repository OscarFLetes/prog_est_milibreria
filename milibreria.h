/* Autor:Oscar Eduardo FLetes Ixta, 07/04/22
	libreria  para funciones comunes en c
	*/
#ifndef _MILIBRERIA//creamos libreria
#define _MILIBRERIA//definimos a la libreria 
#include<stdio.h>//libreria para el cuerpo de c
#include<string.h>//libreria para uso de funciones para cadenas de caarcteres
#include<stdlib.h>//libreria para prototipos de funciones, codigo ascii, entre otras mas funciones
//prototipos
void leers(char *mensaje, char s[], int n);//llamamos a las funciones 
float leerF(char *mensaje, float inferior, float superior);//llamamos a las funciones 
int leerd(char *mensaje, int inferior, int superior);//llamamos a las funciones 
int es_entero(char *cadena);//llamamos a las funciones 
int es_decimal(char *cadena);//llamamos a las funciones 
#include "milibreria.cpp"//llamamos al archivo .cpp de la libreria 
#endif//termina la libreria 

