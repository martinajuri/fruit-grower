//Representan los pedidos mayoristas, hereda de la clase "Order" 
#include <iostream>
#include "Order.hpp"
#include "../model/Client.hpp"
#include "../utils/enum.hpp"


using namespace std;

#ifndef WHOLESALE_ORDER_HPP
#define WHOLESALE_ORDER_HPP
class WholesaleOrder : public Order{
    public:
    
        WholesaleOrder(int amount, Client client, FruitType type): Order(client, type){this->amount=amount;};
        WholesaleOrder():Order(){amount=0;};
        int getAmount(){return amount;};
        void imprimir(){cout <<"  "<< getClient().toString() <<"\n   Pedido: "<< to_string(getAmount()) + " cajones de " + fruitTypeToString(getFruitType())+ " \n   Estado: " + statusToString(getStatus())<<endl;}

    private:
        int amount;
        

};
#endif