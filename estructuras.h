#ifndef ESTRUCTURAS_H     
#define ESTRUCTURAS_H 
#include "lista.h"
#include <string>


struct estudiante {
		char nombreEstudiante;		
		lista<float> nota; 
};
 
 
struct evaluacion {
	    char fecha;
		int tema;
		float porcentajeTema;
		evaluacion *preguntaSig;
};

struct apuntadorEva {
		lista<evaluacion> evaluaciones;
};

struct corte {
		string tipoEvaluacion;
		float porcentaje;
		apuntadorEva *apuntadorEva;
}; 
   
struct cortesDeNotas {		
		lista <corte> listaCortes;
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
		archivosEntrega *archivoSig;
};

struct espacio {
		string codigoEspacio;
		archivosEntrega *archivosEntrega;
};

struct clases {
		int cedulaProfesor;
		lista<espacio> espacio;
};




#endif
