/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punto.cpp
 * Authors: Fernando Gonzalez & Isaac Gomez
 * 
 * Created on November 19, 2016, 9:55 AM
 */

#include "Punto.h"

/**
 * @brief Constructor de clase Punto.
 *
 */
Punto::Punto() {
    this->pos.clear();
}

/**
 * @brief Constructor sobrecargado de clase Punto.
 *
 * @param x Valor de posicion en eje X
 * @param y Valor de posicion en eje Y
 */
Punto::Punto(double x, double y){
    this->pos.push_back(1);
    this->pos.push_back(x);
    this->pos.push_back(y);
}

/**
 * @brief Constructor sobrecargado de clase Punto.
 *
 * @param Punto& Objeto del tipo Punto
 */
Punto::Punto(const Punto& orig) {
}

/**
 * @brief Destructor de clase Punto.
 *
 */
Punto::~Punto() {
}

