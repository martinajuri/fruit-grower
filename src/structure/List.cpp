#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Nodo.cpp"

using namespace std;

template <class T> class Lista {

    private: Nodo<T>* czo;
     
    public:
        Lista() { czo = new Nodo<T>(); };
        Lista(Nodo<T>* n) { czo = n; };
        ~Lista();
        void add(T d); 
        bool isEmpty(void){return czo->isEmpty();};
        T cabeza(void); 
        Lista* resto(void); 
        string toPrint(string p);
        T suma(T i);
        int size();
        void borrar(void); 
        void borrar_last();
        void concat(Lista<T>* l1);
        Lista<T>* copy(void);
        void tomar(int n);
   
};

template <class T>
void Lista<T>::add(T d) 
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->setNext(czo);
    czo = nuevo;
}

//Retorna el primer nodo
template <class T>
T Lista<T>::cabeza(void)
{
    if (this->isEmpty()) {
        cout << " Error, Cabeza de lista vacia";
        return NULL;
    }
    return czo->getDato();
}

//retorna el puntero al "resto" de la lista
//resto = lo que queda de la lista sin la cabeza
template <class T>
Lista<T>* Lista<T>::resto(void)
{
    Lista* l = new Lista(czo->getNext());
    return (l);
}

template <class T>
string Lista<T>::toPrint(string p)
{
    if (this->isEmpty()) {
        return p;
    }
    else {
        ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl;
        return stm.str();
    }
}

template <class T>
T Lista<T>::suma(T i)
{    
    if (this->isEmpty()) {
        return i;
    }
    else {
        return this->resto()->suma(i + this->cabeza());
    }
}

template <class T> int Lista<T>::size()
{
    if (this->isEmpty()) return 0;
    return 1 + this->resto()->size();
}

//borra el nodo cabeza
template <class T> void Lista<T>::borrar(void)
{ 
    if (!this->isEmpty()) {
        Nodo<T>* tmp = czo;
        czo = czo->getNext();
        delete tmp;
    }
}
//borra el ultimo
template <class T> void Lista<T>::borrar_last()
{ 
    if (!this->isEmpty()) {
        if ((czo->getNext())->getNext() == NULL) {
            delete czo->getNext();
            czo->setNext(NULL);
        }
        else this->resto()->borrar_last();
    }
}

// le transfiere los datos de l1 a this
template <class T> void Lista<T>::concat(Lista<T>* l1)
{
    if (!(l1->isEmpty())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}

// hace una copia de la lista
template <class T> Lista<T>* Lista<T>::copy(void)
{
    Lista<T>* aux = new Lista();
    aux->concat(this);
    return aux;
}

//deja "vivos" los n primeros nodos y borra el resto
template <class T> void Lista<T>::tomar(int n)
{ 
    if (this->size() > n) {
        this->borrar_last();
        this->tomar(n);
    }
}
