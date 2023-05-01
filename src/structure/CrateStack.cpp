// Clase que representa una pila de 10 cajas con un tipo de fruta
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "List.cpp"
#include "../utils/enum.hpp"
#include "../model/Crate.cpp"

using namespace std;

#define MAX 10;

class CrateStack : public List<Crate>{

    private:

        FruitType frutaAlmacenada;   
        
    public:

        CrateStack(FruitType f){List<Crate>(); frutaAlmacenada = f;};
        Crate tope(void){return this->cabeza();};
        void desapilar(void){if(!pilaVacia()){this->borrar();}};
        bool pilaVacia(){return this->isEmpty();};
        bool pilaLlena(){return this->size() == MAX;};
        FruitType getFrutaAlmacenada(){return frutaAlmacenada;};
        //string getStringDeFruta(){return fruitTypeToString(frutaAlmacenada);};
        int almacenado(){return this->size();};

    //Apila un caja
    void CrateStack :: apilar(Crate c){

        if(!pilaLlena()){

            if(tope().hasCapacity()){
                Crate cajaAux = tope();
                desapilar();
                this->add(c);
                this->add(cajaAux);
            }else{
                this->add(c);
                }
            }
    }
};

