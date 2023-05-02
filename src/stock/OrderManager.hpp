// Representa el gestor pedidos para consultar y entregar los pedidos pendientes.
#include <iostream>
#include "../orders/WholesaleOrder.hpp"
#include "../orders/RetailOrder.hpp"
#include "../model/Client.hpp"
#include "../utils/enum.hpp"
#include "../structure/Queue.hpp"
#include "../stock/Warehouse.hpp"

#pragma once
class OrderManager{

    private:
        Queue<RetailOrder> *retailQueue = new Queue<RetailOrder>();
        Queue<WholesaleOrder> *wholesaleQueue = new Queue<WholesaleOrder>();
        Warehouse warehouse;
    public:

        //Constructor y destructor
        OrderManager(Warehouse w){warehouse=w;};
        OrderManager();

        //Agrega a la cola una orden minorista o mayorista
        void addRetailOrder(RetailOrder ro){retailQueue->encolar(ro);}
        void addWholesaleOrder(WholesaleOrder wo){wholesaleQueue->encolar(wo);}
        
        //Borra de la cola una orden
        void removeRetailOrder(){retailQueue->desencolar();}
        void removeWholesaleOrder(){wholesaleQueue->desencolar();}
    
        void makeOrder();
        void makeRetailOrder(RetailOrder order);
        void makeWholesaleOrder(WholesaleOrder order);

        void imprimir();
};

//concretar un pedido minorista
void OrderManager::makeRetailOrder(RetailOrder order){
    
    order.setStatus(Status::IN_PROGRESS);
    if(warehouse.checkOrderR(order)){
        warehouse.concretarOrdenR(order);
        order.setStatus(Status::FINISHED);
        removeRetailOrder();
    }
    else{
        cout<<"No fue posible concretar la orden"<<endl;
    }
};

//concretar un pedido mayorista
void OrderManager::makeWholesaleOrder(WholesaleOrder order){
    
    order.setStatus(Status::IN_PROGRESS);
    if(warehouse.checkOrderW(order)){
        warehouse.concretarOrdenW(order);
        order.setStatus(Status::FINISHED);
        removeWholesaleOrder();
    }
    else{
        cout<<"No fue posible concretar la orden"<<endl;
    }
};

void OrderManager::makeOrder(){
    if(retailQueue->size()>0){
        makeRetailOrder(retailQueue->tope());
    }
    else{
        makeWholesaleOrder(wholesaleQueue->tope());
    }
}

void OrderManager::imprimir(){
    cout<<"Pedidos minoristas: " <<endl;retailQueue->imprimir();
    cout<<"Pedidos mayoristas: " <<endl;wholesaleQueue->imprimir();
}