#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Nodo.hpp"

using namespace std;

#ifndef LIST_HPP
#define LIST_HPP
template <class T> class List {
    private: 
        Nodo<T>* czo;  
    public:
        List() { czo = new Nodo<T>(); };
        List(Nodo<T>* n) { czo = n; };
        void add(T* d); 
        bool isEmpty(void){return czo->isEmpty();};
        T* cabeza(void); 
        List* resto(void); 
        string toPrint(string p);
        int size();
        void borrar(void); 
        void borrar_ultimo();
        void concat(List<T>* l1);
        List<T>* copy(void);
        void tomar(int n);
        T* last();
        void imprimir();
        void imprimirQ();
};
#endif