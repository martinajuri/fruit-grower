#include <iostream>
#include "stock\Warehouse.cpp"
#include "model\Crate.cpp"

#include "utils\enum.hpp"

/*
#include "stock\OrderManager.cpp"
#include "structure\List.cpp"
#include "model\Crate.hpp"
#include "structure\CrateStack.cpp"
#include "structure\Queue.hpp"
#include "structure\CrateStack.hpp"
#include "model\Client.hpp"
#include "orders\RetailOrder.hpp"
#include "orders\WholesaleOrder.hpp"
#include "structure\List.cpp"
#include "model\Crate.cpp"
#include "structure\CrateStack.cpp"
*/



using namespace std;
int main( int argc, char *argv[])
{
    /*
    OrderManager *cajero = new OrderManager(*deposito);


    RetailOrder *orden1 = new RetailOrder(2.0,*client1,FruitType::APPLE);
    WholesaleOrder *orden2 = new WholesaleOrder(5,*client2,FruitType::BANANA);

    //List<int> *lista = new List<int>;

    
    CrateStack *pila = new CrateStack(FruitType::APPLE);

    pila->apilar(crate1);
    pila->apilar(crate2);
    pila->apilar(crate3);

    pila->imprimirStack();

    cout << "Capacidad disponible del stack: "<<endl <<pila->stackCapacity()<<endl;
    cout << "Cantidad de cajas " <<pila->almacenado()<< endl;
    cout << "Capacidad disponible del tope de la pila: " <<pila->capacidad_tope()<< endl;
    cout << "Cantidad de kilos que contiene la pila: "<< pila->cantidad_kilos();
    
    Client *fer = new Client("Fer");
    Client *marcos = new Client("Marcos");    
    Client *sofia = new Client("Sofia");  
    
    RetailOrder *ordenMar = new RetailOrder(2.0,*marcos,FruitType::APPLE);
    WholesaleOrder *ordenSofi = new WholesaleOrder(2,*sofia,FruitType::BANANA);
    WholesaleOrder *ordenFer = new WholesaleOrder(10, *fer,FruitType::ORANGE);

    List<int> *lista = new List<int>;
    Crate *crate1 = new Crate("crate1", FruitType::APPLE, 15.0f);
    Crate *crate2 = new Crate("crate2", FruitType::APPLE,7.0f);
    Crate *crate3 = new Crate("crate3", FruitType::APPLE,10.0f);
    
    CrateStack *pila = new CrateStack(FruitType::APPLE);

    pila->apilar(crate1);
    pila->apilar(crate2);
    pila->apilar(crate3);

    pila->imprimirStack();

    */

    Warehouse *deposito = new Warehouse();
    Crate *crate1 = new Crate("crate1", FruitType::APPLE, 15.0f);
    Crate *crate2 = new Crate("crate2", FruitType::BANANA,7.0f);
    Crate *crate3 = new Crate("crate3", FruitType::ORANGE,10.0f);

    deposito->addFruit(crate1);
    deposito->addFruit(crate2);
    deposito->addFruit(crate3);


    //deposito->imprimirWarehouse();
}
