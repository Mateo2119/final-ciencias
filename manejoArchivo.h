#ifndef MANEJOARCHIVO_H
#define MANEJOARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "estructuras.h"
#include "lista.h"
#include "conversiones.h"

using namespace std;



class manejoArchivo{
	  conversiones conversiones_tipos;
      public: manejoArchivo(){}
             void escritura(string carpeta,string nombreArchivo, string dato);
             void lectura(string carpeta,string nombreArchivo, ifstream& archivo);
             void concatenar(string carpeta,string nombreArchivo,string dato);
             int contadorLineas(string carpeta, string tipoArchivo);
             
	  	     
	  	     

	  	     
	  	     void impresionListaTemas(lista<temas> listaTemas);
	  	     lista<temas> consultarListaTemas(int codigoTema);
	  private:lista<cortesDeNotas> consultarCortesDeNotasPorProfesor(string cedula);
      		  
};


void manejoArchivo::lectura(string carpeta,string nombreArchivo, ifstream& archivo) {	
	string ruta = "./archivos/"+carpeta+"/"+nombreArchivo+".txt";
	archivo.open(ruta.c_str(), ios::in);
}


void manejoArchivo::escritura(string carpeta,string nombreArchivo,string dato){
	ofstream archivoEs;
	archivoEs.open(nombreArchivo.c_str(),ios::out|ios::app); 
	if (!archivoEs.fail() ){
		archivoEs<<dato;		
		archivoEs.close();
		
	}else{
		cout<<"ERROR: no se encuentra el archivo para la operacion solicitada"<<endl;		
	}
}

void manejoArchivo::concatenar(string carpeta,string nombreArchivo ,string dato){
	string ruta = "./archivos/"+carpeta+"/"+nombreArchivo+".txt";
    std::ofstream archivo(ruta.c_str(), std::ios_base::app | std::ios_base::out);
	archivo<<dato+"\n";
	archivo.close();
}

int manejoArchivo::contadorLineas(string carpeta, string tipoArchivo) {
	ifstream archivo;
	lectura(carpeta, tipoArchivo,archivo);
  	bool lineaVacia=false;
  	int contador =0;
  	string texto;
	while(!archivo.eof() && !lineaVacia){
		getline(archivo, texto);		
		if(texto.empty()){
			lineaVacia=false;
		} else {
			contador++;
		}
	}
	return contador;
}







//lista<espacio> manejoArchivo::archivoALista(string tipoArchivo, string carpeta, string codigoGrupo, int numeroParcial, int numeroCortes) {
//	ifstream archivo;
//	string texto;
//	string ruta = "./archivos/"+carpeta+"/"+tipoArchivo+".txt";
//	archivo.open(ruta.c_str(), ios::in);
//	if(archivo.fail()){
//		cout<<"No se pudo abrir el archivo";		
//	} else {
//		if(carpeta == "archivosBase"){
//			if(tipoArchivo == "archivosPorCurso"){
//				 
//			}
//			if(tipoArchivo == "estudiantePorCurso"){
////				vector<string> resultado;							
////				estudiantePorCurso auxEstudiantePorCurso;
////				estudiante auxEstudiante;					
////				lista<estudiantePorCurso> listaEstudiantePorCurso;
////				lista<estudiante> listaEstudiante;
////							
////				while(!archivo.eof()){
////					getline(archivo,texto,' ');
////					resultado.push_back(texto);
////					for(int i=0; i<resultado.size(); i++){
////						if(i==0) {
////							auxEstudiantePorCurso.codigoCurso = resultado[i];
////						}else{
////							auxEstudiante.nombreEstudiante = resultado[i];											
////						}
////					}
////				listaEstudiante.insertar_inicio(auxEstudiante);
////				auxEstudiantePorCurso.estudiante=listaEstudiante;
////					if(listaEstudiantePorCurso.lista_vacia())
////						listaEstudiantePorCurso.insertar_inicio(auxEstudiantePorCurso);
////						listaEstudiantePorCurso.insertar_final(auxEstudiantePorCurso);													
////					}
////					return listaEstudiantePorCurso;				
//			}
//			if(tipoArchivo=="profesores"){
////							vector<string> resultado;
////							profesor auxProfesor;							
////							lista<profesor> listaProfesores;
////							while(!archivo.eof()){
////								getline(archivo,texto,' ');
////								resultado.push_back(texto);
////								auxProfesor.cedula = resultado[0];
////								auxProfesor.apellidos = resultado[1];
////								auxProfesor.nombres = resultado[2];
////								auxProfesor.numeroDeClases = toInt(resultado[3]);
////								auxProfesor.listaCortesDeNotas = consultarCortesDeNotasPorProfesor(auxProfesor.cedula);
////								if(listaProfesores.lista_vacia()){
////									listaProfesores.insertar_inicio(auxProfesor);
////								}
////								listaProfesores.insertar_final(auxProfesor);
////								return listaProfesores;									
////							}				
//			}
//			if(tipoArchivo=="profesorPorCurso"){
//			}
//			if(tipoArchivo=="temas"){
////							temas auxTemas;
////							lista<temas> auxListaTemas;
////							vector<string> resultado;
////							while(!archivo.eof()){
////								getline(archivo, texto,' ');
////								resultado.push_back(texto);
////								auxTemas.codigoTema = toInt(resultado[0]);	
////								auxTemas.nombreTema = resultado[1];
////								if(auxListaTemas.lista_vacia()){
////									auxListaTemas.insertar_inicio(auxTemas);
////								}
////								auxListaTemas.insertar_final(auxTemas);
////							}				
//			}
//		}
//		if(carpeta == "archivosNotas"){
//			
//		}
//		if(carpeta == "consolidado"){
////					if(tipoArchivo.rfind("Parcial",0)){
////						
////					}
//		}
//
//	}
//}

//revision

//lista<espacio> manejoArchivo::obtenerListaEspacio(string carpeta, string tipoArchivo, int numeroClases) {
//	ifstream archivo;								
//	espacio arregloEspacio[numeroClases];
//	string ruta = "./archivos/"+carpeta+"/"+tipoArchivo+".txt";
//	archivo.open(ruta.c_str(), ios::in);	
//	
//	if(archivo.fail()){
//	} else {
//	while(!archivo.eof()){
//		vector<string> resultado;
//		string texto;
//		apuntArchivos *auxApuntArchivos;
//		apuntArchivos tempApuntArchivos;
//		lista<archivosEntrega> listaAuxArchivo;
//		archivosEntrega auxArchivo;
//		espacio auxEspacio;		
//		getline(archivo,texto);		
//		resultado = obtenerVector(texto);
//
//		for(int i=0; i<resultado.size(); i++){				
//				if(i==0) {
//					auxEspacio.codigoEspacio = resultado[i];	
//				}else{
//					auxArchivo.nombreArchivo = resultado[i];
//					listaAuxArchivo.lista_vacia()? listaAuxArchivo.insertar_inicio(auxArchivo):listaAuxArchivo.insertar_final(auxArchivo);					
//				}
//		}
//		tempApuntArchivos.listaArchivos = listaAuxArchivo;
//		auxApuntArchivos = &tempApuntArchivos;
//		auxEspacio.archivosEntrega=auxApuntArchivos;
//		//listaEspacio.lista_vacia()? listaEspacio.insertar_inicio(auxEspacio):listaEspacio.insertar_final(auxEspacio);			
//	}
//	//return listaEspacio;
//	}
//}

//lista<cortesDeNotas> consultarCortesDeNotasPorProfesor(string cedula){
//	string ruta = "./archivos/archivosNotas/Esquema/cortesDeNotas_"+cedula+".txt";
//	lista<cortesDeNotas> auxListaCortesDeNotas;
//	lista <corte> auxListaCortes;	
//	cortesDeNotas auxCorteDeNotas;
//	corte auxCorte;
//	ifstream archivo;
//	string texto;
//	string textoLinea;
//	string textoPregunta;
//	vector<string> resultado;
//	vector<string> resultadoLinea;
//	vector<string> resultadoPregunta;
//	lista<evaluacion> auxListaEvaluaciones;
//	evaluacion auxEvaluacion;
//	apuntadorEva *auxApuntadorEva;
//	
//	archivo.open(ruta.c_str(), ios::in);
//	if(archivo.fail()){
//		//crear archivo
//	} else {
//		int cont = 0;
//		while(!archivo.eof()){
//			getline(archivo,texto,' ');
//			resultado.push_back(texto);
//			for(int i=0; i<resultado.size(); i++){
//				if(i==0 && resultado[0] == "C"){
//					cont++;
//					if(cont>1){
//						if(auxListaCortesDeNotas.lista_vacia()) {
//							auxListaCortesDeNotas.insertar_inicio(auxCorteDeNotas);
//						}
//						auxListaCortesDeNotas.insertar_final(auxCorteDeNotas);
//					}
//				}
//				if(i==0 && resultado[0] != "C") {
//					auxCorte.tipoEvaluacion = resultado[i];
//				}
//				if(i==1){
//					auxCorte.porcentaje = resultado[i];
//				}
//				if(i>1) {
//					std::stringstream r1(resultado[i]);
//					getline(r1,textoLinea,',');
//					resultadoLinea.push_back(textoLinea);
//					for(int j=0; j<resultadoLinea.size(); j++){
//						std::stringstream r2(resultadoLinea[j]);
//						getline(r2,textoPregunta,':');
//						resultadoPregunta.push_back(textoPregunta);
//						auxEvaluacion.fecha = resultadoPregunta[0];
//						auxEvaluacion.porcentajeTema = resultadoPregunta[1];
//						auxEvaluacion.tema = toInt(resultadoPregunta[2]);
//						
//						if(!j+1==resultadoLinea.size()){
//							evaluacion *temp;
//							temp->fecha = resultadoPregunta[0];
//							temp->porcentajeTema = resultadoPregunta[1];
//							temp->tema = toInt(resultadoPregunta[2]);							
//							auxEvaluacion.preguntaSig = temp;
//						}
//					}
//					if(auxListaEvaluaciones.lista_vacia()){
//						auxListaEvaluaciones.insertar_inicio(auxEvaluacion);
//					}
//					auxListaEvaluaciones.insertar_final(auxEvaluacion);
//					auxApuntadorEva->evaluaciones = auxListaEvaluaciones;
//					auxCorte.apuntadorEva = auxApuntadorEva;
//					if(auxListaCortes.lista_vacia()){
//						auxListaCortes.insertar_inicio(auxCorte);
//					}
//					auxListaCortes.insertar_final(auxCorte);
//				}	
//								
//			}
//			auxCorteDeNotas.listaCortes = auxListaCortes;	
//			
//		}
//	
//	}
//	return auxListaCortesDeNotas;
//
//}



#endif
