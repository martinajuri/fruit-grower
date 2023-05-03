#include <iostream>
#include <string> 
#include "../utils/enum.hpp"
#include "Crate.hpp"

using namespace std;
#ifndef CRATE_CPP
#define CRATE_CPP
void Crate::addFruit(float n) {
    if (capacity()>= n) { // Si hay capacidad mayor o igual a la cantidad que se quiere agregar
        setFruitAmount(getFruitAmount()+n); // Se suma la cantidad de fruta al cajon
    }
    else { // Si se supera el maximo peso soportado
        cout << "No se puede agregar mas fruta al cajon " << id << endl; // mensaje de error
    }
}

// take fruit out of the crate
void Crate::deleteFruit(float n) {
    if (getFruitAmount()>n) { // Si hay mas cantidad de la que se quiere sacar
        setFruitAmount(getFruitAmount()-n); // Se resta la cantidad de fruta al cajon
    }
    else { 
        cout << "No se puede quitar mas fruta del cajon " << id << endl; // mensaje de error
    }
}
#endif