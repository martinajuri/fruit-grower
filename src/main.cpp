#include <iostream>
#include "model\Client.h"
/*
#include "model\Crate.h"
#include "utils\enum.hpp"
#include "orders\RetailOrder.h"
#include "orders\WholesaleOrder.h"
#include "stock\OrderManager.h"
#include "stock\Warehouse.h"
*/

#include "structure\List.h"

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
   bool isEmpty(void){return czo->isEmpty();};
        T cabeza(void); 
        List* resto(void); 
        string toPrint(string p);
        int size();
        void borrar(void); 
        void borrar_ultimo();
        void concat(List<T>* l1);
        List<T>* copy(void);
        void tomar(int n);
        T last();
        void imprimir();*/

    List<int> *lista = new List<int>;
    Client *client1 = new Client();
    Client *client2 = new Client();    
    Client *client3 = new Client();
    Client *client4 = new Client();
    int n1=1;
    int n2=2;
    int n3=3;
    int n4=4;

    lista->add(n1);
    lista->add(n2);
    lista->add(n3);
    lista->add(n4);

    cout << lista->toPrint("") << endl;
    cout << lista->last();


}
