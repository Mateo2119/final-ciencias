#ifndef CLASECORTESDENOTAS_H
#define CLASECORTESDENOTAS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "estructuras.h"
#include "lista.h"


class claseCortesDeNotas{
	  
      public: claseCortesDeNotas(){}
				void registroCortesDeNotas();
	  	     
	  private:
      		  lista<preguntas> registrarPreguntasPorActividad(int cantPreg,int numeroCorte, int numeroActividad, string nombreActividad, string codigoCurso)
};

void claseCorteDeNotas:: registroCortesDeNotas(string codigoCurso){
	string prefijoCorte = codigoCurso+"\n"+"C";
	string nombreArchivoCorte="corteDeNotas_"+auxProf.cedula;
	string lineaArchivoCorte=prefijoCorte+"\n";
					
	cortesDeNotas objCortes;
	lista<apuntadorCorte> listaApuntadoresCortesDeNotas;
	apuntadorCorte *arregloDeCortes;
	apuntadorEvaluacion *arregloDeEvaluaciones;
					
	cout<<"\n Configuracion esquema de corte para profesor \n";
					
	for(int c=1;c<=numeroCortes;c++) {
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
				lista<preguntas> listaPreguntas = registrarPreguntasPorActividad(cantPreg,c,cort,objCorte.tipoEvaluacion,codigoCurso);
				objEvaluacion.preguntaSig = listaPreguntas;
				listaEvaluaciones.lista_vacia()? listaEvaluaciones.insertar_inicio(objEvaluacion): listaEvaluaciones.insertar_final(objEvaluacion);
								 
			}
				arregloDeEvaluaciones[cort].evaluaciones = listaEvaluaciones;
				arregloDeCortes[c].arregloCorte[cort] = objCorte;
		}
	}
}

lista<preguntas> claseCorteDeNotas:: registrarPreguntasPorActividad(int cantPreg,int numeroCorte, int numeroActividad, string nombreActividad, string codigoCurso){
	
	lista<preguntas> listaPreguntas;
	string nombreArchivo=codigoCurso+"_"+"corte"+numeroCorte+"_"+nombreActividad+numeroActividad+"_preguntas";
	string dato;
	int tema = 0;
	for(int preg = 0; preg<cantPreg; preg++) {
		preguntas objPreguntas;
		cout<<"Ingrese el porcentaje de la pregunta \n";
		cin>>objPreguntas.porcentajeTema;
		manejo_archivo.impresionListaTemas(manejo_archivo.consultarListaTemas(tema));					
		cout<<"\n Ingrese el numero de tema a evaluar \n";
		cin>>objPreguntas.tema;
		listaPreguntas.lista_vacia()?listaPreguntas.insertar_inicio(objPreguntas):listaPreguntas.insertar_final(objPreguntas);
		dato+=objPreguntas.porcentajeTema+" "+objPreguntas.tema+"\n";
	}
	manejo_archivo.escritura("archivoNotas/Parciales",nombreArchivo,dato);
	return listaPreguntas;
}



#endif
