#include <iostream>
#include "./stock/Warehouse.cpp"
#include "stock\OrderManager.cpp"
#include "./utils/enum.hpp"

using namespace std;

void entrarDeposito(Warehouse *deposito);
void entrarCaja(OrderManager *admin);
FruitType tipoElegido(char option);
void ingresarPedido(OrderManager *admin);
int main( int argc, char *argv[])
{

    Warehouse *deposito = new Warehouse();
    OrderManager *admin = new OrderManager(*deposito);

    cout << "\n¡Bienvenido a la verdulería de Vicente!\n" <<endl;

    while (true)
    {
        cout <<endl<< "A donde te quieres dirigir?"<< endl<< "A) Deposito"<<endl<<"B) Caja"<<endl<<"C) Impresiones"<<endl;
        char option;
        cin >> option;
        cout <<endl;
        
        switch (option)
        {
        case 'A':
            entrarDeposito(deposito);
            break;
        case 'B':
            entrarCaja(admin);
            break;
        case 'C':
            cout<<"Que desea imprimir?" << endl << "A) Estado del Deposito"<<endl<<"B) Estado de las ordenes"<<endl;
            char option6;
            cin >> option6;
            cout <<endl;

            switch (option6)
            {
            case 'A':
                deposito->imprimirWarehouse();
                break;
            case 'B':
                admin->imprimir();
                break;
            default:
                cout <<"Opcion invalida"<<endl;
                break;
            }
        break;
        default:
            exit(0);
            break;
        }
    }
}
FruitType tipoElegido(char option){
switch (option)
    {
    case 'A':
        return FruitType::APPLE;
        break;
    case 'B':
        return FruitType::BANANA;
        break;
    case 'C':
        return FruitType::ORANGE;
        break;
    default:
        cout <<"Opcion invalida"<<endl;
        break;
    }
}
void entrarDeposito(Warehouse *deposito){
    cout<< "Usted esta dentro del deposito, hacia que seccion desea moverse?"<<endl<< "A) Manzanas"<<endl<<"B) Bananas"<<endl<<"C) Naranjas"<<endl;
    char option0;
    cin >> option0;
    cout <<endl;
    FruitType type = tipoElegido(option0);

    cout<< "Se encuentra en la seccion de las "<<fruitTypeToString(type)<<", que quiere hacer?"<<endl<< "A) Ingresar fruta"<<endl<<"B) Retirar fruta"<<endl<<"C) Volver"<<endl;
        char option1;
        cin >> option1;
        cout <<endl;

        switch (option1)
        {
        case 'A':
            cout<<"Ingrese la cantidad de fruta en kg que entra al deposito"<<endl;
            float ingreso;
            cin >> ingreso;
            cout <<endl;
            deposito->agregarFruta(type, ingreso);
            break;
        case 'B':
            cout<<"Esta opcion todavia no esta disponible"<<endl;
            cout <<endl;
            break;
        default:
            break;
        }
}
void entrarCaja(OrderManager *admin){
    cout<<"Usted se encuentra en la caja, que desea hacer?"<<endl<< "A) Ingresar un pedido"<<endl<<"B) Intentar realizar un pedido"<<endl<<"C) Volver"<<endl;
    char option4;
    cin >> option4;
    cout <<endl;

    switch (option4)
    {
    case 'A':
        ingresarPedido(admin);
        break;
    case 'B':
        cout<<"Ingrese la prioridad que quiere tener para realizar el pedido"<<endl<<"A) Minorista"<<endl<<"B) Mayorista"<<endl<<"C) Volver"<<endl;
        char option5;
        cin >> option5;
        cout <<endl;
        
        switch (option5)
        {
        case 'A':
            admin->makeOrder(true);
            break;
        case 'B':
            admin->makeOrder(false);
            break;
        default:
            break;
        }
    break;
    default:
        break;
    }   
}

void ingresarPedido(OrderManager *admin){
    string nombre;
    cout<<"Ingrese la informacion del pedido"<<endl<<"Nombre del cliente: ";
    cin>>nombre;
    cout <<endl;

    Client *cliente = new Client(nombre);

    cout << "Tipo de fruta: A) Manzana B) Banana C) Naranja"<<endl;
    char tipoDeFruta;
    cin >> tipoDeFruta;
    cout <<endl;
    FruitType tipoFruta = tipoElegido(tipoDeFruta);

    cout << "Tipo de pedido: A) Minorista B) Mayorista"<<endl;
    char tipoDePedido;
    cin >> tipoDePedido;
    cout <<endl;

    if(tipoDePedido=='A'){
        cout << "Cantidad de fruta en kg:";
        float kgPedido;
        cin >> kgPedido; 
        cout <<endl;

        RetailOrder *orden = new RetailOrder(kgPedido, *cliente, tipoFruta);
        admin->addRetailOrder(orden);
    }
    else if(tipoDePedido=='B'){
        cout << "Cantidad de cajones:";
        int cajonPedido;
        cin >> cajonPedido;
        cout <<endl;

        WholesaleOrder *order = new WholesaleOrder(cajonPedido, *cliente, tipoFruta);
        admin->addWholesaleOrder(order);
    }
}