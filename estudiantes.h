#ifndef CLASEESTUDIANTES_H
#define CLASEESTUDIANTES_H

#include <iostream>
#include <fstream>
#include <string>
#include "estructuras.h"
#include "lista.h"
#include "manejoArchivo.h"
#include "conversiones.h"



class claseEstudiantes{ 
	  manejoArchivo manejo_archivo;
	  conversiones conversiones_tipos;
      public: claseEstudiantes(){}
				void registroNotasEstudiantes(string codigoCurso, int numeroCorte);
	  	     
	  private:
      		  
};

void claseEstudiantes::registroNotasEstudiantes(string codigoCurso, int numeroCorte){
	ifstream archivo;
	
	manejo_archivo.lectura("archivosBase","estudiantePorCurso",archivo);
	bool lineaVacia = false;
	string textoLinea;
	vector<string> informacionLinea;
	vector<string> listaEstudiantes;
	string nombreArchivo=codigoCurso+"_parcial"+conversiones_tipos.toString(numeroCorte);
	string lineaArchivo;
	string nombreArchivoPregs=codigoCurso+"_corte"+conversiones_tipos.toString(numeroCorte)+"_parcial_preguntas.txt";
	int numeroPregs = manejo_archivo.contadorLineas("archivosNotas/Esquema",nombreArchivoPregs);
	
	while(!archivo.eof() && !lineaVacia){
		getline(archivo,textoLinea);
		
		if(textoLinea.empty()){
			lineaVacia=true;
		} else {
			informacionLinea = conversiones_tipos.obtenerVector(textoLinea);
			if(informacionLinea[0] == codigoCurso){
				for(int i=1; i<informacionLinea.size();i++) {
					string nombreEstudiante;
					nombreEstudiante = informacionLinea[i];
					listaEstudiantes.push_back(nombreEstudiante);				
				}
			}
		}		
		
	}
	
	for(int x=0; x<listaEstudiantes.size(); x++){
		
		lineaArchivo+=listaEstudiantes[x]+" ";
		cout<<"Para estudiante "+listaEstudiantes[x];
		for(int y=0;y<numeroPregs;y++) {
			int nota;
			cout<<"Ingrese la nota correspondiente para la pregunta "<<y;
			cin>>nota;
			lineaArchivo+=conversiones_tipos.toString(nota)+" ";
		}
		lineaArchivo+="\n";
		
	}
	manejo_archivo.concatenar("archivosNotas/Parciales",nombreArchivo, lineaArchivo);
}

#endif
