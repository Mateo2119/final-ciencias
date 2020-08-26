#ifndef CLASECORTESDENOTAS_H
#define CLASECORTESDENOTAS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "estructuras.h"
#include "lista.h"
#include "temas.h"

class claseCortesDeNotas{
	  manejoArchivo manejo_archivo;
	  conversiones conversiones_tipos;
      public: claseCortesDeNotas(){}
				void registroCortesDeNotas(string codigoCurso, int numeroCortes, string cedula);
	  	     
	  private:
      		  lista<preguntas> registrarPreguntasPorActividad(int cantPreg,string nombreArchivo);
};

void claseCortesDeNotas:: registroCortesDeNotas(string codigoCurso, int numeroCortes,string cedula){
	char prefijoCorte = 'C';
	string nombreArchivoCorte=codigoCurso+"_corteDeNotas_"+cedula;
	string lineaArchivoCorte;
	string lineaDeEvaluaciones;	
	string lineaPreguntas =codigoCurso+"_"+"corte";	
	cortesDeNotas objCortes;
	lista<apuntadorCorte> listaApuntadoresCortesDeNotas;
	apuntadorCorte *arregloDeCortes;
	apuntadorEvaluacion *arregloDeEvaluaciones;
					
	cout<<"\n Configuracion esquema de corte para profesor \n";
					
	for(int c=1;c<=numeroCortes;c++) {
		lineaArchivoCorte+=prefijoCorte+"\n";
		int cantAct;
		int cantEval;
		cout<<"Ingrese la cantidad de actividades que realizara para cada corte";
		cin>>cantAct;
		for(int cort=1; cort<=cantAct;cort++){
			corte objCorte;
			cout<<"Ingrese el nombre de la actividad \n";
			cin>>objCorte.tipoEvaluacion;
			cout<<"Ingrese el porcentaje para la actividad \n";
			cin>>objCorte.porcentaje;
			objCorte.porcentaje+="%";
			cout<<"Ingrese la cantidad de "<<objCorte.tipoEvaluacion<<" a realizar \n";
			cin>>cantEval;
			lineaArchivoCorte+= objCorte.tipoEvaluacion+" "+objCorte.porcentaje+" ";
			lista<evaluacion> listaEvaluaciones;
			
			for(int eval = 1; eval<=cantEval; eval++){
				int cantPreg;
				string fecha;
				evaluacion objEvaluacion;
								
				cout<<"Ingrese la fecha de realizacion de la "<< eval<<" actividad \n";
				cout<<"digitar en formato (dia/mes/anio) \n";
				cin>>objEvaluacion.fecha;
				cout<<"Ingrese la cantidad de preguntas a relizar en la "<<eval+1<<" actividad \n";
				cin>>cantPreg;
				lineaPreguntas+=conversiones_tipos.toString(c)+"_"+objCorte.tipoEvaluacion+conversiones_tipos.toString(cort)+"_preguntas.txt";
				lista<preguntas> listaPreguntas = registrarPreguntasPorActividad(cantPreg,lineaPreguntas);
				objEvaluacion.preguntaSig = listaPreguntas;
				listaEvaluaciones.lista_vacia()? listaEvaluaciones.insertar_inicio(objEvaluacion): listaEvaluaciones.insertar_final(objEvaluacion);
				lineaDeEvaluaciones+=objEvaluacion.fecha+" "+lineaPreguntas+",";							 
			}
			
				lineaArchivoCorte+=objCorte.tipoEvaluacion+" "+objCorte.porcentaje+lineaDeEvaluaciones+"\n";	
				arregloDeEvaluaciones[cort].evaluaciones = listaEvaluaciones;
				arregloDeCortes[c].arregloCorte[cort] = objCorte;
				
		}
	}
	manejo_archivo.escritura("archivoNotas/Esquema",nombreArchivoCorte,lineaArchivoCorte);
}

lista<preguntas> claseCortesDeNotas:: registrarPreguntasPorActividad(int cantPreg,string nombreArchivo){
	claseTemas claseTema;
	lista<preguntas> listaPreguntas;	
	string dato;
	int tema = 0;
	for(int preg = 0; preg<cantPreg; preg++) {
		preguntas objPreguntas;
		cout<<"Ingrese el porcentaje de la pregunta \n";
		cin>>objPreguntas.porcentajeTema;
		claseTema.imprimirListaTemas(claseTema.consultarListaTemas(tema));					
		cout<<"\n Ingrese el numero de tema a evaluar \n";
		cin>>objPreguntas.tema;
		listaPreguntas.lista_vacia()?listaPreguntas.insertar_inicio(objPreguntas):listaPreguntas.insertar_final(objPreguntas);
		dato+=objPreguntas.porcentajeTema+" "+conversiones_tipos.toString(objPreguntas.tema)+"\n";
	}
	manejo_archivo.escritura("archivoNotas/Parciales",nombreArchivo,dato);
	return listaPreguntas;
}



#endif
