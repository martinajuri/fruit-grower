//Representan los pedidos mayoristas, hereda de la clase "Order" 
#include <iostream>
#include "Order.hpp"
#include "../model/Client.hpp"
#include "../utils/enum.hpp"


using namespace std;

#ifndef WHOLESALE_ORDER
#define WHOLESALE_ORDER
class WholesaleOrder : public Order{
    public:
    
        WholesaleOrder(int amount, Client client, FruitType type): Order(client, type){this->amount=amount;};
        WholesaleOrder();
        int getAmount(){return amount;};
        string toString(){return getClient().toString() + to_string(getAmount()) + " cajones de " + fruitTypeToString(getFruitType()); };
        void imprimir(){cout << getClient().toString() + to_string(getAmount()) + " " + fruitTypeToString(getFruitType())+ " Estado: " + statusToString(getStatus());}

    private:
        int amount;
        

};
#endif