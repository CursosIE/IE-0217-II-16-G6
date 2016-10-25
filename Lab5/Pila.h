/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pila.h
 * Author: hgeihsen
 *
 * Created on October 11, 2016, 2:07 PM
 */

#ifndef PILA_H
#define PILA_H

#include "Lista.h"
#include "ListaConArreglo.h"

class Pila : public ListaConArreglo {
public:
    Pila();
    Pila(const Pila& orig);
    virtual ~Pila();

};

#endif /* PILA_H */

