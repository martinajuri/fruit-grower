//Representa un pedido en general, con sus propiedades como el nombre del cliente, el tipo de pedido (mayorista o minorista), el tipo de fruta y la cantidad de frutas solicitadas.
#include <iostream>
#include "../model/Client.cpp"
#include "../utils/enum.hpp"


using namespace std;

class Order{
    public:
        Order(Client client, FruitType type, int amount){this->client=client ; this->type=type; this->amount=amount;};
        ~Order();
    private:
        Client client;
        FruitType type;
        int amount;

};