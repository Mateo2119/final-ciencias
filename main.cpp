#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <string>
#include<sstream>
#include <vector>
#include "manejoarchivos.h"
#include "logicaformulario.h"
#include "estructuras.h"
#include "lista.h"

using namespace std;

int numeroCortes = 3;
//numero evaluaciones por consola
//numero de espacios (consulta x profesor)

lista <profesor> listaProfesores;
lista <temas> temas;
lista <clases> clases;
lista <corte> listaCortes;
lista <cortesDeNotas> listaCortesDeNotas;
lista <evaluacion> evaluaciones;

listaProfesores.
string fechaActual(char fecha){
  	struct tm *tm;
	strptime(fecha.c_str(), 11, "%d/%m/%Y", tm);
	return fecha;
}


void menu();

void menuPrincipal(){
	system("cls");
	
	cout<<"MENU PRINCIPAL\n"<<endl;
	cout<<"Bienvenido al sistema de seguimiento, seleccione una opcion.\n"
		  "1. Loguearse como director de area.\n"
		  "2. Loguearse como profesor.\n"
		  "3. Loguearse como jefe de seccion.\n"
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{
		if(opcion!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		
		cin>>opcion;
		switch(opcion){
				
			case 1:				
				break;
			case 2:
				break;
			case 3:	
				break;			
		}
	}while(opcion!=0);
		  
}

void subMenuDirector() {
	system("cls");
	
	cout<<"Bienvenido director de area, seleccione una opcion.\n"
		  "1. Consultar promedio de estudiante de un curso\n"
		  "2. Consultar comportamiento promedio de los estudiantes de un curso\n"
		  "3. Consultar comportamiento promedio de los estudiantes por profesor\n"
		  "4. Consultar lista de profesores por numero de clases dictadas\n"
		  "5. Consultar lista de estudiantes con nota superior a la nota indicada\n"
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{
		if(opcion!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		
		cin>>opcion;
		switch(opcion){
				
			case 1:								
				break;
			case 2:
				break;
			case 3:	
				break;	
			case 4:	
				break;	
			case 5:	
				break;			
		}
	}while(opcion!=0);
}

void subMenuJefeSeccion() {

	system("cls");
	
	cout<<"Bienvenido, seleccione una opcion.\n"
		  "1. Registrar un nuevo profesor\n"
		  "2. Registrar estructura de corte\n"
		  "3. Registrar un nuevo tema\n"
		  "4. Registrar un nuevo espacio\n"
		  "5. Registrar notas parcial\n";
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{
		if(opcion!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		
		cin>>opcion;
		switch(opcion){
				
			case 1:	
					int cedula;
					cout<<"Digite la cedula del profesor";
					cin>>cedula;
					if(listaProfesores.)						
				break;
			case 2:
				break;
			case 3:	
				break;
			case 4:
				break;			
		}
	}while(opcion!=0);
}

void subMenuProfesor() {
	system("cls");
	
	cout<<"Bienvenido profesor, seleccione una opcion.\n"
		  "1. Modificar esquema propuesto para corte\n"
		  
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{
		if(opcion!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		
		cin>>opcion;
		switch(opcion){
				
			case 1:								
				break;		
		}
	}while(opcion!=0);
}
int main(int argc, char** argv) {
	
	menu();
	return 0;
}
	
	
