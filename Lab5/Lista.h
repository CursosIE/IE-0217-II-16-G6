#ifndef LISTA_H
#define LISTA_H
#include <cstdlib>
#include <time.h>    
#include <stdlib.h>
using namespace std;


template <class T>
class Lista { //lista de doubles
public:
    Lista(){};
    Lista(const Lista& orig){};
    virtual ~Lista(){};

    virtual void agregar(T const& e) = 0;
    virtual void eliminar(T const& e) = 0;

    virtual void eliminarK(int k) = 0;

    virtual int buscar(T const& e) = 0;

    virtual T siguienteK(int k) = 0;
    virtual T anteriorK(int k) = 0;

    virtual T recuperar(int k) = 0;
    virtual void imprimir() = 0;
private:

};

#endif /* LISTA_H */

