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
    if (pilaVacia()) { // si la pila está vacía
       this->add(c); // funciona
    } else //si no esta vacia
        if(tope().hasCapacity() && !c.hasCapacity()){ // cajon que quiero agregar esta lleno
            Crate cajaAux = tope(); //funciona
            desapilar();
            this->add(c);
            this->add(cajaAux);
            cout<<"primer if"<<endl;    
        }else if(tope().hasCapacity()){ // si ambos cajones no estan llenos (tiene capacidad)
            if(tope().capacity() >= c.getFruitAmount()){ // si la fruta del cajon nuevo entra en el top (el cojon de arriba)
                cout<<"segundo if"<<endl;    
                tope().addFruit(c.getFruitAmount()); //no funciona
                tope().imprimir();
            }
            else{ // si la cantidad de fruta del nuevo cajon no entra 
                cout<<"primer else"<<endl;    
                float aux = tope().capacity();
                tope().addFruit(tope().capacity());
                c.deleteFruit(aux);
            }
        }
        else{cout<<"ultimo else"<<endl;    this->add(c);} 
        //
    // if (pilaVacia()) { // si la pila está vacía
    //     this->add(c);
    // } else if (tope().isEmpty()) { // si la caja superior de la pila está vacía
    //     desapilar(); // eliminamos la caja vacía
    //     this->add(c); // agregamos la nueva caja
    // } else if (tope().hasCapacity()) { // si la caja superior de la pila tiene capacidad
    //     if (tope().capacity() >= c.getFruitAmount()) {
    //         tope().addFruit(c.getFruitAmount());
    //     } else {
    //         float aux = tope().capacity();
    //         tope().addFruit(tope().capacity());
    //         tope().deleteFruit(aux);
    //     }
    // } else { // si la caja superior de la pila no tiene capacidad
    //     this->add(c);
    // }
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


