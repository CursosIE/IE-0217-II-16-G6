#include <cstdlib>
#include "ListaConArreglo.h"
#include "Pila.h"
using namespace std;

int main(int argc, char** argv) {

    Pila * p= new Pila();
    
    for (int i=0; i<argc; i++){
        if (argv[1][i]== '(') {
            p->agregar(5.5);
        }
        else if (argv[1][i] == ')') {
            p->eliminarK(i);
        }
        else {
            cout << "No es un parentesis" << endl;
        }
    }
    
    if (p->tam == 0){
        cout << "Todo bien" << endl;
    }
    else {
        cout << "Error" << endl;
    }
    
    return 0;
}

