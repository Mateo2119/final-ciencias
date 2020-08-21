#ifndef ESTRUCTURAS_H     
#define ESTRUCTURAS_H 

struct nodo{
		T dato;
        nodo *sig;
       };

struct nodoLista {
		T Dato;
        nodoLista<T> * sig;};
        

struct estudiante {
		char nombreEstudiante;		
		lista<float> nota; 
};
        
struct profesor {
		int  cedula;
		char apellidos;
		char nombres;
		int  numeroDeClases;	
		lista <cortesDeNotas> listaCortesDeNotas;	
};

struct cortesDeNotas {		
		lista <corte> listaCortes;
};

struct corte {
		char tipoEvaluacion;
		float porcentaje;
		apuntadorEva *apuntadorEva;
};

struct apuntadorEva {
		lista<evaluacion> evaluaciones;
};

struct evaluacion {
	    char fecha;
		int tema;
		float porcentajeTema;
		evaluacion *preguntaSig;
};

struct temas {
		int codigoTema;
		char nombreTema;
};

struct clases {
		int cedulaProfesor;
		lista<espacio> espacio;
};

struct espacio {
		char codigoEspacio;
		archivo *archivo;
};

struct archivo {
		char nombreArchivo;
		archivo *archivoSig;
};
#endif
