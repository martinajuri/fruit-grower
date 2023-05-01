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
        bool pilaVacia(){return this->isEmpty();};
        bool pilaLlena(){return this->size() == MAX;};
        FruitType getFrutaAlmacenada(){return frutaAlmacenada;};
         //devuelve la cantidad de cajones apilados
        int almacenado(){return this->size();};
        float capacity();
        //string getStringDeFruta(){return fruitTypeToString(frutaAlmacenada);};

    //Apila un caja
    void apilar(Crate c){

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

    //Desapila una caja
    void desapilar(void){
        
        if(!pilaVacia()){
            this->borrar();
        }
    };

    //Retorna la capacidad disponible en la pila
    float capacity(){

        float aux=(MAX - almacenado())*20.0;
        return aux + tope().capacity();

    };

};

