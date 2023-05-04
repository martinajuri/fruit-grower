// Clase que representa una pila de 10 cajas con un tipo de fruta
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "List.hpp"
#include "List.cpp"
#include "../utils/enum.hpp"
#include "../model/Crate.hpp"
#include "../model/Crate.cpp"

using namespace std;

#ifndef CRATESTACK_HPP
#define CRATESTACK_HPP
class CrateStack : public List<Crate>{
    private:
        FruitType frutaAlmacenada;   
        const int MAX = 10;
        
    public:
        //Constructores
        CrateStack(FruitType f){List<Crate>(); frutaAlmacenada = f;};
        CrateStack();

        Crate* tope(void){return this->cabeza();};

        //Metodos tipo size
        bool pilaLlena(){return this->size() == MAX;};
        bool pilaVacia(){return this->isEmpty();};
        int almacenado(){return this->size();};
        float stackCapacity();
        float capacidad_tope();
        float cantidad_kilos();
        FruitType getFrutaAlmacenada(){return frutaAlmacenada;};

        //Metodos para manejar la pila
        void apilar(Crate *c); 
        void desapilar(); 
        void desapilarKilos(float kilos);
        void desapilarCajonEntero(int n);

        //Metodos de impresion
        string getStringDeFruta(){return fruitTypeToString(frutaAlmacenada);};
        void imprimirStack(){cout << "Pila de cajones de "<< getStringDeFruta() << ": "<<endl; imprimir();}
};
#endif