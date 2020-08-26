#ifndef CLASECLASES_H
#define CLASECLASES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "estructuras.h"
#include "lista.h"
#include "curso.h"

 
class claseClases{
	claseCurso clase_curso;
	manejoArchivo manejo_archivo;
	conversiones conversiones_tipos;
      public: claseClases(){}
				clase * consultarClases(); 
				vector<string> registrarClases(int numeroClases, string cedula);
	  	     	
	  private:
	  			
      		  
};

clase * claseClases::consultarClases() {
	
	int numero = manejo_archivo.contadorLineas("archivosBase","profesorPorCurso");
	ifstream archivo;
	manejo_archivo.lectura("archivosBase","profesorPorCurso",archivo);
	clase arregloClase[numero];
	clase *auxArreglo;

	int contador=0;
	bool lineaVacia=false;
	
	while(!archivo.eof() && !lineaVacia){
		vector<string> resultado;
		string texto;
		clase auxClase;						
		getline(archivo,texto);	
		if(texto.empty()){
			lineaVacia=true;
		} else {
			resultado = conversiones_tipos.obtenerVector(texto);		
			int valor = resultado.size()-1;
			espacio tempAEspacio[valor];
			espacio *auxEspacio;	
		
			for(int i=0; i<resultado.size(); i++){				
				if(i==0) {
					auxClase.cedula = resultado[i];	
				}else{
					espacio tempEspacio;
					apuntArchivos tempApunt;
					apuntArchivos *auxApuntArchivos;
										
					tempEspacio.codigoEspacio = resultado[i];
					
					lista<archivosEntrega> listaArchivos = clase_curso.consultarArchivosPorCurso(tempEspacio.codigoEspacio);
					
					tempApunt.listaArchivos = listaArchivos;
					
					auxApuntArchivos = &tempApunt;
					
					tempEspacio.archivosEntrega = auxApuntArchivos;
					
					tempAEspacio[i-1] = tempEspacio;					
									
				}
			}
			auxEspacio= new espacio[valor];
			auxEspacio = tempAEspacio;
			auxClase.arregloEspacios =auxEspacio;
			arregloClase[contador] = auxClase;
			contador++;
		}		
	}	 
	auxArreglo = arregloClase;
	return auxArreglo;
}

vector<string> claseClases::registrarClases(int numeroClases, string cedula){

	vector<string> cursos;
	string lineaProfesorClase = cedula+" ";
	espacio arregloEspacio[numeroClases];	
	espacio *auxArregloEspacio;	
				
	for(int i=0;i<numeroClases; i++){
		string codigoCurso;
		espacio tempEspacio;
		apuntArchivos aa;
		apuntArchivos *a;
		cout<<"por favor digite el "<<i+1<<" codigo de curso: ";
		cin>>codigoCurso;
		cursos.push_back(codigoCurso);
		aa.listaArchivos = clase_curso.consultarArchivosPorCurso(codigoCurso);
		a=&aa;
		tempEspacio.archivosEntrega = a;
		tempEspacio.codigoEspacio= codigoCurso;
		arregloEspacio[i] = tempEspacio;						
		lineaProfesorClase+= codigoCurso+" ";
	}					

	//registrar en archivo profesor por curso
	manejo_archivo.concatenar("archivosBase","profesorPorCurso",lineaProfesorClase);
	return cursos;
}


#endif
