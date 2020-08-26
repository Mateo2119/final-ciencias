#ifndef CLASEPROFESOR_H
#define CLASEPROFESOR_H

#include <iostream>
#include <fstream>
#include <string>
#include "estructuras.h"
#include "lista.h"
#include "manejoArchivo.h"
#include "conversiones.h"



class claseProfesor{ 
	  manejoArchivo manejo_archivo;
	  conversiones conversiones_tipos;
      public: claseProfesor(){}
				void registroProfesor(profesor objProfesor);
	  	     
	  private:
      		  
};

void claseProfesor::registroProfesor(profesor objProfesor){
	string lineaProfesor = objProfesor.cedula+" "+ objProfesor.apellidos+" "+objProfesor.nombres+" "+conversiones_tipos.toString(objProfesor.numeroDeClases)+"\n";
	manejo_archivo.concatenar("archivosBase","profesores", lineaProfesor);
}

#endif
