#include <cstdlib>
#include <iostream>
#include "estructuras.h"

#ifndef PILA_H     
#define PILA_H    

template <class T>

template <class T>
class pila{
	  nodo *cab;
      public: pila(){
	  		cab= new nodo;
            cab->dato=NULL;
            cab->sig = NULL;
		}
             void Push( T v);
             char Pop();
             bool PilaVacia();
             ~pila();
      };
     
template <class T>
void pila<T>::Push(T v){
     nodo *t = new nodo;
     t->dato=v; 
     t->sig=cab->sig;
     cab->sig= t;
     }
     
template <class T>
char pila<T>::Pop(){
     T x;
     nodo *t= cab->sig;
     cab->sig= t->sig; 
     x=t->dato;
     delete t;
     return x;
     }
     
template <class T>     
bool pila<T>::PilaVacia(){
      return cab->sig== NULL;
      }

 pila::~pila(){
      nodo *t=cab;
     while (t!=NULL){
           cab=t;
           t=t->sig;
           delete cab;
           }
     }
 
     
#endif
