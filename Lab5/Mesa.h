/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mesa.h
 * Author: hgeihsen
 *
 * Created on October 30, 2016, 7:42 AM
 */

#ifndef MESA_H
#define MESA_H

#include "Pila.h"

class Mesa {
public:
    Mesa();
    Mesa(const Mesa& orig);
    Mesa(char participante);
    virtual ~Mesa();
    
    int Blackjack();
    void agregar_jugador(double e);
    void sacar_jugador();
    void barajar();
    // repartir();
    
    
    Pila* jugadores;
    int ronda;
private:
    Pila* baraja;
    
};

#endif /* MESA_H */

