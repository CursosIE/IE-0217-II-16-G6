/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   admision.h
 * Author: hgeihsen
 *
 * Created on October 31, 2016, 10:49 PM
 */

#ifndef ADMISION_H
#define ADMISION_H

#include <iostream>
#include "ListaConArreglo.h"
#include "Lista.h"
#include "Pila.h"
 
using namespace std;
void imprimir(char* cadena, int tamano);
ListaConArreglo<char> * admision(char ** lista, int tamano);
int size(char ** lista);



#endif /* ADMISION_H */

