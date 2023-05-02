#include <iostream>
#include "model\Client.h"
#include "model\Crate.h"
#include "utils\enum.hpp"
#include "orders\RetailOrder.h"
#include "orders\WholesaleOrder.h"
#include "stock\OrderManager.h"
#include "stock\Warehouse.h"

using namespace std;
int main( int argc, char *argv[])
{
    Warehouse *deposito = new Warehouse();
    //OrderManager *cajero = new OrderManager(*deposito);

    Client *client1 = new Client();
    Client *client2 = new Client();

    Crate *crate1 = new Crate("crate1", FruitType::APPLE, 15.0f);
    Crate *crate2 = new Crate("crate2", FruitType::BANANA,2.0f);



    RetailOrder *orden1 = new RetailOrder(2.0,*client1,FruitType::APPLE);

}
