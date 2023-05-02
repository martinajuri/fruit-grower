// Clase que representa una pila de 10 cajas con un tipo de fruta
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "List.hpp"
#include "../utils/enum.hpp"
#include "../model/Crate.hpp"

using namespace std;

#define MAX  10;

#pragma once
class CrateStack : public List<Crate>{

    private:

        FruitType frutaAlmacenada;   
        
    public:

        CrateStack(FruitType f){List<Crate>(); frutaAlmacenada = f;};
        CrateStack();
        Crate tope(void){return this->cabeza();};
        bool pilaVacia(){return this->isEmpty();};
        bool pilaLlena(){return this->size() == MAX;};
        FruitType getFrutaAlmacenada(){return frutaAlmacenada;};
         //devuelve la cantidad de cajones apilados
        int almacenado(){return this->size();};
        //float stackCapacity();
        //float capacidad_tope();
        //string getStringDeFruta(){return fruitTypeToString(frutaAlmacenada);};

    //Apila un caja
    void apilar(Crate c){
        
            if(tope().hasCapacity() && !c.hasCapacity()){
                Crate cajaAux = tope();
                desapilar();
                this->add(c);
                this->add(cajaAux);
            }else if(tope().hasCapacity()){
                if(tope().capacity() >= c.getFruitAmount()){
                    tope().addFruit(c.getFruitAmount());
                }else{
                    float aux = tope().capacity();
                    tope().addFruit(tope().capacity());
                    tope().deleteFruit(aux);
                }
            }else{this->add(c);}
            
    };

    //Desapila una caja
    void desapilar(void){
        
        if(!pilaVacia()){
            this->borrar();
        }
    };

    // Desapila x kilos de fruta
    void desapilarKilos(float kilos){
        
        if(kilos==cabeza().getFruitAmount()){
            desapilar();
        }
        else if(kilos<cabeza().getFruitAmount()){
            cabeza().deleteFruit(kilos);
        }
        else{
            float aux = kilos - cabeza().getFruitAmount();
            desapilar();
            desapilarKilos(aux);
        }
    };

    void desapilarCajonEntero(int n){
        
        if(tope().hasCapacity()){
                Crate cajaAux = tope();
                desapilar();
                desapilarCajonEntero(n);
                this->add(cajaAux);
        }
        else{
            for (int i = 0; i < n; i++){
                desapilar();
            }
        }
        
    };

    //Retorna la capacidad disponible en la pila
    float stackCapacity(){

        float aux= MAX - almacenado();
        return ((aux*20.0) + tope().capacity());

    };

    // Retorna la capacidad de la caja que se encuentra arriba
    float capacidad_tope(){
        return tope().capacity();
    };

    // Retorna la cantidad de fruta en kilogramos
    float cantidad_kilos(){
        int cajonesLlenos = almacenado()-1;
        return cajonesLlenos*20.0 + cabeza().getFruitAmount();
    }
};

