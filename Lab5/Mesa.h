
#ifndef MESA_H
#define MESA_H
#include "ListaConArreglo.h"
#include "Lista.h"
#include "Pila.h"
#include "admision.h"

class Mesa {
public:
    Mesa();
    Mesa(/*ListaConArreglo* admision,*/ int N);
    Mesa(const Mesa& orig);    
    virtual ~Mesa();
    
    void Blackjack(ListaConArreglo<char>* admision);
    void agregar_jugador(ListaConArreglo<char>* admision);
    void sacar_jugador(int i);
    void barajar();
    bool lleno();
    void llenar(ListaConArreglo<char>* Admision);
    void vaciar();
    // repartir();
    
    ListaConArreglo<char>*jugadores;
    ListaConArreglo<int>* puntajes;
    int ronda;
private:
    Pila<int>* baraja;
    
};

#endif /* MESA_H */

