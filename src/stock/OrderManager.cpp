// Representa el gestor pedidos para consultar y entregar los pedidos pendientes.
#include <iostream>
#include "../orders/WholesaleOrder.hpp"
#include "../orders/RetailOrder.hpp"
#include "../model/Client.hpp"
#include "../utils/enum.hpp"
#include "../structure/Queue.hpp"
#include "Warehouse.hpp"
#include "Warehouse.cpp"
#include "OrderManager.hpp"

#ifndef ORDER_MANAGER_CPP
#define ORDER_MANAGER_CPP
//atender un pedido minorista
void OrderManager::makeRetailOrder(RetailOrder *order){
    order->setStatus(Status::IN_PROGRESS);
    if(warehouse.checkOrderR(*order)){
        warehouse.concretarOrdenR(*order);
        order->setStatus(Status::FINISHED);
        removeRetailOrder();
    }
    else{
        cout<<"No fue posible concretar la orden"<<endl;
    }
};

//atender un pedido mayorista
void OrderManager::makeWholesaleOrder(WholesaleOrder *order){   
    order->setStatus(Status::IN_PROGRESS);
    if(warehouse.checkOrderW(*order)){
        warehouse.concretarOrdenW(*order);
        order->setStatus(Status::FINISHED);
        cout << "ORDEN REALIZADA:" <<endl;
        order->imprimir();
        removeWholesaleOrder();
    }else{
        cout<<"No fue posible concretar la orden"<<endl;
    }
};

//Atender un pedido, recibe true si le da prioridad a los pedidos minoristas y false si da prioridad a los mayoristas
void OrderManager::makeOrder(bool b){
    if(b){
       if(retailQueue->size()>0){
        makeRetailOrder(retailQueue->tope());
        }else{
        makeWholesaleOrder(wholesaleQueue->tope());
        } 
    }else{
        if(wholesaleQueue->size()>0){
            makeWholesaleOrder(wholesaleQueue->tope());
        }else{
            makeRetailOrder(retailQueue->tope());
        }
    }
}

//Imprimir el listado de pedidos minoristas y mayoristas
void OrderManager::imprimir(){
    cout<<"Pedidos minoristas: " <<endl;retailQueue->imprimirQueue();
    cout<<"Pedidos mayoristas: " <<endl;wholesaleQueue->imprimirQueue();
}
#endif