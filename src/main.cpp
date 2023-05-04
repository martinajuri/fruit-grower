#include <iostream>
#include "utils\enum.hpp"
#include "stock\Warehouse.cpp"
#include "stock\OrderManager.cpp"
#include "structure\List.cpp"
#include "model\Crate.cpp"
#include "structure\CrateStack.cpp"
#include "model\Client.hpp"
#include "orders\RetailOrder.hpp"
#include "orders\WholesaleOrder.hpp"

/*
#include "stock\Warehouse.cpp"
#include "structure\List.cpp"
#include "model\Crate.cpp"
#include "model\Crate.hpp"
#include "structure\CrateStack.cpp"
#include "structure\Queue.hpp"
#include "structure\CrateStack.hpp"
*/



using namespace std;
int main()
{
    /*
    OrderManager *cajero = new OrderManager(*deposito);


    RetailOrder *orden1 = new RetailOrder(2.0,*client1,FruitType::APPLE);
    WholesaleOrder *orden2 = new WholesaleOrder(5,*client2,FruitType::BANANA);

    //List<int> *lista = new List<int>;
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

    

    */
    Warehouse *deposito = new Warehouse();

    Crate *crate1 = new Crate("crate1", FruitType::APPLE, 15.0f);
    Crate *crate2 = new Crate("crate2", FruitType::ORANGE,7.0f);
    Crate *crate3 = new Crate("crate3", FruitType::BANANA,10.0f);
    Crate *crate4 = new Crate("crate4", FruitType::ORANGE,10.0f);
    Crate *crate5 = new Crate("crate5", FruitType::APPLE,2.0f);
    
    CrateStack *pilaManzanas = new CrateStack(FruitType::APPLE);
    CrateStack *pilaNaranjas = new CrateStack(FruitType::ORANGE);
    CrateStack *pilaBananas = new CrateStack(FruitType::BANANA);

    pilaManzanas->apilar(crate1);
    pilaNaranjas->apilar(crate2);
    pilaBananas->apilar(crate3);

    pilaManzanas->imprimirStack();
    pilaNaranjas->imprimirStack();
    pilaBananas->imprimirStack();

    cout<<endl;

    deposito->addFruit(FruitType :: APPLE,pilaManzanas);
    deposito->addFruit(FruitType :: ORANGE,pilaNaranjas);
    deposito->addFruit(FruitType :: BANANA,pilaBananas);
    deposito->imprimirWarehouse();
    cout<<endl;
    pilaManzanas->apilar(crate5);
    pilaNaranjas->apilar(crate4);

    deposito->imprimirWarehouse();
    cout<<endl;

    OrderManager *admin = new OrderManager(*deposito);

    Client *fer = new Client("Fer");
    Client *marcos = new Client("Marcos");    
    Client *sofia = new Client("Sofia");  

    RetailOrder *ordenMar = new RetailOrder(2.0,*marcos,FruitType::APPLE);
    WholesaleOrder *ordenSofi = new WholesaleOrder(2,*sofia,FruitType::BANANA);
    WholesaleOrder *ordenFer = new WholesaleOrder(10, *fer,FruitType::ORANGE);

    admin->addRetailOrder(ordenMar);
    admin->addWholesaleOrder(ordenSofi);
    admin->addWholesaleOrder(ordenFer);

    admin->imprimir();
    cout<<endl;

    admin->makeOrder(true);
    admin->makeOrder(true);

    admin->imprimir();
    cout<<endl;
    
    deposito->imprimirWarehouse();

}
