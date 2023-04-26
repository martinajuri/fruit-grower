#include <iostream>
#include "../utils/enum.hpp"

using namespace std;


class Crate{

    public:
        Crate(string id, FruitType type, int fruitAmount); //generator
        void addFruit(){};
        void deleteFruit(){};
        bool isEmpty(){};
        bool hasCapacity(){};

    private:
        string id;
        FruitType type;
        int fruitAmount;
        int maxWeight;
};