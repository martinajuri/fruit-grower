#include <iostream>
#include "../utils/enum.hpp"

using namespace std;



//Representa una fruta en general, con sus propiedades como el tipo de fruta, el peso y el identificador de cajón.
class Fruit {
    
    public:
        Fruit(FruitType type); // generator
    
    private:
        FruitType type; // kind of fruit
        

};