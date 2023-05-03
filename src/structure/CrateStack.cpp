// Clase que representa una pila de 10 cajas con un tipo de fruta
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "List.hpp"
#include "List.cpp"
#include "../utils/enum.hpp"
#include "../model/Crate.hpp"
#include "../model/Crate.cpp"
#include "CrateStack.hpp"

using namespace std;

#define MAX  10;

//Apila un caja
void CrateStack::apilar(Crate c){   
    cout<<"entro al metodo apilar"<<endl;    
    if(tope().hasCapacity() && !c.hasCapacity()){
        Crate cajaAux = tope();
        desapilar();
        this->add(c);
        this->add(cajaAux);
    cout<<"primer if"<<endl;    
    }else if(tope().hasCapacity()){
        if(tope().capacity() >= c.getFruitAmount()){
    cout<<"segundo if"<<endl;    
            tope().addFruit(c.getFruitAmount());
        }else{
    cout<<"primer else"<<endl;    
            float aux = tope().capacity();
            tope().addFruit(tope().capacity());
            tope().deleteFruit(aux);
        }
    }else{cout<<"ultimo else"<<endl;    this->add(c);} 
};

//Desapila una caja
void CrateStack::desapilar(void){
    if(!pilaVacia()){
        this->borrar();
    }
};

// Desapila x kilos de fruta
void CrateStack::desapilarKilos(float kilos){
    if(kilos==cabeza().getFruitAmount()){
        desapilar();
    }
    else if(kilos<cabeza().getFruitAmount()){
        cabeza().deleteFruit(kilos);
    }else{
        float aux = kilos - cabeza().getFruitAmount();
        desapilar();
        desapilarKilos(aux);
    }
};

void CrateStack::desapilarCajonEntero(int n){
    if(tope().hasCapacity()){
            Crate cajaAux = tope();
            desapilar();
            desapilarCajonEntero(n);
            this->add(cajaAux);
    }else{
        for (int i = 0; i < n; i++){desapilar();}
    }
};

//Retorna la capacidad disponible en la pila
float CrateStack::stackCapacity(){
    float aux= MAX - almacenado();
    return ((aux*20.0) + tope().capacity());
};

// Retorna la capacidad de la caja que se encuentra arriba
float CrateStack::capacidad_tope(){
    return tope().capacity();
};

// Retorna la cantidad de fruta en kilogramos
float CrateStack::cantidad_kilos(){
    int cajonesLlenos = almacenado()-1;
    return cajonesLlenos*20.0 + cabeza().getFruitAmount();
};


