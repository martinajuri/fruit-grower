#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Nodo.hpp"
#include "List.hpp"

using namespace std;

#ifndef LIST_CPP
#define LIST_CPP
template <class T>
void List<T>::add(T d){
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->setNext(czo);
    czo = nuevo;
};

//Retorna el primer nodo
template <class T>
T List<T>::cabeza(void){
    if (this->isEmpty()) {
        return czo->getDato(); //invalid conversion from 'long long int' to 'FruitType' [-fpermissive]
    }
    return czo->getDato();
};

//retorna el puntero al "resto" de la lista
//resto = lo que queda de la lista sin la cabeza
template <class T>
List<T>* List<T>::resto(void){
    List* l = new List(czo->getNext());
    return (l);
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

//imprime listas, el ultimo en ser agregado es el que se muestra primero
template <class T>
void List<T>::imprimir(){
    
    if (!this->isEmpty()){
        cabeza().imprimir();
        cout<< endl;
        this->resto()->imprimir();
    }
};

//imprime colas: el primero en llegar es el que se muestra primero
template <class T>
void List<T>::imprimirQ(){
    
    if (this->isEmpty()) {
    }else {  
        this->resto()->imprimirQ();
        cabeza().imprimir();
        cout<< endl;
    }
};

//Devuelve el tamaño
template <class T> int List<T>::size(){
    if (this->isEmpty()) return 0;
    return 1 + this->resto()->size();
};

//borra el nodo cabeza
template <class T> void List<T>::borrar(void){ 
    if (!this->isEmpty()) {
        Nodo<T>* tmp = czo;
        czo = czo->getNext();
        delete tmp;
    }
};
//borra el ultimo
template <class T> void List<T>::borrar_ultimo(){ 
    if (!this->isEmpty()) {
        if ((czo->getNext())->getNext() == NULL) {
            delete czo->getNext();
            czo->setNext(NULL);
        }
        else this->resto()->borrar_ultimo();
    }
};

// le transfiere los datos de l1 a this
template <class T> void List<T>::concat(List<T>* l1){
    if (!(l1->isEmpty())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
};

// hace una copia de la lista
template <class T> List<T>* List<T>::copy(void){
    List<T>* aux = new List();
    aux->concat(this);
    return aux;
};


//deja "vivos" los n primeros nodos y borra el resto
template <class T> void List<T>::tomar(int n){ 
    if (this->size() > n) {
        this->borrar_last();
        this->tomar(n);
    }
};

//devuelve el ultimo elemento de la lista
template <class T> 
T List<T>::last(){
    if ((czo->getNext())->getNext() == NULL) { //si es el ultimo elemento de la lista
        return czo->getDato(); //devuelve a lo que apunta el elemento
    // "could not convert '*((List<WholesaleOrder>*)this)->List<WholesaleOrder>::czo' from 'Nodo<WholesaleOrder>' to 'WholesaleOrder'",
    }
    else {return this->resto()->last();} //parte recursiva (le va sacando un elemento a la lista) 
};
#endif