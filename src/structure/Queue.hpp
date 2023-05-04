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
        //Constructor
        Queue() { List<T>(); };

        //getters de las puntas
        T* tope() { return this->last(); };
        T* ultimo(void) { return this->cabeza(); };

        //Metodos para modificar la cola
        void encolar(T *a) { this->add(a); };
        void desencolar(void) { this->borrar_ultimo(); };

        //Metodos del tipo size
        bool colavacia(void) { return this->isEmpty(); };

        //Metodos de impresion
        void imprimirQueue(){cout<< "Cola de pedidos: " << endl; this->imprimirQ();}
};
#endif