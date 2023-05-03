#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Nodo.hpp"

using namespace std;

#ifndef LIST_HPP
#define LIST_HPP
template <class T> class List {
    private: 
        Nodo<T>* czo;  //Puntero al primer nodo de la lista
    public:
    //Constructores
        List() { czo = new Nodo<T>(); };
        List(Nodo<T>* n) { czo = n; };

    //Principales
        T* cabeza(void);
        List* resto(void);
        T* last();

    //Modificadores
        void add(T* d); 
        void borrar(void); 
        void borrar_ultimo();

    //Tamaño
        bool isEmpty(void){return czo->isEmpty();};
        int size();

    //Para el cout
        void imprimir();
        void imprimirQ();

    //No Usados
        void concat(List<T>* l1);
        string toPrint(string p);
        List<T>* copy(void);
        void tomar(int n);
};
#endif