#include <iostream>
#include <array>
#include <random>
#include <initializer_list>
using namespace std;

#ifndef NAMES
#define NAMES
static const array<string, 10> names = {"Benjamín","Vicente","Martín","Matías","Joaquín","Lucía","María","Paula","Daniela","Sara"};
#endif

class Client{
    public:
        Client(){name = names.at(rand()%10);};
        //Client();
        ~Client();
        string toString(){return name + ": ";};

    private:
        string name;


};