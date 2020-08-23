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

manejoArchivo manejo_archivo;

/*string fechaActual(char fecha){
  	struct tm *tm;
	strptime(fecha.c_str(), 11, "%d/%m/%Y", tm);
	return fecha;
}
*/
string pasarString(auto &i){
   std::stringstream ss;
   ss << i;
   return ss.str();
}

void subMenuJefeSeccion();
void menuPrincipal();
void consultaProEstudianteEnCurso();
void consultaComProEstudiantesEnCurso();
void consultaComProEstudiantesEnProfesor();
void consultarListaProfesoresNumeroDeClases();
void consultarListaEstudiantesNotaSuperior();
void subMenuDirector();
void subMenuProfesor();
void generarConsolidado();

//-------
int main(int argc, char** argv) {
	
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
				break;
			}							
				
			case 2:{
				break;
			}
				
			case 3:	{
				break;
			}
				
			case 4:	{
				break;
			}
					
			case 5:	{
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
					string lineaProfesor;
					string lineaProfesorClase;
					
					cout<<"Digite la cedula del profesor\n";
					cin>>auxProf.cedula;
					cout<<"Digite apellidos\n";
					cin>>auxProf.apellidos;
					cout<<"Digite nombres\n";
					cin>>auxProf.nombres;
					cout<<"Digite cantidad de cursos que dictara\n";
					cin>>auxProf.numeroDeClases;	
					auxProf.listaCortesDeNotas = listaCortesDeNotas;	
					
					//registroProfesorArchivo
					lineaProfesor = auxProf.cedula+" "+ auxProf.apellidos+" "+auxProf.nombres+" "+pasarString(auxProf.numeroDeClases)+"\n";
					manejo_archivo.concatenar("archivosBase","profesores", lineaProfesor);
					
					//consulta clases
					int cont = manejo_archivo.contadorLineas("archivosBase","profesorPorCurso");
					arregloClases = new clase[cont+1];					
					arregloClases = manejo_archivo.consultarClases("archivosBase","profesorPorCurso",cont);
					//
					
					int contA = manejo_archivo.contadorLineas("archivosBase","archivosPorCurso");
					espacio *arregloCursos = manejo_archivo.consultarCursos(contA);
					cout<<"Estos son los cursos registrados hasta el momento \n";
					
					for(int a=0; a<contA; a++){
						cout<<arregloCursos[a].codigoEspacio<<"\n";
					}		
					cout<<"Escriba los "<<auxProf.numeroDeClases<<" cursos a registrar para el profesor \n";
			
					lineaProfesorClase = auxProf.cedula;
					espacio arregloEspacio[auxProf.numeroDeClases];					
					for(int i=0;i<auxProf.numeroDeClases; i++){
						string codigoCurso;
						espacio tempEspacio;
						apuntArchivos aa;
						apuntArchivos *a;
						cout<<"por favor digite el primer codigo de curso";
						cin>>codigoCurso;
						aa.listaArchivos = manejo_archivo.consultarArchivosPorCurso(codigoCurso);
						a=&aa;
						tempEspacio.archivosEntrega = a;
						tempEspacio.codigoEspacio= codigoCurso;
						arregloEspacio[i] = tempEspacio;						
						lineaProfesorClase+=codigoCurso+" ";
					}
					//registrar en archivo profesor por curso
					manejo_archivo.concatenar("archivosBase","profesoresPorCurso",lineaProfesorClase);
					clase auxClase;
					auxClase.cedula = auxProf.cedula;
					auxClase.arregloEspacios = arregloEspacio;
					arregloClases[cont+1] = auxClase;
					
					cout<<arregloClases[11].cedula;
					//--------------------
					//cortes
					//arreglo de tipo cortes de notas[varibale constante]
					//
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

void consultaProEstudianteEnCurso (){
}

void consultaComProEstudiantesEnCurso() {
}

void consultaComProEstudiantesEnProfesor () {
}

void consultarListaProfesoresNumeroDeClases(){
}

void consultarListaEstudiantesNotaSuperior(){
}

void generarConsolidado(){	
}



	
