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
void List<T>::add(T* d){
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->setNext(czo);
    czo = nuevo;
};

//Retorna el puntero al primer objeto T de la lista
template <class T>
T* List<T>::cabeza(void){
    if (this->isEmpty()) {
        return czo->getDato(); 
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
T* List<T>::last(){
    if ((czo->getNext())->getNext() == nullptr) { //cond. de corte
        return czo->getDato(); //devuelve a lo que apunta el elemento
    }
    else {
        return this->resto()->last(); //parte recursiva
    } 
};


//Imprime un string, LIFO
template <class T>
void List<T>::imprimir(){
    if (!this->isEmpty()){
        cabeza()->imprimir();
        this->resto()->imprimir();
    }
};

//Imprime un string, FIFO
template <class T>
void List<T>::imprimirQ(){
    if (this->isEmpty()) {
    }else {  
        this->resto()->imprimirQ();
        cabeza()->imprimir();
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
        if ((czo->getNext())->getNext() == nullptr) {
            delete czo->getNext();
            czo->setNext(nullptr);
        }
        else this->resto()->borrar_ultimo();
    }
};

//Le transfiere los datos de l1 a this
template <class T> void List<T>::concat(List<T>* l1){
    if (!(l1->isEmpty())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
};

//Hace una copia de la lista
template <class T> List<T>* List<T>::copy(void){
    List<T>* aux = new List();
    aux->concat(this);
    return aux;
};


//Deja "vivos" los n primeros nodos y borra el resto
template <class T> void List<T>::tomar(int n){ 
    if (this->size() > n) {
        this->borrar_last();
        this->tomar(n);
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