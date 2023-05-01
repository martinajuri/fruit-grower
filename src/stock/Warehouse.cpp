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
        void addCrate(float f, FruitType type);
        void deleteCrate(int n, FruitType type);
        void deleteCrate(float f, FruitType type);
        void apilarN(int n, FruitType type, List<CrateStack> list);
        void apilarF(float f, FruitType type, List<CrateStack> list);
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

// Apila una cantida n de cajones de un tipo
void Warehouse::addCrate(int n, FruitType type){

    List<CrateStack> list = listaIndicada(type);
    apilarN(n,type,list);

}

// Apila una cantida f de kilos de una fruta 
void Warehouse::addCrate(float f, FruitType type){

    List<CrateStack> list = listaIndicada(type);
    apilarF(f,type,list);

}

// Apila una cantidad n de cajones
void Warehouse :: apilarN(int n, FruitType type, List<CrateStack> list){
        
        for (int i = 0; i < n; i++)
        {
            Crate *c = new Crate("crate"+n, type, 20.0);
            list.last().apilar(*c);
        }
        
    }

void Warehouse :: apilarF(float f, FruitType type, List<CrateStack> list){
        
        
}
