#ifndef CLASETEMAS_H
#define CLASETEMAS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "estructuras.h"
#include "lista.h"
#include "manejoArchivo.h"
#include "conversiones.h"

manejoArchivo manejo_archivo;
conversiones conversiones_tipos;

class claseTemas{
	  
      public: claseTemas(){}
				lista<temas> consultarListaTemas(int codigoTema);
	  	     	void imprimirListaTemas(lista<temas> listaTemas)
	  private:
      		  
};


lista<temas> claseTemas::consultarListaTemas(int codigoTema){
	ifstream archivo;
	manejo_archivo.lectura("archivosBase", "temas",archivo);
	string texto;
	lista<temas> listaTemas;
	temas objTemas;
	int contador=0;
	bool lineaVacia=false;
	vector<string> resultado;
	
	while(!archivo.eof() && !lineaVacia){
		getline(archivo,texto);		
		string codigo = conversiones_tipos.toString(codigoTema);
		resultado = conversiones_tipos.obtenerVector(texto);
		for(int i=0; i<resultado.size(); i++) {
			if(i==0) {
				objTemas.codigoTema = toInt(resultado[0]);
				if(resultado[i] == codigo) {
					objTemas.nombreTema = resultado[1];
					listaTemas.insertar_inicio(objTemas);
					lineaVacia = true;
				}	
			} else {
				objTemas.nombreTema = resultado[i];
				listaTemas.lista_vacia() ? listaTemas.insertar_inicio(objTemas): listaTemas.insertar_final(objTemas);		
			}	
		}								 
	}	
	return listaTemas;	
}


void claseTemas::imprimirListaTemas(lista<temas> listaTemas){
	
	temas objTema;
	int numeroLineas = contadorLineas("archivosBase","temas");
	
	for(int num=0;num<numeroLineas;num++){
		objTema = listaTemas.imprimir(num);
		cout<<objTema.codigoTema<<" "<<objTema.nombreTema<<"\n";
	}
	
}

#endif
