#include <iostream>
#include "../utils/enum.hpp"

using namespace std;

template <class T>
class FruitCrate{

    public:
        FruitCrate(); //generator

    private:
        Id id;
        FruitTypes type;
        int fruitAmount;

};