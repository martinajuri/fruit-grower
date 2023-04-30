#include <iostream>
#include "model\Client.cpp"
#include "model\Crate.cpp"
#include "utils\enum.hpp"

using namespace std;
int main( int argc, char *argv[])
{
   
   Client *client1 = new Client();
   Client *client2 = new Client();

   Crate *crate1 = new Crate("crate1", FruitType::APPLE, 15.0f);
   Crate *crate2 = new Crate("crate2", FruitType::BANANA,2.0f);

    cout << client1->toString() << " "<< crate1->toString()<< endl;
    cout << client2->toString() << " "<< crate2->toString()<< endl;
    
    crate1->deleteFruit(5);
    cout << crate1->toString()<< endl;

}
