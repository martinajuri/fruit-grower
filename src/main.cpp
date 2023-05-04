#include <iostream>
#include "./stock/Warehouse.cpp"
#include "./model/Crate.cpp"
#include "stock\OrderManager.cpp"
#include "./utils/enum.hpp"

/*

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

//Establecer prioridad
string rta;
bool retailPriority;
cout<<"Devuelva true si la prioridad la tendran los minoristas"<<endl;
cin>>rta;
if(rta!="true"){
    retailPriority = false;
}

//Creación de depósito y cajas
    Warehouse *deposito = new Warehouse();
    Crate *crate1 = new Crate("crate1", FruitType::APPLE, 15.0f);
    Crate *crate2 = new Crate("crate2", FruitType::BANANA,8.0f);
    Crate *crate3 = new Crate("crate3", FruitType::ORANGE,10.0f);
    Crate *crate4 = new Crate("crate4", FruitType::ORANGE,15.0f);
    Crate *crate5 = new Crate("crate5", FruitType::BANANA,18.0f);
    Crate *crate6 = new Crate("crate6", FruitType::APPLE, 19.0f);
    deposito->addFruit(crate1);
    deposito->addFruit(crate2);
    deposito->addFruit(crate3);
    deposito->addFruit(crate4);
    deposito->addFruit(crate5);
    deposito->addFruit(crate6);
    deposito->imprimirWarehouse();
    cout<<"\n"<<endl;

//Creación de ordenes

    //hago el gerente de pedidos
    OrderManager *Ordermanager = new OrderManager(*deposito);
    
    //creo clientes
    Client *fer = new Client("Fer");
    Client *marcos = new Client("Marcos");    
    Client *sofi = new Client("Sofi");
    Client *vicente = new Client("Vicente");    
    
    //Creo las ordenes
    RetailOrder *ordenMar = new RetailOrder(2.0,*marcos,FruitType::APPLE);
    WholesaleOrder *ordenSofi = new WholesaleOrder(2,*sofi,FruitType::BANANA);
    WholesaleOrder *ordenFer = new WholesaleOrder(10, *fer,FruitType::ORANGE);
    RetailOrder *ordenVicente = new RetailOrder(10.0, *vicente,FruitType::BANANA);

    //Meto las ordenes en OrderManager
    Ordermanager->addRetailOrder(ordenMar);
    Ordermanager->addRetailOrder(ordenVicente);
    Ordermanager->addWholesaleOrder(ordenFer);
    Ordermanager->addWholesaleOrder(ordenSofi);
    Ordermanager->imprimir();
    cout<<"\n"<<endl;
    
    // //Intento llevar a cabo los pedidos
    // Ordermanager->makeOrder(retailPriority);
    // Ordermanager->makeOrder(retailPriority);

    // //actualizo impresión de warehouse y ordermanager
    // cout<<"\n"<<endl;
    // Ordermanager->imprimir();
    // deposito->imprimirWarehouse(); 

}