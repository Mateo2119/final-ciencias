#include <cstdlib>
#include <iostream>
#include "estructuras.h"

#ifndef COLA_H     
#define COLA_H 

using namespace std;
template <class T>

struct nodo{
		T dato;
        nodo *sig;
       };
       
template <class T>
class cola{
	nodo *cab,*fin;
    public: cola(){cab=fin=NULL;}
    void InsCola(T i);
    T AtenderCola();
    void ImprimirCola();
    bool ColaVacia();
    ~cola();
 };

template <class T>
void cola<T>::InsCola(T i){
     nodo *nuevo;
     nuevo= new nodo;
     nuevo->dato=i;
     nuevo->sig= NULL;
     if (cab==NULL)
         {cab=nuevo;}
     else {fin->sig = nuevo;}
     fin=nuevo;
}


template <class T>
T cola<T>::AtenderCola()
{   T x;
    nodo *aux = cab; 
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    return x;
    }
    
template <class T>
void cola<T>::ImprimirCola(){
     nodo *aux;
     aux=cab;
     while(aux!=NULL){
       cout<<aux->dato<<" ";
       aux=aux->sig;}    
}

template <class T>
bool cola<T>::ColaVacia(){
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
