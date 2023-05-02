//Representan los pedidos minoristas, hereda de la clase "Order" 
#include <iostream>
#include <string>
#include "Order.cpp"
#include "../model/Client.cpp"
#include "../utils/enum.hpp"


using namespace std;

class RetailOrder : public Order{
    public:
    
        RetailOrder(float weight, Client client, FruitType type): Order(client, type){this->weight=weight;};
        float getAmount(){return weight;};
        string toString(){return getClient().toString() + to_string(getAmount()) + " " + fruitTypeToString(getFruitType()); };
        void imprimir(){cout << getClient().toString() + to_string(getAmount()) + " " + fruitTypeToString(getFruitType());}
    private:
        float weight;
        

};