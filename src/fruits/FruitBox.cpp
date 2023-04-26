#include <iostream>
#include "../utils/enum.hpp"

using namespace std;

template <class T>
class FruitBox{

    public:
        FruitCrate(); //generator
        addFruit();
        deleteFruit()

    private:
        Id id;
        FruitTypes type;
        int fruitAmount;
        int maxWeight = 20;
};