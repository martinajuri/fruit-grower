#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Nodo.hpp"
#include "List.hpp"

using namespace std;

#ifndef LIST_CPP
#define LIST_CPP
template <class T>

//Agrega un puntero de un objeto T a la lista
void List<T>::add(T d){
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->setNext(czo);
    czo = nuevo;
};

//Retorna el puntero al primer objeto T de la lista
template <class T>
T List<T>::cabeza(void){
    if (this.isEmpty()) {
        return NULL; 
    }
    return czo->getDato();
};

//Retorna el puntero al "resto" de la lista
template <class T>
List<T>* List<T>::resto(void){
    List* l = new List(czo->getNext());
    return (l);
};


//Devuelve el puntero al ultimo objeto de la lista
template <class T> 
T List<T>::last(){
    if ((czo->getNext())->getNext()->isEmpty()) { //cond. de corte
        return czo->getDato(); //devuelve a lo que apunta el elemento
    }
    else {return this->resto()->last();} //parte recursiva
};


//imprime un string, LIFO
template <class T>
void List<T>::imprimir(){
    
    if (!this->isEmpty()){
        cabeza()->imprimir();
        //cout<< endl;
        this->resto()->imprimir();
    }
    else{
        cout << "Lista vacía" << endl;
    }
};

//imprime un string, FIFO
template <class T>
void List<T>::imprimirQ(){
    
    if (this->isEmpty()) {
    }else {  
        this->resto()->imprimirQ();
        cabeza()->imprimir();
        //cout<< endl;
    }
};

//Devuelve la cantidad de nodos
template <class T> int List<T>::size(){
    if (this->isEmpty()) return 0;
    return 1 + this->resto()->size();
};

//Borra el nodo cabeza y asigna al segundo como czo
template <class T> void List<T>::borrar(void){ 
    if (!this->isEmpty()) {
        Nodo<T>* tmp = czo;
        czo = czo->getNext();
        delete tmp;
    }
};
//Borra el ultimo nodo
template <class T> void List<T>::borrar_ultimo(){ 
    if (!this->isEmpty()) {
        if ((czo->getNext())->getNext() == NULL) {
            delete czo->getNext();
            czo->setNext(NULL);
        }
        else this->resto()->borrar_ultimo();
    }
};


template <class T>
string List<T>::toPrint(string p){
    if (this->isEmpty()) {
        return p;
    }else {
        ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p);
        return stm.str();
    }
};
#endif