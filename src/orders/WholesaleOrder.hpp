//Representan los pedidos mayoristas, hereda de la clase "Order" 
#include <iostream>
#include "Order.hpp"
#include "../model/Client.hpp"
#include "../utils/enum.hpp"

using namespace std;

#ifndef WHOLESALE_ORDER
#define WHOLESALE_ORDER
class WholesaleOrder : public Order{
    private:
        int amount;
    
    public:
        //Constructores
        WholesaleOrder(int amount, Client client, FruitType type): Order(client, type){this->amount=amount;};
        WholesaleOrder();

        //getters
        int getAmount(){return amount;};

        //Metodos de impresion
        void imprimir(){cout << getClient().toString() + to_string(getAmount()) + " cajones de " + fruitTypeToString(getFruitType())+ " Estado: " + statusToString(getStatus())<<endl;}
};
#endif