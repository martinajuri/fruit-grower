#include <iostream>
#include <array>
#include <random>
#include <initializer_list>
#include <string>
using namespace std;

#ifndef NAMES
#define NAMES
static const array<string, 10> names = {"Benjamín","Vicente","Martín","Matías","Joaquín","Lucía","María","Paula","Daniela","Sara"};
#endif

#pragma once
class Client{
    public:
        Client(){name = names.at(rand()%10);};
        Client(string n){name=n;};
        string toString(){return name + ": ";};
        void imprimir(){cout << toString();}

    private:
        string name;


};
