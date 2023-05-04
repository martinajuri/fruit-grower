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
    private:
        string name;
    
    public:
        //Constructores
        Client(){name = names.at(rand()%10);};
        Client(string n){name=n;};

        //Metodos de impresion
        string toString(){return name + ": ";};
        void imprimir(){cout << toString();}
};
#endif
