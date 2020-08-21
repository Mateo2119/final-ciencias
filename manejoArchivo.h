#ifndef MANEJOARCHIVO_H
#define MANEJOARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
fstream archivo;

void escritura(string nombreArchivo,string dato){
	archivo.open(nombreArchivo.c_str(),ios::out|ios::app); 
	if (archivo.is_open() ){
		archivo<<dato;		
		archivo.close();
		
	}else{
		cout<<"ERROR: no se encuentra el archivo para la operacion solicitada"<<endl;		
	}
}

void lectura(){
	
}




#endif
