#include <iostream>
#include <array>
#include <random>
#include <initializer_list>
using namespace std;


static const array<string, 10> names = {"Benjamín","Vicente","Martín","Matías","Joaquín","Lucía","María","Paula","Daniela","Sara"};

class Client{
    public:
        Client(){name = names.at(rand()%10);};
        ~Client();
        string toString(){return name + ": ";};

    private:
        string name;


};