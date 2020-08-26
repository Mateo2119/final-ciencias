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
#include "manejoarchivo.h"
#include "estructuras.h"
#include "lista.h"
#include "profesor.h"
#include "curso.h"
#include "clases.h"
#include "cola.h"
using namespace std;

int numeroCortes = 3;
//numero evaluaciones por consola
//numero de espacios (consulta x profesor)

lista <profesor> listaProfesores;
lista <temas> temas;
lista <corte> listaCortes;
lista <cortesDeNotas> listaCortesDeNotas;
lista <evaluacion> evaluaciones;
clase *arregloClases;



/*string fechaActual(char fecha){
  	struct tm *tm;
	strptime(fecha.c_str(), 11, "%d/%m/%Y", tm);
	return fecha;
}
*/



void subMenuJefeSeccion();
void menuPrincipal();
void consultaProEstudianteEnCurso(string codigoCurso,string nombreEstudiante);
void consultaComProEstudiantesEnCurso(string codigoCurso);
void consultaComProEstudiantesEnProfesor(string celProfesor);
void consultarListaProfesoresNumeroDeClases(int NumClases);
void consultarListaEstudiantesNotaSuperior(float nota);
void subMenuDirector();
void subMenuProfesor();
void generarConsolidado();

//-------
int main(int argc, char** argv) {
	manejoArchivo manejo_archivo;
	menuPrincipal();
	return 0;
}
//-------
void menuPrincipal(){
	system("cls");	
	cout<<"MENU PRINCIPAL\n"<<endl;
	cout<<"Bienvenido al sistema de seguimiento, seleccione una opcion.\n"
		  "1. Loguearse como director de area.\n"
		  "2. Loguearse como profesor.\n"
		  "3. Loguearse como jefe de seccion.\n";
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{
		
		cin>>opcion;
		switch(opcion){
				
			case 1:	{
				subMenuDirector();				
				break;
			}
			case 2:
				subMenuProfesor();
				break;
			case 3:	
				subMenuJefeSeccion();
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
		  "5. Consultar lista de estudiantes con nota superior a la nota indicada\n";
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{
		
		cin>>opcion;
		switch(opcion){
				
			case 1:	{
				clase *auxArregloClases;
				string codigoCurso;
				string nombreEstudiante;
				
   				cout<<"Digite el codigo del curso"<<endl;
				cin>>codigoCurso;
				cout<<"Digite el nombre del estudiante"<<endl;
				cin>>nombreEstudiante;
				consultaProEstudianteEnCurso (codigoCurso,nombreEstudiante);
				break;
			}							
				
			case 2:{
				string codigoCurso;
				cout<<"Digite el codigo del curso"<<endl;
				cin>>codigoCurso;
				consultaComProEstudiantesEnCurso(codigoCurso);
				break;
			}
				
			case 3:	{
				string celProfesor;
				cout<<"Digite la cedula del profesor"<<endl;
				cin>>celProfesor;
				consultaComProEstudiantesEnProfesor(celProfesor);
				break;
			}
				
			case 4:	{
				int NumClases;
				cout<<"Digite el numero de clases que puede pertenecer al profesor"<<endl;
				cin>>NumClases;
				consultarListaProfesoresNumeroDeClases(NumClases);
				break;
			}
					
			case 5:	{
				float nota;
				cout<<"Digite la nota para la consulta"<<endl;
				cin>>nota;
				consultarListaEstudiantesNotaSuperior(nota);
				break;
			}
							
		}
	}while(opcion!=0);
}

void subMenuProfesor() {
	system("cls");
	
	cout<<"Bienvenido profesor, seleccione una opcion.\n"
		  "1. Modificar esquema propuesto para corte\n";
		  
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{
		if(opcion!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		
		cin>>opcion;
		switch(opcion){

			case 1:	{
				break;
			}							
						
		}
	}while(opcion!=0);
}

void subMenuJefeSeccion(){
	system("cls");	
	cout<<"Bienvenido, seleccione una opcion.\n"
		  "1. Registrar un nuevo profesor\n"
		  "3. Registrar un nuevo tema\n"
		  "4. Registrar un nuevo espacio\n"
		  "5. Registrar notas parcial\n";
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{		
		cin>>opcion;
		switch(opcion){				
			case 1:	{
					profesor auxProf;
					claseProfesor claseProfesor;
					claseCurso claseCurso;
					claseClases claseClase;
					cout<<"Digite la cedula del profesor\n";
					cin>>auxProf.cedula;
					cout<<"Digite apellidos\n";
					cin>>auxProf.apellidos;
					cout<<"Digite nombres\n";
					cin>>auxProf.nombres;
					cout<<"Digite cantidad de cursos que dictara\n";
					cin>>auxProf.numeroDeClases;	

					//registro Profesor Archivo

					claseProfesor.registroProfesor(auxProf);
					
					//consulta numero de cursos registrados
					int numeroLineas = manejo_archivo.contadorLineas("archivosBase","archivosPorCurso");
										
					cout<<"Estos son los cursos registrados hasta el momento \n";
					
					//impresion de cursos registrados
					claseCurso.imprimirCursos(numeroLineas,claseCurso.consultarCursos(numeroLineas));
					
					//registro Clases profesor
		
					cout<<"Escriba los "<<auxProf.numeroDeClases<<" cursos a registrar para el profesor \n";
			
					
					claseClase.registrarClases(auxProf.numeroDeClases, auxProf.cedula);

					//--------------------
					//cortes
					//arreglo de tipo cortes de notas[varibale constante]
					//
					
					cout<<"\n Configuracion esquema de corte para profesor \n";
					
					
				break;
			}			
			case 2:{
				break;
			}
				
			case 3:	{
				break;
			}
				
			case 4:{
//				manejoArchivo m;
//				
//				lista<espacio> auxesp = m.obtenerListaEspacio("archivosBase","archivosPorCurso",5);
//				int tam = auxesp.obtenerTamano();
//				cout<<tam;
//				for(int i=0; i<tam; i++){
//					espacio auxEspacio = auxesp.imprimir(i);
//					apuntArchivos a = *auxEspacio.archivosEntrega;
//					
//					cout<<auxEspacio.codigoEspacio;
//					int x = a.listaArchivos.obtenerTamano();
//					for(int p=0; p<x;p++ ){
//						archivosEntrega f = a.listaArchivos.imprimir(p);
//						cout<<f.nombreArchivo;
//					}
//					cout<<"\n";
//				} 
				break;
			}
										
		}
	}while(opcion!=0);
}
void consultaProEstudianteEnCurso (string codigoCurso,string nombreEstudiante){
}

void consultaComProEstudiantesEnCurso(string codigoCurso) {
	
}

void consultaComProEstudiantesEnProfesor(string celProfesor) {
	
}

void consultarListaProfesoresNumeroDeClases(int NumClases){
	
}

void consultarListaEstudiantesNotaSuperior(float nota){
	
}

void generarConsolidado(){	
}



	
