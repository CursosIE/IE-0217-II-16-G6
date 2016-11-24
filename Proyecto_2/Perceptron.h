/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Perceptron.h
 * Author: ngonzalez456
 *
 * Created on November 19, 2016, 9:53 AM
 */

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include<iostream>
#include<vector>
#include"Punto.h"

using namespace std;

class Perceptron {
public:
    vector<Punto*> puntos;
    vector<double> w;
    Perceptron();
    Perceptron(vector<Punto*> vec);
    Perceptron(const Perceptron& orig);
    virtual ~Perceptron();
    double dotProduct(vector<Punto*> vec, vector<double> w, int order);
    void learn(double n, vector<Punto*> vec0, vector<Punto*> vec1);
private:

};

#endif /* PERCEPTRON_H */

