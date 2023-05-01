// Representa el gestor pedidos para consultar y entregar los pedidos pendientes.
#include <iostream>
#include "../orders/WholesaleOrder.cpp"
#include "../orders/RetailOrder.cpp"
#include "../model/Client.cpp"
#include "../utils/enum.hpp"
#include "../structure/Queue.cpp"

class OrderManager{

    private:
        Queue<RetailOrder> *RetailQueue = new Queue<RetailOrder>();
        Queue<WholesaleOrder> *WholesaleQueue = new Queue<WholesaleOrder>();
    public:

        //Constructor y destructor
        OrderManager();
        ~OrderManager();

        //Agrega a la cola una orden minorista o mayorista
        void addRetailOrder(RetailOrder ro){RetailQueue->encolar(ro);}
        void addWholesaleOrder(WholesaleOrder wo){WholesaleQueue->encolar(wo);}
        //Borra de la cola una orden
        void removeRetailOrder(){RetailQueue->desencolar();}
        void removelesaleOrder(){WholesaleQueue->desencolar();}




};