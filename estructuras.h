#ifndef ESTRUCTURAS_H     
#define ESTRUCTURAS_H 
#include "lista.h"
#include <string>



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
		archivosEntrega *archivoSig;
};

struct espacio {
		string codigoEspacio;
		archivosEntrega *archivosEntrega;
};

struct clases {
		string cedulaProfesor;
		lista<espacio> espacio;
};




#endif
