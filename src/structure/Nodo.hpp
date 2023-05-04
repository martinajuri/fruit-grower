#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

#ifndef NODO_HPP
#define NODO_HPP
template <class T>
class Nodo{
    private:
        T *dato;        // Puntero al dato del nodo
        Nodo *next;     // Puntero al siguiente nodo
    
    public:
        //Constructores
        Nodo() { next = NULL; };
        Nodo(T *a){ dato = a; next = NULL; };
        
        //setters       
        void setDato(T *a) { dato = a; };    
        void setNext(Nodo *n) { next = n; }; 

        //getters
        T *getDato() { return dato; };       
        Nodo *getNext() { return next; };

        //devuelve si el nodo no tiene siguiente nodo apuntado
        bool isEmpty() { return next == NULL; }
};
#endif
