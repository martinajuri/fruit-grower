#include <cstdlib>
#include <iostream>
#include <sstream>
#include "List.hpp"
#include "List.cpp"

using namespace std;

#ifndef QUEUE_HPP
#define QUEUE_HPP
template <class T> class Queue :public List<T> {
public:
    Queue() { List<T>(); };
    T tope() { return this.last(); };
    bool colavacia(void) { return this.isEmpty(); };
    void encolar(T a) { this.add(a); };
    void desencolar(void) { this.borrar_ultimo(); };
    T ultimo(void) { return this.cabeza(); };
    //string toPrint(string s) { return this->toPrint(s); };
    void imprimirQueue(){cout<< "Cola de pedidos: " << endl; this.imprimirQ();}
};
#endif