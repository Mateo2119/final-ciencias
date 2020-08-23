#ifndef MANEJOARCHIVO_H
#define MANEJOARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "estructuras.h"
#include "lista.h"


using namespace std;


int toInt(string i){
   stringstream ss(i);
   int x = 0;
   ss << x;
   return x;
}

float toFloat(string i){
   stringstream ss(i);
   float x = 0;
   ss << x;
   return x;
}


class manejoArchivo{
	  
      public: manejoArchivo(){}
             void escritura(string carpeta,string nombreArchivo, string dato);
             void concatenar(string carpeta,string nombreArchivo,string dato);
             //lista<espacio> archivoALista(string tipoArchivo, string carpeta, string codigoGrupo, int numeroParcial, int numeroCortes);
     		 //lista<espacio> obtenerListaEspacio(string carpeta, string tipoArchivo,int numeroClases);
	  	     clase * consultarClases(string carpeta, string tipoArchivo, int numero);
	  	     int contadorLineas(string carpeta, string tipoArchivo);
	  	     lista<archivosEntrega> consultarArchivosPorCurso(string codigoCurso);
	  	     espacio * consultarCursos(int numeroLineas);
	  	     
	  private:lista<cortesDeNotas> consultarCortesDeNotasPorProfesor(string cedula);
      		  
};


vector<string> obtenerVector(string cadena){
	vector<string> result;
	string textoLinea;
	std::stringstream ss(cadena);
	while(getline(ss,textoLinea,' ')){
			result.push_back(textoLinea);		
	}
	return result;
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
	archivo<<dato;
	archivo.close();
}

int manejoArchivo::contadorLineas(string carpeta, string tipoArchivo) {

	string ruta = "./archivos/"+carpeta+"/"+tipoArchivo+".txt";	
	std::ifstream inFile(ruta.c_str()); 
  	return std::count(std::istreambuf_iterator<char>(inFile), 
             std::istreambuf_iterator<char>(), '\n')+1;
}

espacio * manejoArchivo::consultarCursos(int numeroLineas){	
	espacio arregloEspacios [numeroLineas];
	espacio *auxArreglo;
	ifstream archivo;
	string texto;
	string textoLinea;
	string ruta = "./archivos/archivosBase/archivosPorCurso.txt";
	archivo.open(ruta.c_str(), ios::in);
	int contador = 0;
	while(!archivo.eof()){
		vector<string> resultado;
		lista<archivosEntrega> listaArchivos;
		archivosEntrega auxArchivo;
		espacio auxEspacio;
		apuntArchivos *auxApunt;
		apuntArchivos tempApunt;
		getline(archivo,texto);
		resultado = obtenerVector(texto);
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
	auxArreglo = new espacio[contador];
	auxArreglo = arregloEspacios;
	return auxArreglo;
}


lista<archivosEntrega> manejoArchivo::consultarArchivosPorCurso(string codigoCurso){
	vector<string> resultado;
	archivosEntrega auxArchivo;
	lista<archivosEntrega> listaArchivos;
	ifstream archivo;
	string texto;
	string textoLinea;
	string ruta = "./archivos/archivosBase/archivosPorCurso.txt";
	archivo.open(ruta.c_str(), ios::in);
	while(!archivo.eof()){
		getline(archivo,texto);
		if(texto.rfind(codigoCurso,0)){
			std::stringstream r1(texto);
			getline(r1,textoLinea,' ');
			resultado.push_back(textoLinea);
			for(int i=1; i<resultado.size(); i++){
				auxArchivo.nombreArchivo = resultado[i];
				listaArchivos.lista_vacia()? listaArchivos.insertar_inicio(auxArchivo):listaArchivos.insertar_final(auxArchivo);		
			}			
		}
	}
	return listaArchivos;
}

clase * manejoArchivo::consultarClases(string carpeta, string tipoArchivo, int numero) {
	ifstream archivo;
	string texto;
	clase arregloClase[numero];
	clase *auxArreglo;
	string ruta = "./archivos/"+carpeta+"/"+tipoArchivo+".txt";
	archivo.open(ruta.c_str(), ios::in);
	int contador=0;
	
	while(!archivo.eof()){
		vector<string> resultado;
		string texto;
		clase auxClase;				
		getline(archivo,texto);		
		resultado = obtenerVector(texto);
		espacio auxEspacio[resultado.size()-1];	
		for(int i=0; i<resultado.size(); i++){				
				if(i==0) {
					auxClase.cedula = resultado[i];	
				}else{
					espacio tempEspacio;
					apuntArchivos *auxApuntArchivos;					
					tempEspacio.codigoEspacio = resultado[i];
					lista<archivosEntrega> listaArchivos = consultarArchivosPorCurso(tempEspacio.codigoEspacio);
					auxApuntArchivos->listaArchivos = listaArchivos;
					tempEspacio.archivosEntrega = auxApuntArchivos;
					auxEspacio[i-1] = tempEspacio;					
									
				}
		}
		auxClase.arregloEspacios = auxEspacio;
		arregloClase[contador] = auxClase;
		contador++;
	}	
	auxArreglo= arregloClase;
	return auxArreglo;
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
