/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punto.h
 * Author: ngonzalez456
 *
 * Created on November 19, 2016, 9:55 AM
 */

#ifndef PUNTO_H
#define PUNTO_H

#include<vector>

using namespace std;

class Punto {
public:
    vector<double> pos;
    Punto();
    Punto(double x, double y);
    Punto(const Punto& orig);
    virtual ~Punto();
private:

};

#endif /* PUNTO_H */

