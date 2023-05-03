// Representan los pedidos minoristas, hereda de la clase "Order"
#include <iostream>
#include <string>
#include <iomanip>
#include "Order.hpp"
#include "../model/Client.hpp"
#include "../utils/enum.hpp"

using namespace std;

#ifndef RETAIL_ORDER
#define RETAIL_ORDER
class RetailOrder : public Order
{
public:
    RetailOrder(float weight, Client client, FruitType type) : Order(client, type) { this->weight = weight; };
    RetailOrder();
    float getAmount() { return weight; };
    void imprimir() { cout << getClient().toString() << fixed << setprecision(1)<< getAmount() << " kg de " << fruitTypeToString(getFruitType()) << " Estado: " << statusToString(getStatus())<<endl; }

private:
    float weight;
};
#endif