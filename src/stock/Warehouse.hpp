//Representa un elemento de stock en general, con propiedades como el tipo de fruta, la cantidad de cajones disponibles.
#include <iostream>
#include "../structure/List.hpp"
#include "../structure/CrateStack.hpp"
#include "../model/Crate.hpp"
#include "../orders/RetailOrder.hpp"
#include "../orders/WholesaleOrder.hpp"

using namespace std;

#pragma once
class Warehouse{
    private:
        List<CrateStack> *appleList = new List<CrateStack>;
        List<CrateStack> *bananaList = new List<CrateStack>;
        List<CrateStack> *orangeList = new List<CrateStack>;

    public:
        Warehouse();
        List<CrateStack> listaIndicada(FruitType type);
        void addFruit(Crate c);
        void concretarOrdenR(RetailOrder order);
        void concretarOrdenW(WholesaleOrder order);
        float stockCompleto(FruitType type);
        bool checkOrderW(WholesaleOrder order);
        bool checkOrderR(RetailOrder order);
};
