#include <iostream>
#include <string> 
#include <iomanip>
#include "../utils/enum.hpp"

using namespace std;

#ifndef CRATE
#define CRATE
class Crate{
    private:
        string id;
        FruitType type;
        float fruitAmount = 0.0f;
        float maxWeight = 20.0f;
        void setFruitAmount(int n){fruitAmount=n;};

    public:
        //generator & destructor
        Crate(string i, FruitType t, float fA){id=i;type=t;fruitAmount=fA;}; 
        Crate() : id(""), type(FruitType::APPLE), fruitAmount(0.0f), maxWeight(20.0f) {}

        //getters
        string getId(){return id;};
        FruitType getType(){return type;};
        float getFruitAmount(){return fruitAmount;};

        //check capacity
        bool isEmpty(){return (getFruitAmount()==0);}; // devuelve true si la cantidad de fruta es 0
        bool hasCapacity(){return (capacity()>0);}; // devuelve true si la capacidad es mayor a 0
        float capacity(){return maxWeight - fruitAmount;} // devuelve la cantidad de fruta que puede ser agregada
    
        //to string
        //string toString(){return "Cajon " + id + ": " +  to_string(getFruitAmount()) + " " + fruitTypeToString(type) ;}
        void imprimir(){cout << "Cajon " << id << ": " <<fixed<< setprecision(1)<<getFruitAmount() << " kg de " << fruitTypeToString(type)<<endl;}

        // add fruit to crate
        void addFruit(float n);

        // take fruit out of the crate
        void deleteFruit(float n);
};
#endif