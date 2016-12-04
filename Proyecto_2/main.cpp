/* 
 * File:   main.cpp
 * Authors: Fernando Gonzalez & Isaac Gomez
 *
 * Created on November 19, 2016, 9:53 AM
 */

#include <cstdlib>
#include <algorithm>
#include <list>
#include"Perceptron.h"
#include"Punto.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Vector cualquiera
    vector<Punto*> vec0;
    vector<Punto*> vec1;
    
    
    Punto* x0 = new Punto(-2, 1);
    vec1.push_back(x0);
    Punto* x1 = new Punto(1, 1);
    vec1.push_back(x1);
    Punto* x2 = new Punto(2, -2);
    vec0.push_back(x2);
    Punto* x3 = new Punto(-1, -1.5);
    vec0.push_back(x3);
    Punto* x4 = new Punto(-2, -1);
    vec0.push_back(x4);
    Punto* x5 = new Punto(1.5, -0.5);
    vec1.push_back(x5);
    
    Perceptron perceptron = Perceptron();
    
    perceptron.learn(0.2, vec0, vec1);
   
    cout << "Vector de pesos para función cualquiera" << endl;
    for (int i = 0; i < perceptron.w.size(); i++) {
        cout << perceptron.w[i] << endl;        
    }
    
    // Compuerta and
    vector<Punto*> vec0a;
    vector<Punto*> vec1a;
    
    Punto* a0 = new Punto(0, 0);
    vec0a.push_back(a0);
    Punto* a1 = new Punto(0, 1);
    vec0a.push_back(a1);
    Punto* a2 = new Punto(1, 0);
    vec0a.push_back(a2);
    Punto* a3 = new Punto(1, 1);
    vec1a.push_back(a3);
        
    Perceptron perceptron_and = Perceptron();
    
    perceptron_and.learn(0.2, vec0a, vec1a);
   
    cout << "Vector de pesos para compuerta and" << endl;
    for (int i = 0; i < perceptron_and.w.size(); i++) {
        cout << perceptron_and.w[i] << endl;        
    }
    
   
    return 0;
}

