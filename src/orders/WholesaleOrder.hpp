//Representan los pedidos mayoristas, hereda de la clase "Order" 
#include <iostream>
#include "Order.hpp"
#include "../model/Client.hpp"
#include "../utils/enum.hpp"


using namespace std;

#pragma once
class WholesaleOrder : public Order{
    public:
    
        WholesaleOrder(int amount, Client client, FruitType type): Order(client, type){this->amount=amount;};
        WholesaleOrder();
        int getAmount(){return amount;};
        string toString(){return getClient().toString() + to_string(getAmount()) + " cajones de " + fruitTypeToString(getFruitType()); };
        void imprimir(){cout << getClient().toString() + to_string(getAmount()) + " " + fruitTypeToString(getFruitType());}

    private:
        int amount;
        

};
