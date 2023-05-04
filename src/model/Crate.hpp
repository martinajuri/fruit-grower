#include <iostream>
#include <string> 
#include <iomanip>
#include "../utils/enum.hpp"

using namespace std;

#ifndef CRATE_HPP
#define CRATE_HPP
class Crate{
    private:
        string id;
        FruitType type;
        float fruitAmount = 0.0f;
        float maxWeight = 20.0f;

    public:
        //Constructores
        Crate(string i, FruitType t, float fA){id=i;type=t;fruitAmount=fA;}; 
        Crate() : id(""), type(FruitType::APPLE), fruitAmount(0.0f), maxWeight(20.0f) {}

        //setters & getters
        string getId(){return id;};
        FruitType getType(){return type;};
        float getFruitAmount(){return fruitAmount;};
        void setFruitAmount(float n){fruitAmount=n;};

        //Metodos de capacidad
        bool isEmpty(){return (getFruitAmount()==0);}; // devuelve true si la cantidad de fruta es 0
        bool hasCapacity(){return (capacity()>0);}; // devuelve true si la capacidad es mayor a 0
        float capacity(){return maxWeight - fruitAmount;} // devuelve la cantidad de fruta que puede ser agregada
    
        //Metodos de impresion
        void imprimir(){cout << "Cajon " << id << ": " <<fixed<< setprecision(1)<<getFruitAmount() << " kg de " << fruitTypeToString(type)<<endl;}

        //Metodos de modificacion del cajon
        void addFruit(float n);
        void deleteFruit(float n);
};
#endif