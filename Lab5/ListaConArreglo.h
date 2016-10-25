
#ifndef LISTACONARREGLO_H
#define LISTACONARREGLO_H
#include <iostream>
#include "Lista.h"

class ListaConArreglo : public Lista {
public:
    ListaConArreglo();
    ListaConArreglo(int N);
    ListaConArreglo(const ListaConArreglo& orig);
    ~ListaConArreglo();


    void agregar(double e);
    void agregarEnOrdenAscendente(double e);
    void eliminar(double e);
    void eliminarK(int k);
    

    int buscar(double e);

    int siguienteK(int k);
    int anteriorK(int k);

    double recuperar(int k);

    void imprimir();
    
    int tam;
private:
    
    int ultimo;
    double* data; //almacenar los elementos
};

#endif /* LISTACONARREGLO_H */

