#include <iostream>
#include "model\Client.hpp"
/*#include "model\Crate.h"
#include "utils\enum.hpp"
#include "orders\RetailOrder.h"
#include "orders\WholesaleOrder.h"
#include "stock\OrderManager.h"
#include "stock\Warehouse.h"
*/

#include "structure\List.hpp"
#include "structure\Queue.hpp"

using namespace std;
int main( int argc, char *argv[])
{
    /*
    Warehouse *deposito = new Warehouse();
    OrderManager *cajero = new OrderManager(*deposito);

    Crate *crate1 = new Crate("crate1", FruitType::APPLE, 15.0f);
    Crate *crate2 = new Crate("crate2", FruitType::BANANA,2.0f);

    RetailOrder *orden1 = new RetailOrder(2.0,*client1,FruitType::APPLE);
    WholesaleOrder *orden2 = new WholesaleOrder(5,*client2,FruitType::BANANA);
    */

   /*
   T tope() { return this->last(); };
    bool colavacia(void) { return this->isEmpty(); };
    void encolar(T a) { this->add(a); };
    void desencolar(void) { this->borrar_ultimo(); };
    T ultimo(void) { return this->cabeza(); };
    string toPrint(string s) { return this->toPrint(s); };
    */

    //List<int> *lista = new List<int>;
    Queue<Client> *cola = new Queue<Client>;
    Client *client1 = new Client();
    Client *client2 = new Client();    
    Client *client3 = new Client();
    Client *client4 = new Client();


    cola->encolar(*client1);
    cola->encolar(*client2);
    cola->encolar(*client3);
    cola->encolar(*client4);

    cola->imprimir();
}
