//Representa un pedido en general, con sus propiedades como el nombre del cliente, el tipo de pedido (mayorista o minorista), el tipo de fruta y la cantidad de frutas solicitadas.
#include <iostream>
#include "../model/Client.hpp"
#include "../utils/enum.hpp"

using namespace std;

#ifndef ORDER
#define ORDER
class Order{
    private:
        Client client;
        FruitType type;
        Status status;
    
    public:
        //Constructores
        Order(Client client, FruitType type){this->client=client ; this->type=type; this->status=Status::PENDING;};
        Order();

        //setters & getters
        void setStatus(Status newStatus){status=newStatus;};
        Client getClient(){return client;};
        FruitType getFruitType(){return type;};
        Status getStatus(){return status;};
};
#endif