// Representa el gestor pedidos para consultar y entregar los pedidos pendientes.
#include <iostream>
#include "../orders/WholesaleOrder.hpp"
#include "../orders/RetailOrder.hpp"
#include "../model/Client.hpp"
#include "../utils/enum.hpp"
#include "../structure/Queue.hpp"
#include "../stock/Warehouse.hpp"
#include "../stock/Warehouse.cpp"

#ifndef ORDER_MANAGER_HPP
#define ORDER_MANAGER_HPP
class OrderManager{

    private:
        Queue<RetailOrder> *retailQueue;
        Queue<WholesaleOrder> *wholesaleQueue;
        Warehouse warehouse;
    public:

        //Constructor y destructor
        OrderManager(Warehouse w){
            warehouse=w;
            retailQueue = new Queue<RetailOrder>();
            wholesaleQueue = new Queue<WholesaleOrder>();
        };
        OrderManager();

        //Agrega a la cola una orden minorista o mayorista
        void addRetailOrder(RetailOrder *ro){retailQueue->encolar(ro);}
        void addWholesaleOrder(WholesaleOrder *wo){wholesaleQueue->encolar(wo);}
        
        //Borra de la cola una orden
        void removeRetailOrder(){retailQueue->desencolar();}
        void removeWholesaleOrder(){wholesaleQueue->desencolar();}
    
        void makeOrder(bool b);
        void makeRetailOrder(RetailOrder *order);
        void makeWholesaleOrder(WholesaleOrder *order);

        void imprimir();
};
#endif