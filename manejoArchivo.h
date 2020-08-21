#ifndef MANEJOARCHIVO_H
#define MANEJOARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "estructuras.h"
#include "lista.h"

fstream archivo;
using namespace std;
template <class T>


template <class T>
class manejoArchivo{
	  
      public: manejoArchivo(){}
             void escritura(string nombreArchivo, string dato);
             lista<T> archivoALista(string tipoArchivo, string carpeta, string codigoGrupo, int numeroParcial);
             
};

template <class T>
void manejoArchivo<T>::escritura(string nombreArchivo,string dato){
	archivo.open(nombreArchivo.c_str(),ios::out|ios::app); 
	if (archivo.is_open() ){
		archivo<<dato;		
		archivo.close();
		
	}else{
		cout<<"ERROR: no se encuentra el archivo para la operacion solicitada"<<endl;		
	}
}

template <class T>
lista<T> manejoArchivo<T>::archivoALista(string tipoArchivo, string carpeta, string codigoGrupo, int numeroParcial) {
	string texto;
	archivo.open("./archivos/"+carpeta+"/"+tipoArchivo, ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";		
	} else {
		switch(carpeta){
			case "archivosBase":
					switch(tipoArchivo){
						case "archivosPorCurso":
							vector<string> resultado;
							archivosEntrega *auxArchivo;
							espacio auxEspacio;					
							lista<espacio> listaEspacio;							
							while(!archivo.eof()){
								  getline(archivo,texto," ");
								  resultado.push_back(texto);
								  for(int i=0; i<resultado.size(); i++){
								  		if(i==1) {
								  			auxEspacio.codigoEspacio = resultado[i];
										}else{
											archivosEntrega *temp=NULL;
											auxArchivo->nombreArchivo = resultado[i];
											if(!i+1==resultado.size()){
												temp.nombreArchivo = resultado[i+1];
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
						case "cortesDeNotas":
							while(!archivo.eof()){
									
								}
							break;
						case "estructuraCorte":
							while(!archivo.eof()){
									
							}
							break;
						case "estudiantePorCurso":
							while(!archivo.eof()){
									
							}
							break;
						case "profesores":
							while(!archivo.eof()){
									
							}
							break;
						case "profesorPorCurso":
							while(!archivo.eof()){
									
							}
							break;	
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
