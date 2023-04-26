#include <iostream>
#include "../utils/enum.hpp"

using namespace std;

template <class T>
class Crate{

    public:
        FruitCrate(); //generator
        addFruit();
        deleteFruit()

    private:
        Id id;
        FruitType type;
        int fruitAmount;
        int maxWeight = 20;
};