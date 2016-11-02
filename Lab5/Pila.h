#ifndef PILA_H
#define PILA_H
#include <cstdlib>
#include <time.h>    
#include <stdlib.h>
using namespace std;

#include "Lista.h"
#include "ListaConArreglo.h"

//clock_t begin = clock();

template <class T>
class Pila {
public:

    Pila() {

    };

    Pila(int N) {
        this->lista = new ListaConArreglo<T>(N);

    };

    Pila(const Pila& orig) {
    };

    virtual ~Pila() {
    };

    T pop() {
        //cout<<endl<<"pop inicial: ";
        //this->imprimir();
        int pop = this->lista->recuperar(lista->tam - 1);
        this->lista->eliminarK(lista->tam - 1);
        //cout<<endl<<"pop final: ";
        //this->imprimir();
        return pop;
        
    };

    void push(T const &e) {
        lista->agregar(e);
    };

    void imprimir() {
        lista->imprimir();
        cout <<"Tamaño de pila: "<< lista->tam<<endl;
    };

    void aleatorizar() {
        //cout<<clock()<<endl;
        srand(clock());
        for (int i; i < this->lista->tam; i++) {
            int j = rand() % this->lista->tam;
            lista->agregark(j, this->lista->recuperar(i));
        }
    };
    //sumar 

    bool vacio() {
        if (lista->tam == 0) {
            return true;
        } else {
            return false;
        }
    };

private:
    ListaConArreglo<T>* lista = new ListaConArreglo<T>();

};

#endif /* PILA_H */

