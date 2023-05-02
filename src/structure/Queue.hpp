#include <cstdlib>
#include <iostream>
#include <sstream>
#include "List.hpp"

using namespace std;

#pragma once
template <class T> class Queue :public List<T> {
public:
    Queue() { List<T>(); };
    //~Queue();
    T tope() { return this->last(); };
    bool colavacia(void) { return this->isEmpty(); };
    void encolar(T a) { this->add(a); };
    void desencolar(void) { this->borrar_ultimo(); };
    T ultimo(void) { return this->cabeza(); };
    string toPrint(string s) { return this->toPrint(s); };

};
