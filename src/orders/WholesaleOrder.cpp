//Representan los pedidos mayoristas, hereda de la clase "Order" 
#include <iostream>
#include "Order.cpp"
#include "../model/Client.cpp"
#include "../utils/enum.hpp"


using namespace std;

class WholesaleOrder : public Order{
    public:
    
        WholesaleOrder(int amount, Client client, FruitType type): Order(client, type){this->amount=amount;};
        int getAmount(){return amount;};


    private:
        int amount;
        

};