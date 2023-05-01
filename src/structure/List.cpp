#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Nodo.cpp"

using namespace std;

template <class T> class List {

    private: Nodo<T>* czo;
     
    public:
        List() { czo = new Nodo<T>(); };
        List(Nodo<T>* n) { czo = n; };
        ~List();
        void add(T d); 
        bool isEmpty(void){return czo->isEmpty();};
        T cabeza(void); 
        List* resto(void); 
        string toPrint(string p);
        int size();
        void borrar(void); 
        void borrar_ultimo();
        void concat(List<T>* l1);
        List<T>* copy(void);
        void tomar(int n);
        T last();
   
};

template <class T>
void List<T>::add(T d) 
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->setNext(czo);
    czo = nuevo;
}

//Retorna el primer nodo
template <class T>
T List<T>::cabeza(void)
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
List<T>* List<T>::resto(void)
{
    List* l = new List(czo->getNext());
    return (l);
}


template <class T>
string List<T>::toPrint(string p)
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

//Devuelve el tamaño
template <class T> int List<T>::size()
{
    if (this->isEmpty()) return 0;
    return 1 + this->resto()->size();
}

//borra el nodo cabeza
template <class T> void List<T>::borrar(void)
{ 
    if (!this->isEmpty()) {
        Nodo<T>* tmp = czo;
        czo = czo->getNext();
        delete tmp;
    }
}
//borra el ultimo
template <class T> void List<T>::borrar_ultimo()
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
template <class T> void List<T>::concat(List<T>* l1)
{
    if (!(l1->isEmpty())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}

// hace una copia de la lista
template <class T> List<T>* List<T>::copy(void)
{
    List<T>* aux = new List();
    aux->concat(this);
    return aux;
}

//deja "vivos" los n primeros nodos y borra el resto
template <class T> void List<T>::tomar(int n)
{ 
    if (this->size() > n) {
        this->borrar_last();
        this->tomar(n);
    }
}

//devuelve el ultimo elemento de la lista
template <class T> T List<T>::last()
{

    if (czo->getNext() == NULL) { //si es el ultimo elemento de la lista
        return *czo; //devuelve a lo que apunta el elemento
    }
    else this->resto()->last(); //parte recursiva (le va sacando un elemento a la lista) 
    
}
