#include <iostream>
#include <string> 
#include "../utils/enum.hpp"

using namespace std;

#pragma once
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
        Crate(); 
        //~Crate(); 

        //getters
        string getId(){return id;};
        FruitType getType(){return type;};
        float getFruitAmount(){return fruitAmount;};

        //check capacity
        bool isEmpty(){return (getFruitAmount()==0);}; // devuelve true si la cantidad de fruta es 0
        bool hasCapacity(){return (capacity()>0);}; // devuelve true si la capacidad es mayor a 0
        float capacity(){return maxWeight - fruitAmount;} // devuelve la cantidad de fruta que puede ser agregada
    

        //to string
        string toString(){return "Cajon " + id + ": " +  to_string(getFruitAmount()) + " " + fruitTypeToString(type);}

        // add fruit to crate
        void addFruit(float n) {
            if (capacity()>= n) { // Si hay capacidad mayor o igual a la cantidad que se quiere agregar
            setFruitAmount(getFruitAmount()+n); // Se suma la cantidad de fruta al cajon
            }
            else { // Si se supera el maximo peso soportado
                cout << "No se puede agregar mas fruta al cajon " << id << endl; // mensaje de error
            }
        }

        // take fruit out of the crate
        void deleteFruit(float n) {
            if (getFruitAmount()>n) { // Si hay mas cantidad de la que se quiere sacar
            setFruitAmount(getFruitAmount()-n); // Se resta la cantidad de fruta al cajon
            }
            else { 
                cout << "No se puede quitar mas fruta del cajon " << id << endl; // mensaje de error
            }
        }
};