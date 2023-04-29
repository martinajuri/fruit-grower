//Representa un pedido en general, con sus propiedades como el nombre del cliente, el tipo de pedido (mayorista o minorista), el tipo de fruta y la cantidad de frutas solicitadas.
#include <iostream>
#include "../model/Client.cpp"
#include "../utils/enum.hpp"


using namespace std;

class Order{
    public:
        Order();
        ~Order();
        Client getClient(){return client;};
        FruitType getFruitType(){return type;};
        int getAmount(){return amount;};
        Status getStatus(){return status;};
        void setStatus(Status newStatus){status=newStatus;};

    private:
        Client client;
        FruitType type;
        int amount;
        Status status;

    Order(Client client, FruitType type, int amount){
    this->client=client ; 
    this->type=type; 
    this->amount=amount;
    this->status=Status::READY;
    };

    
};
