//Representa un elemento de stock en general, con propiedades como el tipo de fruta, la cantidad de cajones disponibles.
#include <iostream>
#include "../structure/List.hpp"
#include "../structure/List.cpp"
#include "../structure/CrateStack.hpp"
#include "../structure/CrateStack.cpp"
#include "../model/Crate.hpp"
#include "../model/Crate.cpp"
#include "../orders/RetailOrder.hpp"
#include "../orders/WholesaleOrder.hpp"
#include "Warehouse.hpp"

using namespace std;
#ifndef WAREHOUSE_CPP
#define WAREHOUSE_CPP
//Devuelve la lista indicada dependiendo el tipo de fruta que se quiere agregar
List<CrateStack> Warehouse::listaIndicada(FruitType type){
    switch (type)
    {
    case FruitType::APPLE:
        return *appleList;
        break;
    case FruitType::BANANA:
        return *bananaList;
        break;
    default:
        return *orangeList;
        break;
    }
};

// Llega al deposito un cajon con una cantida de una fruta 
void Warehouse::addFruit(FruitType f, CrateStack *p){

    // Si todo lo del cajon entra en la ultima pila, este se agrega
   switch (f)
    {
    case FruitType::APPLE:
        appleList->add(p);
        break;
    case FruitType::BANANA:
        bananaList->add(p);
        break;
    default:
        orangeList->add(p);
        break;
    }
};

// Concreta una orden minorista
void Warehouse::concretarOrdenR(RetailOrder order){

    List<CrateStack> list = listaIndicada(order.getFruitType());
    if(order.getAmount()<=list.cabeza()->cantidad_kilos() ){
        list.cabeza()->desapilarKilos(order.getAmount());
        //cout << "Pedido concretado" << endl;

    }
    else{
        float aux = order.getAmount()-list.cabeza()->cantidad_kilos();
        list.cabeza()->desapilarKilos(list.cabeza()->cantidad_kilos());
        list.borrar();
        list.cabeza()->desapilarKilos(aux);
        //cout << "Pedido concretado" << endl;
    }
};

// Concreta una orden mayorista
void Warehouse::concretarOrdenW(WholesaleOrder order){
    
    List<CrateStack> list = listaIndicada(order.getFruitType());
    Crate *cabezaAux = list.cabeza()->cabeza();
    
    if(list.cabeza()->cabeza()->hasCapacity()&&list.cabeza()->size()==1){
        cout << "No se pudo realizar el pedido"<<endl;
    }
    else if(list.cabeza()->cabeza()->hasCapacity()&&!(list.cabeza()->size()==1)){
        list.cabeza()->desapilar();
        concretarOrdenW(order);
        list.cabeza()->apilar(cabezaAux);
    }
    else if(order.getAmount()<=list.cabeza()->almacenado()){
            list.cabeza()->desapilarCajonEntero(order.getAmount());
    }
    else{
        int aux = order.getAmount()-list.cabeza()->almacenado();
        list.borrar();
        list.cabeza()->desapilarCajonEntero(aux);
    }
};

// Devuelve la cantidad de kilos de un tipo de fruta
float Warehouse::stockCompleto(FruitType type){
    List<CrateStack> list = listaIndicada(type);
    int aux = list.size()-1;
    float cantidadKilos = aux*200.0;
    cantidadKilos += list.cabeza()->cantidad_kilos();
    return cantidadKilos;
    
};

//Intenta concretar una orden mayorista
bool Warehouse::checkOrderW(WholesaleOrder order){
    float aux = order.getAmount() *20.0;
    if(aux<=stockCompleto(order.getFruitType())){
        return true;
    }
    else{
        return false;
    }
};


// Intenta concretar una orden minorista
bool Warehouse::checkOrderR(RetailOrder order){

    if(order.getAmount()<=stockCompleto(order.getFruitType())){
        return true;
    }
    else{
        return false;
    }
};

//Imprimir
void Warehouse::imprimirWarehouse(){
    cout<<"Deposito: "<<endl<<"Seccion Manzanas: "<<endl; 
    appleList->imprimir(); 
    cout<<"Seccion Bananas: "<<endl; 
    bananaList->imprimir(); 
    cout<<"Seccion Naranjas: "<<endl; 
    orangeList->imprimir(); 
};
#endif