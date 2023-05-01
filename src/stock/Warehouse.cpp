//Representa un elemento de stock en general, con propiedades como el tipo de fruta, la cantidad de cajones disponibles.
#include <iostream>
#include "../structure/List.cpp"
#include "../structure/CrateStack.cpp"
#include "../structure/Nodo.cpp"
#include "../model/Crate.cpp"

class Warehouse{
    private:
        List<CrateStack> *appleList = new List<CrateStack>;
        List<CrateStack> *bananaList = new List<CrateStack>;
        List<CrateStack> *orangeList = new List<CrateStack>;

    public:
        Warehouse();
        ~Warehouse();
        List<CrateStack> listaIndicada(FruitType type);
        void addCrate(int n, FruitType type);

};

// Devuelve la lista indicada dependiendo el tipo de fruta que se quiere agregar
List<CrateStack> Warehouse::listaIndicada(FruitType type){
    switch (type)
    {
    case FruitType::APPLE:
        return *appleList;
        break;
    case FruitType::BANANA:
        return *bananaList;
        break;
    case FruitType::ORANGE:
        return *orangeList;
        break;
    }
};

