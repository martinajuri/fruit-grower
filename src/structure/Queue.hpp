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
    
    void imprimir(){
        if (this->isEmpty()) {
            cout <<" No tiene nada "<< endl;
    }
    else {
        this->cabeza().imprimir();
        cout << endl;
        this->resto()->imprimir();
        cout<< endl;
    }
    }
};
