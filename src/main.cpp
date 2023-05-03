#include <iostream>
#include "model\Crate.cpp"
#include "model\Crate.hpp"
#include "structure\CrateStack.cpp"
#include "structure\CrateStack.hpp"

/*
#include "model\Client.hpp"
#include "utils\enum.hpp"
#include "orders\RetailOrder.hpp"
#include "orders\WholesaleOrder.hpp"
#include "stock\OrderManager.cpp"
#include "stock\Warehouse.cpp"
#include "structure\List.cpp"
#include "structure\Queue.hpp"
*/



using namespace std;
int main( int argc, char *argv[])
{
    /*
    Warehouse *deposito = new Warehouse();
    OrderManager *cajero = new OrderManager(*deposito);

    Queue<Client> *cola = new Queue<Client>; 

    RetailOrder *orden1 = new RetailOrder(2.0,*client1,FruitType::APPLE);
    WholesaleOrder *orden2 = new WholesaleOrder(5,*client2,FruitType::BANANA);

    //List<int> *lista = new List<int>;
    
    
    Client *fer = new Client("Fer");
    Client *marcos = new Client("Marcos");    
    Client *marti = new Client("Marti");
    Client *sofia = new Client("Sofia");  
    */

  
    Crate *crate1 = new Crate("crate1", FruitType::APPLE, 15.0f);
    Crate *crate2 = new Crate("crate2", FruitType::APPLE,7.0f);
    Crate *crate3 = new Crate("crate3", FruitType::APPLE,10.0f);
    
    CrateStack *pila = new CrateStack(FruitType::APPLE);

    pila->apilar(crate1);
    pila->apilar(crate2);
    pila->apilar(crate3);

    pila->imprimirStack();

    cout << "Capacidad disponible del stack: "<<endl <<pila->stackCapacity()<<endl;
    cout << "Cantidad de cajas " <<pila->almacenado()<< endl;
    cout << "Capacidad disponible del tope de la pila: " <<pila->capacidad_tope()<< endl;
    cout << "Cantidad de kilos que contiene la pila: "<< pila->cantidad_kilos();

}
