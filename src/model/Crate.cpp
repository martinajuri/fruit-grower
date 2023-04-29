#include <iostream>
#include <string> 
#include "../utils/enum.hpp"

using namespace std;


class Crate{

    public:
        //generator & destructor
        Crate(string id, FruitType type, int fruitAmount = 20){this->id=id;this->type=type;}; 
        ~Crate(); 

        //getters
        string getId(){return id;};
        FruitType getType(){return type;};
        int getFruitAmount(){return fruitAmount;};

        //setters
        void addFruit(int n){setFruitAmount(getFruitAmount()+n);};
        void deleteFruit(int n){setFruitAmount(getFruitAmount()-n);};

        //check capacity
        bool isEmpty(){return (getFruitAmount==0);};
        bool hasCapacity(){return (capacity()>0);};
        int capacity(){return maxWeight - fruitAmount;}

        //to string
        string toString(){return "Cajon " + id + ": " + to_string(fruitAmount) + to_string(type);}


    private:
        string id;
        FruitType type;
        int fruitAmount;
        int maxWeight = 20;

        void setFruitAmount(int n){fruitAmount=n;};

};