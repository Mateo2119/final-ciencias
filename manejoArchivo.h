#ifndef MANEJOARCHIVO_H
#define MANEJOARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include "estructuras.h"
#include "lista.h"
using namespace std;
fstream archivo;

using namespace std;
template <class T>

template <class T>

class manejoArchivo{
	  
      public: manejoArchivo(){	  		
		}
             void escritura(string nombreArchivo, dato);
             void lista<T> archivoALista(string tipoArchivo, string carpeta, string codigoGrupo, int numeroParcial);
             
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

lista<T> manejoArchivo<T>::archivoALista(string tipoArchivo, string carpeta, string codigoGrupo, int numeroParcial) {

	archivo.open("./archivos/"+carpeta+"/"+tipoArchivo, ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";		
	} else {
		switch(carpeta){
			case "archivosBase":
					switch(tipoArchivo){
						case "archivosPorCurso":
							break;
						case "cortesDeNotas":
							break;
						case "estructuraCorte":
							break;
						case "estudiantePorCurso":
							break;
						case "profesores":
							break;
						case "profesorPorCurso":
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
