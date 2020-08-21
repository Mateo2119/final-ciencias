#ifndef MANEJOARCHIVO_H
#define MANEJOARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "estructuras.h"
#include "lista.h"


using namespace std;


int toInt(string i){
   stringstream ss(i);
   int x = 0;
   ss << x;
   return x;
}

template <class T>
class manejoArchivo{
	  char IndicativoParcial='P';
      public: manejoArchivo(){}
             void escritura(string nombreArchivo, string dato);
             void archivoALista(string tipoArchivo, string carpeta, string codigoGrupo, int numeroParcial);
             
};

template <class T>
void manejoArchivo<T>::escritura(string nombreArchivo,string dato){
	ofstream archivoEs;
	archivoEs.open(nombreArchivo.c_str(),ios::out|ios::app); 
	if (!archivoEs.fail() ){
		archivoEs<<dato;		
		archivoEs.close();
		
	}else{
		cout<<"ERROR: no se encuentra el archivo para la operacion solicitada"<<endl;		
	}
}

template <class T>
void manejoArchivo<T>::archivoALista(string tipoArchivo, string carpeta, string codigoGrupo, int numeroParcial) {
	ifstream archivo;
	string texto;
	string ruta = "./archivos/"+carpeta+"/"+tipoArchivo+".txt";
	archivo.open(ruta.c_str(), ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";		
	} else {
		switch(carpeta){
			case "archivosBase":
					switch(tipoArchivo){
						case "archivosPorCurso":{
							vector<string> resultado;
							archivosEntrega *auxArchivo;
							espacio auxEspacio;					
							lista<espacio> listaEspacio;							
							while(!archivo.eof()){
								  getline(archivo,texto,' ');
								  resultado.push_back(texto);
								  	for(int i=0; i<resultado.size(); i++){
								  		if(i==0) {
								  			auxEspacio.codigoEspacio = resultado[i];
										}else{
											archivosEntrega *temp=NULL;
											auxArchivo->nombreArchivo = resultado[i];
											if(!i+1==resultado.size()){
												temp->nombreArchivo = resultado[i+1];
												auxArchivo->archivoSig = temp;												
											}
											auxArchivo->archivoSig=NULL;
										}
								  	}
								  	auxEspacio.archivosEntrega=auxArchivo;
								  	if(listaEspacio.lista_vacia())
								  		listaEspacio.insertar_inicio(auxEspacio);
								  	listaEspacio.insertar_final(auxEspacio);													
								}
							return listaEspacio;
							break;
						}						
							
						case "estudiantePorCurso":{
							vector<string> resultado;							
							estudiantePorCurso auxEstudiantePorCurso;
							estudiante auxEstudiante;					
							lista<estudiantePorCurso> listaEstudiantePorCurso;
							lista<estudiante> listaEstudiante;
							
							while(!archivo.eof()){
								  getline(archivo,texto,' ');
								  resultado.push_back(texto);
								  for(int i=0; i<resultado.size(); i++){
								  		if(i==0) {
								  			auxEstudiantePorCurso.codigoCurso = resultado[i];
										}else{
											auxEstudiante.nombreEstudiante = resultado[i];											
										}
								  	}
								  	listaEstudiante.insertar_inicio(auxEstudiante);
								  	auxEstudiantePorCurso.estudiante=listaEstudiante;
								  	if(listaEstudiantePorCurso.lista_vacia())
								  		listaEstudiantePorCurso.insertar_inicio(auxEstudiantePorCurso);
								  	listaEstudiantePorCurso.insertar_final(auxEstudiantePorCurso);													
								}
							return listaEstudiantePorCurso;
							break;
						}
						case "profesores":{
							vector<string> resultado;
							profesor auxProfesor;
							lista <cortesDeNotas> listaCortesDeNotas;
							lista<profesor> listaProfesores;
							while(!archivo.eof()){
								getline(archivo,texto,' ');
								resultado.push_back(texto);
								for(int i=0; i<resultado.size(); i++){
								  	if(i==0) {
								  		auxProfesor.cedula = resultado[i];
									}
									if(i==1){
										auxProfesor.apellidos = resultado[i];
									}
									if(i==2){
										auxProfesor.nombres = resultado[i];
									}
									if(i==3){
										auxProfesor.numeroDeClases = toInt(resultado[i]);
									}
								}
																	
							}
							break;
						}
						case "profesorPorCurso":{
							while(!archivo.eof()){
									
							}
							break;
						}		
								
					}
				break;
			case "archivosNotas":
				break;
			case "consolidado":
				break;
		}
	}
}

lista<cortesDeNotas> consultarCortesDeNotasPorProfesor(string cedula){
	string ruta = "./archivos/archivosNotas/Esquema/cortesDeNotas_"+cedula+".txt";
	lista<cortesDeNotas> listaCortesDeNotas;
	lista <corte> listaCortes;
	corte auxCorte;
	ifstream archivo;
	string texto;
	vector<string> resultado;
	
	archivo.open(ruta.c_str(), ios::in);
	if(archivo.fail()){
		//crear archivo
	} else {
		while(!archivo.eof()){
			getline(archivo,texto,' ');
			resultado.push_back(texto);
			
		}
		
		
	}
	
}

lista<corte> consultarEstructuraDeNotasPorProfesor(string cedula) {
	string ruta = "./archivos/archivosNotas/Esquema/estructuraDeNotas_"+cedula+".txt";
	lista<evaluacion> evaluaciones;
	evaluacion *auxEvaluacion;
	evaluacion *temp;
}




#endif
