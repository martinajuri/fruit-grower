//Representa un pedido en general, con sus propiedades como el nombre del cliente, el tipo de pedido (mayorista o minorista), el tipo de fruta y la cantidad de frutas solicitadas.
#include <iostream>
#include "../model/Client.cpp"
#include "../utils/enum.hpp"


using namespace std;

class Order{
    public:
        // generator & destructor
        Order(Client client, FruitType type){this->client=client ; this->type=type; this->status=Status::PENDING;};
        ~Order();

        //getters
        Client getClient(){return client;};
        FruitType getFruitType(){return type;};
        Status getStatus(){return status;};

        //setters
        void setStatus(Status newStatus){status=newStatus;};

    private:
        Client client;
        FruitType type;
        Status status;
    
};
