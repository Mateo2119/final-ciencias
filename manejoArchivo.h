#ifndef MANEJOARCHIVO_H
#define MANEJOARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "estructuras.h"
#include "lista.h"


using namespace std;


template <class T>
class manejoArchivo{
	  
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
	char* ruta = "./archivos/"+carpeta+"/"+tipoArchivo+".txt";
	archivo.open(ruta, ios::in);
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
								  		if(i==1) {
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
								  	if(listaEspacio.lista_vacia())
								  		listaEspacio.insertar_inicio(auxEspacio);
								  	listaEspacio.insertar_final(auxEspacio);													
								}
							return listaEspacio;
							break;
						}						
							
						case "estudiantePorCurso":{
							vector<string> resultado;							
							estudiante auxEstudiante;					
							lista<estudiante> listaEstudiante;
							
							while(!archivo.eof()){
								getline(archivo,texto,' ');
								  resultado.push_back(texto);
								  for(int i=0; i<resultado.size(); i++){
								  		if(i==1) {
								  			auxEstudiante.codigoCurso = resultado[i];
										}else{
											auxEstudiante.nombreEstudiante = resultado[i];
										}
								  	}
								  	if(listaEstudiante.lista_vacia())
								  		listaEstudiante.insertar_inicio(auxEstudiante);
								  	listaEstudiante.insertar_final(auxEstudiante);	
							}
							return listaEstudiante;
							break;
						}
						case "profesores":{
							while(!archivo.eof()){
									
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




#endif
