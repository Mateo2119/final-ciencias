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

struct estudiante{
		string nombreEstudiante;
};

struct estudiantePorCurso {
		string codigoCurso;
		lista<estudiante> estudiante;				
}; 

struct evaluacion {
		string fecha;	    
		int tema;
		string porcentajeTema;
		evaluacion *preguntaSig;
};

struct apuntadorEva {
		lista<evaluacion> evaluaciones;
};

struct corte {
		string tipoEvaluacion;
		string porcentaje;
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
