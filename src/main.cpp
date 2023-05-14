#include <iostream>
#include "./stock/Warehouse.cpp"
#include "stock\OrderManager.cpp"
#include "./utils/enum.hpp"


using namespace std;
int main( int argc, char *argv[])
{

    Warehouse *deposito = new Warehouse();
    OrderManager *admin = new OrderManager(*deposito);
    string nombre;

    cout << "¡Bienvenido a la verdulería de Vicente!" << endl;
    while (true)
    {
        cout << "A donde te quieres dirigir?"<< endl<< "A) Deposito"<<endl<<"B) Caja"<<endl<<"C) Impresiones"<<endl;
        char option;
        cin >> option;
    
        switch (option)
        {

        case 'A':
            cout<< "Usted esta dentro del deposito, hacia que seccion desea moverse?"<<endl<< "A) Manzanas"<<endl<<"B) Bananas"<<endl<<"C) Naranjas"<<endl;
            char option0;
            cin >> option0;
            FruitType type;

            switch (option0)
            {
            case 'A':
                type=FruitType::APPLE;
                cout<< "Se encuentra en la seccion de las "<<fruitTypeToString(type)<<", que quiere hacer?"<<endl<< "A) Ingresar fruta"<<endl<<"B) Retirar fruta"<<endl<<"C) Volver"<<endl;
                char option1;
                cin >> option1;
                switch (option1)
                {
                case 'A':
                    cout<<"Ingrese la cantidad de fruta en kg que entra al deposito"<<endl;
                    float ingreso;
                    cin >> ingreso;
                    deposito->agregarFruta(type, ingreso);
                    break;
                case 'B':
                    cout<<"Esta opcion todavia no esta disponible"<<endl;
                    break;
                case 'C':
                    break;
                default:
                    cout <<"Opcion invalida"<<endl;
                    break;
                }
            break;
            case 'B':
                type=FruitType::BANANA;
                cout<< "Se encuentra en la seccion de las "<<fruitTypeToString(type)<<", que quiere hacer?"<<endl<< "A) Ingresar fruta"<<endl<<"B) Retirar fruta"<<endl<<"C) Volver"<<endl;
                char option2;
                cin >> option2;
                switch (option2)
                {
                case 'A':
                    cout<<"Ingrese la cantidad de fruta en kg que entra al deposito"<<endl;
                    float ingreso1;
                    cin >> ingreso1;
                    deposito->agregarFruta(type, ingreso1);
                    break;
                case 'B':
                    cout<<"Esta opcion todavia no esta disponible"<<endl;
                    break;
                case 'C':
                    break;
                default:
                    cout <<"Opcion invalida"<<endl;
                    break;
                }
            break;
            case 'C':
                type=FruitType::ORANGE;
                cout<< "Se encuentra en la seccion de las "<<fruitTypeToString(type)<<", que quiere hacer?"<<endl<< "A) Ingresar fruta"<<endl<<"B) Retirar fruta"<<endl<<"C) Volver"<<endl;
                char option3;
                cin >> option3;
                switch (option3)
                {
                case 'A':
                    cout<<"Ingrese la cantidad de fruta en kg que entra al deposito"<<endl;
                    float ingreso2;
                    cin >> ingreso2;
                    deposito->agregarFruta(type, ingreso2);
                    break;
                case 'B':
                    cout<<"Esta opcion todavia no esta disponible"<<endl;
                    break;
                case 'C':
                    break;
                default:
                    cout <<"Opcion invalida"<<endl;
                    break;
                }
            break;
            default:
                cout <<"Opcion invalida"<<endl;
                break;
            }
        break;

        // case 'B':
        //     cout<<"Usted se encuentra en la caja, que desea hacer?"<<endl<< "A) Ingresar un pedido"<<endl<<"B) Intentar realizar un pedido"<<endl<<"C) Volver"<<endl;
        //     char option4;
        //     cin >> option4;
        //     switch (option4)
        //     {
        //     case 'A':
        //         cout<<"Ingrese la informacion del pedido"<<endl<<"Nombre del cliente: ";
        //         cin>>nombre;
        //         Client *cliente = new Client(nombre);
                
        //         cout << "Tipo de pedido: A) Minorista B) Mayorista"<<endl;
        //         char tipoDePedido;
        //         cin >> tipoDePedido;
        //         switch (tipoDePedido)
        //         {
        //         case 'A':
        //             cout << "Cantidad de fruta en kg:";
        //             float kgPedido;
        //             cin >> kgPedido;
        //             cout << "Tipo de fruta: A) Manzana B) Banana C) Naranja";
        //             char tipoDeFruta;
        //             cin >> tipoDeFruta;
        //             switch (tipoDeFruta)
        //             {
        //             case 'A':
        //                 RetailOrder *orden = new RetailOrder(kgPedido, *cliente, FruitType::APPLE);
        //                 admin->addRetailOrder(orden);
        //                 break;
        //             case 'B':
        //                 RetailOrder *orden1 = new RetailOrder(kgPedido, *cliente, FruitType::BANANA);
        //                 admin->addRetailOrder(orden1);
        //                 break;
        //             case 'C':
        //                 RetailOrder *orden2 = new RetailOrder(kgPedido, *cliente, FruitType::ORANGE);
        //                 admin->addRetailOrder(orden2);
        //                 break;  
        //             default:
        //                 cout <<"Opcion invalida"<<endl;
        //                 break;
        //             }
        //         break;
        //         case 'B':
        //             cout << "Cantidad de cajones:";
        //             int cajonPedido;
        //             cin >> cajonPedido;
        //             cout << "Tipo de fruta: A) Manzana B) Banana C) Naranja";
        //             char tipoDeFruta1;
        //             cin >> tipoDeFruta1;
        //             switch (tipoDeFruta1)
        //             {
        //             case 'A':
        //                 WholesaleOrder *order = new WholesaleOrder(cajonPedido, *cliente, FruitType::APPLE);
        //                 admin->addWholesaleOrder(order);
        //                 break;
        //             case 'B':
        //                 WholesaleOrder *order1 = new WholesaleOrder(cajonPedido, *cliente, FruitType::APPLE);
        //                 admin->addWholesaleOrder(order1);
        //                 break;
        //             case 'C':
        //                 WholesaleOrder *order2 = new WholesaleOrder(cajonPedido, *cliente, FruitType::APPLE);
        //                 admin->addWholesaleOrder(order2);
        //                 break;  
        //             default:
        //                 cout <<"Opcion invalida"<<endl;
        //                 break;
        //             }
        //         break;
        //         default:
        //             cout <<"Opcion invalida"<<endl;
        //             break;
        //         }
        //     break;
        //     case 'B':
        //         cout<<"Ingrese la prioridad que quiere tener para realizar el pedido"<<endl<<"A) Minorista"<<endl<<"B) Mayorista"<<endl<<"C) Volver"<<endl;
        //         char option5;
        //         cin >> option5;
        //         switch (option5)
        //         {
        //         case 'A':
        //             admin->makeOrder(true);
        //            break;
        //         case 'B':
        //             admin->makeOrder(false);
        //             break;
        //         case 'C':
        //             break;
        //         default:
        //             cout <<"Opcion invalida"<<endl;
        //             break;
        //         }
        //         break;
        //     case 'C':
        //         break;
        //     default:
        //         cout <<"Opcion invalida"<<endl;
        //         break;
        //     }
        // break;
        case 'C':
            cout<<"Que desea imprimir?" << endl << "A) Estado del Deposito"<<endl<<"B) Estado de las ordenes"<<endl;
            char option6;
            cin >> option6;
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