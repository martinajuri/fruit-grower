//Representan los pedidos minoristas, hereda de la clase "Order" 
#include <iostream>
#include "Order.cpp"
#include "../model/Client.cpp"
#include "../utils/enum.hpp"


using namespace std;

class RetailOrder : public Order{
    public:
        RetailOrder(Client client, FruitType type, int amount);

    

};