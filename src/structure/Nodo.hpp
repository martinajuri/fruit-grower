#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

#ifndef NODO_HPP
#define NODO_HPP
template <class T> class Nodo {
private:
    T* dato;
    Nodo* next;
public:
    Nodo() { next = NULL; };
    Nodo(T* a) { dato = a; next = NULL; };
    void setDato(T* a) { dato = a; };
    void setNext(Nodo* n) { next = n; };
    T* getDato() { return dato; };
    Nodo* getNext() { return next; };
    bool isEmpty() { return next == NULL; }
};
#endif
