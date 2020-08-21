#include <cstdlib>
#include <iostream>
#include "estructuras.h"

#ifndef COLA_H     
#define COLA_H 

using namespace std;

class cola{
	nodo *cab,*fin;
    public: cola(){cab=fin=NULL;}
    void InsCola(T i);
    T AtenderCola();
    void ImprimirCola();
    bool ColaVacia();
    ~cola();
 };

void cola::InsCola(T i){
     nodo *nuevo;
     nuevo= new nodo;
     nuevo->dato=i;
     nuevo->sig= NULL;
     if (cab==NULL)
         {cab=nuevo;}
     else {fin->sig = nuevo;}
     fin=nuevo;
}



T cola::AtenderCola()
{   T x;
    nodo *aux = cab; 
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    return x;
    }

void cola::ImprimirCola(){
     nodo *aux;
     aux=cab;
     while(aux!=NULL){
       cout<<aux->dato<<" ";
       aux=aux->sig;}    
}

bool cola::ColaVacia(){
     return (cab==NULL);
     }

cola::~cola(){
     nodo *aux;
     while(cab!=NULL)
       {aux= cab;
        cab=aux->sig;
        delete aux;}
     delete cab;
     }

#endif
