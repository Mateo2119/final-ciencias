#ifndef CLASECURSO_H
#define CLASECURSO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "estructuras.h"
#include "lista.h"
#include "manejoArchivo.h"
#include "conversiones.h"



class claseCurso{
	  	manejoArchivo manejo_archivo;
		conversiones conversiones_tipos;
	  
      public: claseCurso(){}
      			
				void registroProfesor(profesor objProfesor);
				void imprimirCursos(int numeroLineas, espacio *cursos);
				lista<archivosEntrega> consultarArchivosPorCurso(string codigoCurso);
	  	     	espacio * consultarCursos(int numeroLineas);
	  	     	void validarClasesSinAsignar(string codigoCurso);
	  private:
      		  
};


espacio * claseCurso::consultarCursos(int numeroLineas){

	
	ifstream archivo;
	manejo_archivo.lectura("archivosBase","archivosPorCurso",archivo);	
	espacio arregloEspacios [numeroLineas];
	espacio *auxArreglo;

	int contador = 0;
	bool lineaVacia=false;
	while(!archivo.eof() && !lineaVacia){
		string texto;
		vector<string> resultado;
		lista<archivosEntrega> listaArchivos;
		archivosEntrega auxArchivo;
		espacio auxEspacio;
		apuntArchivos *auxApunt;
		apuntArchivos tempApunt;
		getline(archivo,texto);
		if(texto.empty()){
			lineaVacia=true;
		} else {
			resultado = conversiones_tipos.obtenerVector(texto);
			for(int i=0; i<resultado.size(); i++){
				if(i==0){
					auxEspacio.codigoEspacio = resultado[i];
				}
				else{
					auxArchivo.nombreArchivo = resultado[i];
					listaArchivos.lista_vacia()? listaArchivos.insertar_inicio(auxArchivo):listaArchivos.insertar_final(auxArchivo);
					
				}
			}
			tempApunt.listaArchivos = listaArchivos;
			auxApunt = &tempApunt;
			auxEspacio.archivosEntrega =auxApunt;		 			
			arregloEspacios[contador] = auxEspacio;
			contador++;
		}		
	}
	auxArreglo = new espacio[contador];
	auxArreglo = arregloEspacios;
	return auxArreglo;
}

lista<archivosEntrega> claseCurso::consultarArchivosPorCurso(string codigoCurso){

	ifstream archivo;
	manejo_archivo.lectura("archivosBase","archivosPorCurso",archivo);
	vector<string> resultado;
	archivosEntrega auxArchivo;
	lista<archivosEntrega> listaArchivos;
	string texto;

	while(!archivo.eof()){
		getline(archivo,texto);
		if(texto.rfind(codigoCurso,0)){
			resultado = conversiones_tipos.obtenerVector(texto);
			for(int i=1; i<resultado.size(); i++){
				auxArchivo.nombreArchivo = resultado[i];
				listaArchivos.lista_vacia()? listaArchivos.insertar_inicio(auxArchivo):listaArchivos.insertar_final(auxArchivo);		
			}			
		}
	}
	return listaArchivos;
}

void claseCurso::imprimirCursos(int numeroLineas, espacio *cursos){	
	ifstream archivo;
	manejo_archivo.lectura("archivosBase","profesorPorCurso",archivo);
	bool lineaVacia=false;
	string texto;
	vector<string> resultado;
	
	for(int a=0; a<numeroLineas; a++){

		while(!archivo.eof() && !lineaVacia){
			getline(archivo,texto);
			resultado = conversiones_tipos.obtenerVector(texto);		
			if(texto.empty()){
				lineaVacia = true;
			} else {
				for(int i=1; i<resultado.size(); i++){
					
					if(resultado[i] != cursos[a].codigoEspacio){
						cout<<cursos[a].codigoEspacio<<"\n";
					}
				}
			}		
		}				
	}			
}


void claseCurso::validarClasesSinAsignar(string codigoCurso) {
	
	ifstream archivo;
	manejo_archivo.lectura("archivosBase","profesorPorCurso",archivo);
	bool lineaVacia=false;
	string texto;
	vector<string> resultado;
	while(!archivo.eof() && !lineaVacia){
		getline(archivo,texto);
		resultado = conversiones_tipos.obtenerVector(texto);		
		if(texto.empty()){
			lineaVacia = true;
		} else {
			for(int i=1; i<resultado.size(); i++){
				if(resultado[i] != codigoCurso){
					cout<<codigoCurso<<"\n";
				}
			}
		}		
	}
}

  
#endif
