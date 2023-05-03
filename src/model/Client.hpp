#include <iostream>
#include <array>
#include <random>
#include <initializer_list>
#include <string>
using namespace std;


#ifndef CLIENT_HPP
#define CLIENT_HPP

static const array<string, 10> names = {"Benjamín","Vicente","Martín","Matías","Joaquín","Lucía","María","Paula","Daniela","Sara"};

class Client{
    public:
        Client(){name = names.at(rand()%10);};
        Client(string n){name=n;};
        string toString(){return name + ": ";};
        void imprimir(){cout << toString();}

    private:
        string name;


};
#endif
