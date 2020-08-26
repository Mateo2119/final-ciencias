#ifndef ESTRUCTURAS_H     
#define ESTRUCTURAS_H 
#include "lista.h"
#include <string>



struct refuerzo{
		string tema;
		float promedio;
};

struct consolidado{
		string pregunta;
		float promedio;
};

struct estudiante {
		string nombreEstudiante;
		lista<int> notas;
};

struct estudiantePorCurso {
		string codigoCurso;
		lista<estudiante> estudiante;				
}; 

struct preguntas {
	int tema;
	string porcentajeTema;
};

struct evaluacion {
		string fecha;	    		
		lista<preguntas> preguntaSig;
};

struct apuntadorEvaluacion {
		lista<evaluacion> evaluaciones;
};

struct corte {
		string tipoEvaluacion;
		string porcentaje;
		apuntadorEvaluacion *apuntadorEvaluacion;
}; 

struct apuntadorCorte{
		corte *arregloCorte;
};
   
struct cortesDeNotas {		
		lista <apuntadorCorte> listaCortes;
};
 
struct profesor {
		string  cedula;
		string apellidos;
		string nombres;
		int  numeroDeClases;	
		lista <cortesDeNotas> listaCortesDeNotas;	
};


struct temas {
		int codigoTema;
		string nombreTema;
};

struct archivosEntrega {
		string nombreArchivo;
};

struct apuntArchivos {
		lista<archivosEntrega> listaArchivos;
};
struct espacio {
		string codigoEspacio;
		apuntArchivos *archivosEntrega;
};

struct clase {
		string cedula;
		espacio *arregloEspacios;
};



#endif
