#include <iostream>
#include <string> 
#include "../utils/enum.hpp"

using namespace std;


class Crate{


    private:
        string id;
        FruitType type;
        int fruitAmount = 20.0;
        int maxWeight = 20.0;

        void setFruitAmount(int n){fruitAmount=n;};

    public:
        //generator & destructor
        Crate(string id, FruitType type){this->id=id;this->type=type;}; 
        ~Crate(); 

        //getters
        string getId(){return id;};
        FruitType getType(){return type;};
        int getFruitAmount(){return fruitAmount;};

        //setters
        void add(int n){setFruitAmount(getFruitAmount()+n);};
        void deleteF(int n){setFruitAmount(getFruitAmount()-n);};

        //check capacity
        bool isEmpty(){return (getFruitAmount()==0);};
        bool hasCapacity(){return (capacity()>0);};
        int capacity(){return maxWeight - fruitAmount;}
    

        //to string
        string toString(){return "Cajon " + id + ": " +  to_string(fruitAmount) + " " + fruitTypeToString(type);}

    // add fruit to crate
    void addFruit(int n) {
        if (fruitAmount + n <= maxWeight) { // Si no se supera el maximo peso soportado
            add(n); // Se suma la cantidad de fruta al cajon
        }
        else { // Si se supera el maximo peso soportado
            cout << "No se puede agregar mas fruta al cajon " << id << endl; // Se muestra un mensaje de error
        }
    }

    // take fruit out of the crate
    void deleteFruit(int n) {
        if (fruitAmount - n >= 0) { // Si no se queda con cantidad negativa
            deleteF(n); // Se resta la cantidad de fruta al cajon
        }
        else { // Si se queda con cantidad negativa
            cout << "No se puede quitar mas fruta del cajon " << id << endl; // Se muestra un mensaje de error
        }
    }

};