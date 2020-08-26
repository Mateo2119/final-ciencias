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
#include "temas.h"
#include "cortesDeNotas.h"
#include "estudiantes.h"
using namespace std;

int numeroCortes = 3;
//numero evaluaciones por consola
//numero de espacios (consulta x profesor)

lista <profesor> listaProfesores;
lista <temas> listaTemas;
lista <corte> listaCortes;
lista <cortesDeNotas> listaCortesDeNotas;
lista <evaluacion> evaluaciones;
clase *arregloClases;

manejoArchivo manejo_archivo;
conversiones conversiones_tipos;
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
void consultarListaProfesoresNumeroDeClases(string celProfesor);
void consultarListaEstudiantesNotaSuperior(float nota);
void consultarEstudiantes(string numCurso);
void subMenuDirector();
void subMenuProfesor();
void generarConsolidado();

//-------
int main(int argc, char** argv) {
	manejoArchivo manejo_archivo;
	menuPrincipal();
	conversiones conversionTipo;
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
		  "4. Consultar lista de cursos por numero de cedula de profesor\n"
		  "5. Consultar lista de estudiantes con nota superior a la nota indicada\n"
		  "6. Consultar estudiantes de un curso\n";
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
				string NumClases;
				cout<<"Digite el numero de cedula del profesor para ver sus cursos"<<endl;
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
			case 6:	{
				string numClase;
				cout<<"Digite el curso para ver los estudiantes"<<endl;
				cin>>numClase;
				consultarEstudiantes(numClase);
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
		  "2. Registrar un nuevo tema\n"
		  "3. Registrar un nuevo espacio\n"
		  "4. Registrar notas parcial\n";
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
					claseCortesDeNotas claseCorteDeNotas;
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
			
					
					vector<string> cursos = claseClase.registrarClases(auxProf.numeroDeClases, auxProf.cedula);

					//--------------------
					//cortes
					//
					
					for(int x=0; x<cursos.size();x++){
						cout<<"\n Configuracion esquema de corte para profesor asociado al curso "+cursos[x]+ "\n";
						claseCorteDeNotas.registroCortesDeNotas(cursos[x],numeroCortes,auxProf.cedula);
					}
	
				break;
			}			
			case 2:{
				claseTemas claseTemas;
				temas objTemas;
				int cantidadTemas;
				cout<<"Ingrese cuantos temas desea ingresar \n";
				cin>>cantidadTemas;				
				for(int i=1; i<=cantidadTemas; i++){					
					cout<<"Ingrese el nombre del tema \n";
					cin>> objTemas.nombreTema;
					objTemas.codigoTema = i;
					claseTemas.registrarTemas(objTemas);
				}
				break;
			}
				
			case 3:	{	
				claseCurso claseCurso;
				espacio objEspacio;
				int cantidadEspacios;
				cout<<"Ingrese cuantos cursos desea ingresar \n";
				cin>>cantidadEspacios;				
				for(int i=1; i<=cantidadEspacios; i++){					
					cout<<"Ingrese el codigo del espacio \n";
					cin>> objEspacio.codigoEspacio;					
					claseCurso.registroCurso(objEspacio,numeroCortes);
				}		
				break;
			}
				
			case 4:{
				string codigoCurso;
				claseEstudiantes claseEstudiante;
				int numeroCorte;
				cout<<"Por favor digite codigo de curso";
				cin>>codigoCurso;
				cout<<"Por favor digite numero de corte del parcial a registrar";
				cin>>numeroCorte;			
				claseEstudiante.registroNotasEstudiantes(codigoCurso,numeroCorte);
				break;
			}
										
		}
	}while(opcion!=0);
}

void consultaProEstudianteEnCurso (string codigoCurso,string nombreEstudiante){
		 conversiones conversionTipo;
	 vector<int> vectorPreguntas;
	 ifstream archivo;


		int numeroDeLineasDePreguntas = manejo_archivo.contadorLineas("archivosBase/", "estudiantePorCurso");
		manejo_archivo.lectura("archivosBase/", "estudiantePorCurso",archivo);
		string textoFila;
		vector<string> resultado;
		int contadorPreg = 0;
		bool lineaVacia= false;
		while(!archivo.eof() && !lineaVacia){
			getline(archivo, textoFila);
			if(textoFila.empty()){
				lineaVacia=true;
			} else {
				resultado = conversionTipo.obtenerVector((textoFila));
	  			//cout<<resultado[0]<<endl;
	  			if(resultado[0]==codigoCurso ){
	  				lineaVacia=true;
	  				cout<<"Curso Encontrado..."<<endl;
					archivo.close();
	  }
	}
   }
   
  
   manejo_archivo.lectura("archivosNotas/Parciales/",codigoCurso+"Parcial1",archivo);
   
   if(archivo.fail()){
	  cout<<"Notas no Ingresadas";
   }
	lineaVacia=false;
		while(!archivo.eof() && !lineaVacia){
			getline(archivo, textoFila);
			if(textoFila.empty()){
				lineaVacia=true;
			} else {
				resultado = conversionTipo.obtenerVector((textoFila));
	  			//cout<<resultado[0]<<endl;
	  			if(resultado[0]==nombreEstudiante){
	  				lineaVacia=true;
	  				cout<<"Estudiante Encontrado..."+resultado[0]<<endl;
					archivo.close();
			}
		}
	}
manejo_archivo.lectura("consolidado","Parcial1",archivo);
vector<int> vectorNotas;
   if(archivo.fail()){
	  cout<<"Error de notacion";
   }
	lineaVacia=false;
		while(!archivo.eof() && !lineaVacia){
			getline(archivo, textoFila);
			if(textoFila.empty()){
				lineaVacia=true;
			} else {
				resultado = conversionTipo.obtenerVector((textoFila));
				for(int i=1; i<resultado.size(); i++) {
						int cont = 1;
						int promedio[10];
						promedio[i] = conversionTipo.toInt(resultado[i]);
					  int nota = promedio[i];
    				  int sumatoria = sumatoria + nota;
					   cont ++;
					  if(cont == 10){
					  	float promedio = sumatoria/10;
					  cout<<"El Promedio del estudiante"+resultado[0]<<endl;
					  cout<<promedio<<endl;
					  }
					}
					archivo.close();
			}
		}
	


}

void consultaComProEstudiantesEnCurso(string codigoCurso) {
	
}
//---------------------------------------------------------------------------
void consultaComProEstudiantesEnProfesor(string celProfesor) {
}

void consultarListaProfesoresNumeroDeClases(string celProfesor){
	cout<<"Buscando..."<<endl;
	vector<string> cursos;
	ifstream archivo;
	conversiones conversionTipo;
	int numeroDeLineasDePreguntas = manejo_archivo.contadorLineas("archivosBase/", "profesorPorCurso");
	manejo_archivo.lectura("archivosBase/", "profesorPorCurso",archivo);
	string textoFila;
	vector<string> resultado;
	bool lineaVacia = false;
	bool siguiente = true;
	while(!archivo.eof() && !lineaVacia){
			getline(archivo, textoFila);
			if(textoFila.empty()){
				lineaVacia=true;
			} else {
				resultado = conversionTipo.obtenerVector((textoFila));
	  			if(resultado[0]==celProfesor ){
	  				lineaVacia=true;
	  				cout<<"Cursos del profesor: "<<endl;
	  				int i = 1;
	  				while(siguiente){
	  					cout<<"		"<<resultado[i]<<endl;
	  					if(resultado[i+1] == ""){
	  						siguiente = false;
						  }
						i++; 
					  }
	  				//cout<<"ejemplo: "<<resultado[1];
					archivo.close();
	  			}
			}
	}
}

void consultarListaEstudiantesNotaSuperior(float nota){
	
}
void consultarEstudiantes(string numCurso){
	cout<<"... "<<endl;
	vector<string> estudiantes;
	ifstream archivo;
	conversiones conversionTipo;
	int numeroDeLineasDePreguntas = manejo_archivo.contadorLineas("archivosBase/", "estudiantePorCurso");
	manejo_archivo.lectura("archivosBase/", "estudiantePorCurso",archivo);
	string textoFila;
	bool lineaVacia = false;
	bool siguiente = true;
	while(!archivo.eof() && !lineaVacia){
			getline(archivo, textoFila);
			if(textoFila.empty()){
				lineaVacia=true;
			} else {
				estudiantes = conversionTipo.obtenerVector((textoFila));
	  			if(estudiantes[0]==numCurso ){
	  				lineaVacia=true;
	  				cout<<"Estudiantes: "<<endl;
	  				int i = 1;
	  				while(siguiente){
	  					cout<<"		"<<estudiantes[i]<<endl;
	  					if(estudiantes[i+1] == ""){
	  						siguiente = false;
						  }
						i++; 
					  }
	  				//cout<<"ejemplo: "<<resultado[1];
					archivo.close();
	  			}
			}
	}
}

void generarConsolidado(){	
}



	
