/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mesa.cpp
 * Author: hgeihsen
 * 
 * Created on October 30, 2016, 7:42 AM
 */

#include "Mesa.h"

Mesa::Mesa() {
    jugadores = 0;
    baraja = 0;
    ronda = 0;
}

Mesa::Mesa(const Mesa& orig) {
}

Mesa::Mesa(char a) {
    this->jugadores = new Pila();
    this->baraja = new Pila();
}

Mesa::~Mesa() {
}

int Mesa::Blackjack() {
    /*while (true) {
        if (ronda == 0) {
            this->barajar();
            for (int i = 0; i < jugadores->tam - 1; i++) {
                jugadores->sumark(i, baraja->pop());
                jugadores->sumark(i, baraja->pop());
            }
        } else {
            while (true) {
                for (int i = 0; i < jugadores->tam - 1; i++) {
                    if (jugadores->recuperar(i) < 19) {
                        jugadores->sumark(i, baraja->pop());
                    } else if (jugadores->recuperar(i) > 21) {
                        jugadores->eliminarK(i);
                    } else if (jugadores->tam == 0) {
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
    }*/
}


void Mesa::agregar_jugador(double e) {
    jugadores->push(e);
}

void Mesa::sacar_jugador() {
    jugadores->pop();
}

void Mesa::barajar() {
    /*srand(time(NULL));
    int j = rand() % baraja->tam - 1;
    for (int i; i < baraja->tam - 1; i++) {
        baraja->sumark(j, baraja->recuperar(i));
    }*/
}
