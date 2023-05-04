// Representan los pedidos minoristas, hereda de la clase "Order"
#include <iostream>
#include <string>
#include <iomanip>
#include "Order.hpp"
#include "../model/Client.hpp"
#include "../utils/enum.hpp"

using namespace std;

#ifndef RETAIL_ORDER_HPP
#define RETAIL_ORDER_HPP
class RetailOrder : public Order
{
public:
    RetailOrder(float weight, Client client, FruitType type) : Order(client, type) { this->weight = weight; };
    RetailOrder(): Order(){weight=0.0f;};
    float getAmount() { return weight; };
    void imprimir() { cout <<"  "<< getClient().toString() <<"\n   Pedido: "<< fixed << setprecision(1)<< getAmount() << " kg de " << fruitTypeToString(getFruitType()) << " \n   Estado: " << statusToString(getStatus())<<endl; }

private:
    float weight;
};
#endif