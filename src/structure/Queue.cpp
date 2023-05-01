#include <cstdlib>
#include <iostream>
#include <sstream>
#include "List.cpp"

using namespace std;
template <class T> class Cola :public List<T> {
public:
    Cola() { List<T>(); };
    ~Cola();
    T tope() { return this->last(); };
    bool colavacia(void) { return this->isEmpty(); };
    void encolar(T a) { this->add(a); };
    void desencolar(void) { this->borrar_last(); };
    T ultimo(void) { return this->cabeza(); };
    string imprimir(string s) { return this->toPrint(s); };
};