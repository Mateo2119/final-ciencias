#ifndef ESTRUCTURAS_H     
#define ESTRUCTURAS_H 

struct nodo{
		char dato;
        nodo *sig;
       };

struct nodoLista {
		T Dato;
        nodo<T> * sig;};
        
struct profesor {
		int  cedula;
		char apellidos;
		char nombres;
		int  numeroDeClases;	
		lista<corte> listaCortes;	
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
		int tema;
		float porcentajeTema;
		evaluacion *preguntaSig;
};

struct tema {
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
