//Representan los pedidos minoristas, hereda de la clase "Order" 
#include <iostream>
#include <string>
#include "Order.hpp"
#include "../model/Client.hpp"
#include "../utils/enum.hpp"

using namespace std;

#pragma once
class RetailOrder : public Order{
    public:
    
        RetailOrder(float weight, Client client, FruitType type): Order(client, type){this->weight=weight;};
        RetailOrder();
        float getAmount(){return weight;};
        string toString(){return getClient().toString() + to_string(getAmount()) + " " + fruitTypeToString(getFruitType()); };
        void imprimir(){cout << getClient().toString() + to_string(getAmount()) + " " + fruitTypeToString(getFruitType()) + " Estado: " + statusToString(getStatus());}
    private:
        float weight;
        
};
