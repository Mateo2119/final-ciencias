#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <string>
#include<sstream>
#include <vector>
#include "manejoarchivos.h"
#include "logicaformulario.h"

using namespace std;

void menu();

string fechaActual(){
	time_t t;
  	struct tm *tm;
  	char fecha[11];
	t=time(NULL);
	tm=localtime(&t);
	strftime(fecha, 11, "%d/%m/%Y", tm);
	return fecha;
}

void registrar_Empleado(){
	//variable generada automaticamente para asignar un identificador unico
	string  id;
	//variables para el ingreso de los datos, tipo string 
	string nombre,apellido,identificacion,tel_celular,tel_fijo,email,f_nacimiento,edad,ciudad_nacimiento,pais_nacimiento;
	string ciudad_actual,direccion,barrio,actividad_laboral,sucursal_actual;
	
	//variables tipo string para identificar tipos 
	string tipo_identificacion,sexo,tiene_hijos; 
	
	//lista de hijos
	int numero_hijos=0;
	
	
	//variables tipo string para almacenar un registro completo
	string registro_Empleado_cadena,registro_Hijo_cadena;
	
	//comienza el formulario, se piden todos los datos
	system("cls");
	cout<<"REGISTRO EMPLEADO\n"<<endl;
	cout<<"Se le ha asignado automaticamente un identificador unico (id) "<<endl;     

    int i=obtener_id("empleado.txt");
    stringstream ss;
	ss << i;
	id = ss.str();
    
	cout<<"ID:  "<<id<<endl;
	cout<<" "<<endl;
	cout<<"Complete los siguientes campos del formulario\n"<<endl;
	
		//Nombre y apellido
	cout<<"\n 1. Nombre:   "; cin>>nombre;
	cout<<"\n 2. Apellido:   "; cin>>apellido;
	cout<<" "<<endl;
		//Tipo de identificacion 
	cout<<"\n 3. Seleccione su tipo de identificacion \n"
				"	1. Cedula Ciudadania\n"
				"	2. Cedula Extranjeria\n"
				"	3. Tarjeta Identidad"<<endl;
		//variable opcion tipo de identificacion
	int opc_Tipo_Identificacion=0;
	do{
		if(opc_Tipo_Identificacion!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		cout<<"opcion :   ";
		cin>>opc_Tipo_Identificacion;
		switch(opc_Tipo_Identificacion){	
			case 1: tipo_identificacion="CC";
					opc_Tipo_Identificacion=0;
				break;
			case 2: tipo_identificacion="CE";
					opc_Tipo_Identificacion=0;
				break;
			case 3:	tipo_identificacion="TI";
					opc_Tipo_Identificacion=0;
				break;
	    }
	    
	}while(opc_Tipo_Identificacion!=0);
	cout<<"\n 4. Numero de identificacion:   "; cin>>identificacion;
	
	//genero
	cout<<"\n 5. Seleccione su genero \n"
				"	1. Femenino\n"
				"	2. Masculino"<<endl;
		//variable opcion tipo de sexo
	int opc_genero=0;
	do{
		if(opc_genero!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		cout<<"opcion :   ";
		cin>>opc_genero;
		switch(opc_genero){	
			case 1: sexo="F";
					opc_genero=0;
				break;
			case 2: sexo="M";
					opc_genero=0;
				break;
	    }
	    
	}while(opc_genero!=0);
	
	//telefonos
	cout<<"\n 6. Telefono celular:   "; cin>>tel_celular;
	cout<<"\n 7. Telefono fijo:   "; cin>>tel_fijo;
	
	//email
	cout<<"\n 8. Email:   "; cin>>email;
	string fechaN;
	//fecha de nacimiento
	cout<<"\n 9. Ingrese su fecha de nacimiento con el siguiente Formato: dd/mm/aaaa    :";
			
		cin>>f_nacimiento;
			
	//calculo de la edad		
			string per1,dia3,dia4,mes3,mes4,actual,cad2;  
			
			
			per1 = f_nacimiento.substr (6);  
			actual = fechaActual();    
			cad2 = actual.substr (6); 
			  
					
			mes3=f_nacimiento.substr(3,2);   
			mes4=actual.substr(3,2);   
			
			int calculoEdad=atoi(cad2.c_str())- atoi(per1.c_str()); 
			
			if(mes3>mes4){
				calculoEdad= calculoEdad-1;  
			}else if(mes3==mes4 && dia3>dia4){
				calculoEdad= calculoEdad-1;   
			}	
	
	cout<<"\n 10. Edad:   ";
	stringstream sss;
	sss << calculoEdad;
	edad = sss.str();
	cout<<edad<<endl;
	
	//ciudad y pais de nacimiento
	cout<<"\n 11. Ciudad de nacimiento:   "; cin>>ciudad_nacimiento;
	cout<<"\n 12. Pais  de nacimiento:   "; cin>>pais_nacimiento;
	
	//residencia actual 
	cout<<"\n 13. Ciudad de residencia:   "; cin>>ciudad_actual;
	cout<<"\n 14. Direccion residencia:   "; cin>>direccion;
	cout<<"\n 15. Barrio residencia:   "; cin>>barrio;
	
	//actividad laboral
	cout<<"\n 16. Seleccione su Actividad laboral correspondiente \n"
				"	1. Artes\n"
				"	2. Ciencias Sociales\n"
				"	3. Ingenieria\n"
				"	4. Salud\n"
				"	5. Otros"<<endl;
		//variable opcion tipo de actividad laboral
	int opc_Tipo_Actividad=0;
	do{
		if(opc_Tipo_Actividad!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		cout<<"opcion :   ";
		cin>>opc_Tipo_Actividad;
		switch(opc_Tipo_Actividad){	
			case 1: actividad_laboral="Artes";
					opc_Tipo_Actividad=0;
				break;
			case 2: actividad_laboral="Sociales";
					opc_Tipo_Actividad=0;
				break;
			case 3:	actividad_laboral="Ingenieria";
					opc_Tipo_Actividad=0;
				break;
			case 4:	actividad_laboral="Salud";
					opc_Tipo_Actividad=0;
				break;
			case 5:	actividad_laboral="Otros";
					opc_Tipo_Actividad=0;
				break;
	    }
	    
	}while(opc_Tipo_Actividad!=0);
	
	//hijos
	cout<<"\n 17. Tiene hijos? \n"
				"	1. Si\n"
				"	2. No"<<endl;
		//variable opcion 
	int opc_hijos=0;
	do{
		if(opc_hijos!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		cout<<"opcion :   ";
		cin>>opc_hijos;
		switch(opc_hijos){	
			case 1: tiene_hijos="Si";
					opc_hijos=0;
				break;
			case 2: tiene_hijos="No";
					opc_hijos=0;
				break;
	    }
	    
	}while(opc_hijos!=0);
	
	//si la respues a tener hijos es positiva 
	if(tiene_hijos=="Si"){
		cout<<"		17.1.  Por favor digite el numero de hijos:   ";
		cin>>numero_hijos;
		string hijos[numero_hijos][3];
		//ingresar los hijos en un arreglo
		cout<<"			A continuacion , por favor digite el nombre de su hijos, enter, la edad y enter de nuevo"<<endl;
		for(int a=0;a<numero_hijos;a++){
			hijos[a][0]=id;
			cout<<"		Hijo numero "<< a+1<<endl;
			for(int b=1;b<3;b++){
				if (b==1){
					cout<<"			nombre:   ";
				}
				else{
					cout<<"			edad:   ";
				}
				cin>>hijos[a][b];
				
			}
		}
		//muestra los hijos , el primer numero es el id del padre 
		cout<<"		hijos, resumen: "<<endl;
		for(int a=0;a<numero_hijos;a++){
			
			for(int b=0;b<3;b++){
				cout<<hijos[a][b]<<" ";
			}
			
			cout<<" "<<endl;
		}
		//ingresar el registro de los hijos
		string cadena_hijos; 
		for(int a=0;a<numero_hijos;a++){
			cadena_hijos="";
			for(int b=0;b<3;b++){
				if(b==0){
					cadena_hijos=hijos[a][b];
				}else{
					cadena_hijos=cadena_hijos+":"+hijos[a][b];
				}
				
			}
			cadena_hijos=cadena_hijos+"\n";
			escribir_Archivo("hijo.txt",cadena_hijos);
		}
		
	}
	
	
	//nombre de la sucursal donde trabaja 
	cout<<"\n 18. Nombre de la sucursal donde trabaja:   "; cin>>sucursal_actual;
	
	//cadena concatenada con todos los valores ingresados, utilizando : como separador 
	registro_Empleado_cadena=id+":"+nombre+":"+apellido+":"+tipo_identificacion+":"+identificacion
							+":"+sexo+":"+tel_celular+":"+tel_fijo+":"+email+":"+f_nacimiento
							+":"+edad+":"+ciudad_nacimiento+":"+pais_nacimiento
							+":"+ciudad_actual+":"+direccion+":"+barrio+":"+actividad_laboral
							+":"+tiene_hijos+":"+sucursal_actual+"\n";
							
	cout<<registro_Empleado_cadena<<endl;
	//se ingresa el registro al archivo empleado
	escribir_Archivo("empleado.txt",registro_Empleado_cadena);
	
	
	//registro terminado, se retorna al menu principal
	cout<<"Registro completado, presione cualquier tecla para regresar al menu principal"<<endl;
	system("pause");
	menu();
}

void registrar_Sucursal(){
	system("cls");
	//variable generada automaticamente para asignar un identificador unico
	string  id;
	string nombre,direccion,barrio,ciudad,nombre_gerente;
	cout<<"REGISTRO SUCURSAL\n"<<endl;
	int i=obtener_id("sucursal.txt");
    stringstream ss;
	ss << i;
	id = ss.str();
    
	cout<<"ID:  "<<id<<endl;
	cout<<" "<<endl;
	cout<<"Complete los siguientes campos del formulario\n"<<endl;
	//Nombre, direccion, barrio y nombre del gerente 
	cout<<"\n 1. Nombre:   "; cin>>nombre;
	cout<<"\n 2. Direccion:   "; cin>>direccion;
	cout<<"\n 3. Barrio:   "; cin>>barrio;
	cout<<"\n 4. Nombre del gerente:   "; cin>>nombre_gerente;
	
	string cadena=id+":"+nombre+":"+direccion+":"+barrio+":"+nombre_gerente+"\n";
	escribir_Archivo("sucursal.txt",cadena);
	
	cout<<"Registro completado, presione cualquier tecla para regresar al menu principal"<<endl;
	system("pause");
	menu();
}

void consultar_Datos(){
	//se extrae los datos de los archivos y se guardan en arreglos
	string *q;
	int cont=asignarContador("empleado.txt");
	q=consultar("empleado.txt");
	for (int i=0;i<cont;i++){
			cout<<q[i]<<endl;
	} 
	//definicion de variables de empleado
	
	
	
	
	
	
	//system("cls");
	cout<<"Modulo de consulta, seleccione una opcion .\n"
		  "1.	Numero total de personas que trabajan en una sucursal dada," 
		        "clasificandolos por rangos de edades de los hijos \n\n"
		  "2.   Listado de los nombres y apellidos de aquellos que tienen  un numero de hijos dado  \n\n"
		  "3.  	Nombre y apellidos de las personas que viven en una ciudad\n\n"
		  "4.   Numero de sucursales en las que trabaja un numero de personas superior a un numero dado\n\n"
		  "5.   Numero de hombres y el numero de mujeres que trabajan en las diferentes sucursales\n\n"
		  "6.   Dado un rango de edad y una actividad laborar mostrar la lista de trabajadores de esa edad\n"<<endl;
	cout<<"Opcion:  ";
	int opcion=0;
	
	
	
	
	
	cout<<"Consulta completada, presione cualquier tecla para regresar al menu principal"<<endl;
	system("pause");
	menu();
}


void menuPrincipal(){
	system("cls");
	
	cout<<"MENU PRINCIPAL\n"<<endl;
	cout<<"Bienvenido al sistema de seguimiento, seleccione una opcion.\n"
		  "1. Loguearse como director de area.\n"
		  "2. Loguearse como profesor.\n"
		  "3. Loguearse como jefe de seccion.\n"
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{
		if(opcion!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		
		cin>>opcion;
		switch(opcion){
				
			case 1:				
				break;
			case 2:
				break;
			case 3:	
				break;			
		}
	}while(opcion!=0);
		  
}

void subMenuDirector() {
	system("cls");
	
	cout<<"Bienvenido director de area, seleccione una opcion.\n"
		  "1. Consultar promedio de estudiante de un curso\n"
		  "2. Consultar comportamiento promedio de los estudiantes de un curso\n"
		  "3. Consultar comportamiento promedio de los estudiantes por profesor\n"
		  "4. Consultar lista de profesores por numero de clases dictadas\n"
		  "5. Consultar lista de estudiantes con nota superior a la nota indicada\n"
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{
		if(opcion!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		
		cin>>opcion;
		switch(opcion){
				
			case 1:								
				break;
			case 2:
				break;
			case 3:	
				break;	
			case 4:	
				break;	
			case 5:	
				break;			
		}
	}while(opcion!=0);
}

void subMenuJefeSeccion() {
	system("cls");
	
	cout<<"Bienvenido profesor, seleccione una opcion.\n"
		  "1. Modificar esquema propueesto para corte\n"
		  "2. Consultar comportamiento promedio de los estudiantes de un curso\n"
		  "3. Consultar comportamiento promedio de los estudiantes por profesor\n"
		  "4. Consultar lista de profesores por numero de clases dictadas\n"
		  "5. Consultar lista de estudiantes con nota superior a la nota indicada\n"
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{
		if(opcion!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		
		cin>>opcion;
		switch(opcion){
				
			case 1:								
				break;
			case 2:
				break;
			case 3:	
				break;	
			case 4:	
				break;	
			case 5:	
				break;			
		}
	}while(opcion!=0);
}

void subMenuProfesor() {
	system("cls");
	
	cout<<"Bienvenido profesor, seleccione una opcion.\n"
		  "1. Modificar esquema propueesto para corte\n"
		  "2. Consultar comportamiento promedio de los estudiantes de un curso\n"
		  "3. Consultar comportamiento promedio de los estudiantes por profesor\n"
		  "4. Consultar lista de profesores por numero de clases dictadas\n"
		  "5. Consultar lista de estudiantes con nota superior a la nota indicada\n"
	cout<<"Opcion:  ";
	int opcion=0;
	// Ciclo do while para que seleccione una opcion valida
	do{
		if(opcion!=0){
			cout<<"Seleccione una opcion valida"<<endl;
		}
		
		cin>>opcion;
		switch(opcion){
				
			case 1:								
				break;
			case 2:
				break;
			case 3:	
				break;	
			case 4:	
				break;	
			case 5:	
				break;			
		}
	}while(opcion!=0);
}
int main(int argc, char** argv) {
	
	menu();
	return 0;
}
	
	
