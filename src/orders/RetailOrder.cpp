//Representan los pedidos minoristas, hereda de la clase "Order" 
#include <iostream>
#include "Order.cpp"
#include "../model/Client.cpp"
#include "../utils/enum.hpp"


using namespace std;

class RetailOrder : public Order{
    public:
    
        RetailOrder(int amount, Client client, FruitType type): Order(client, type){weight=amount;};
        int getAmount(){return weight;};


    private:
        int weight;
        

};