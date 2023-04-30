// Clase que representa una pila de 10 cajas con un tipo de fruta
#include <iostream>
#include <array>
#include "../model/Crate.cpp"

#define MAX 10
using namespace std;

class CrateStack {

private:

    Crate* cajasF; //Objeto de tipo crate que va a ser la pila de cajas
    int pos; // Caja apilada
    FruitType frutaAlmacenada; // Tipo de fruta almacenado en la pila

public:
    
    CrateStack(FruitType fruta) {pos = -1; frutaAlmacenada = fruta; cajasF = new Crate[MAX];}; //Constructor de la pila de cajas
    void apilar(Crate c);//Apila una caja
    void desapilar(void){if(!pilaVacia())pos--;}; //Desapila una caja
    FruitType getFrutaAlmacenada(){return frutaAlmacenada;};//Devuelve que fruta esta almacenada en la pila 
    bool pilaVacia(){return pos == -1;};//Verifica si la pila esta vacia
    bool pilaLlena(){return pos == MAX-1;};//Verifica si la pila esta llena
    int almacenado() {return pos + 1;};//Devuelve la cantidad de cajas alamacenada
    
};

    void CrateStack::apilar(Crate c){

        if(!pilaLlena()){

            cajasF[++pos] = c;

        }else{cout << "Pila llena" << endl;}


    }