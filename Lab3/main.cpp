/**
 * @file main.cpp
 * @author Jose Fernando Gonzalez Salas & Isaac Gomez Sanchez
 * @date 20 de setiembre, 2016
 * @brief En este programa se hace uso de los templates para hacer una calculadora con los métodos suma, resta, división, multiplicación e impresión de diferentes objetos. 
 * En este caso dichos objetos del tipo Matriz, Fracciones y Polinomio.
 */


#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

#include "Fraccion.h"
#include "Matriz.h"
#include "Polinomios.h"
#include "Calculadora.h"

using namespace std;

int main(int argc, char** argv) {
    
    //Parte de Polinomios
    Calculadora<Polinomios> pol;
    
    double a[] = {1, 2, 3};
    Polinomios p1(3, a);

    cout << "El polinomio 1 es: " << endl;
    ~p1;
    
    double b[] = {4, 5, 6};
    Polinomios p2(3, b);

    cout << "El polinomio 2 es: " << endl;
    ~p2;

    Polinomios p3;  
    p3=pol.add(p1, p2);
    
    cout << "La suma de los polinomios es: " << endl;
    pol.print(p3);

    p3=pol.sub(p1, p2);
    
    cout << "La resta de los polinomios es: "<< endl;
    pol.print(p3);

    p3=pol.mul(p1, p2);
    
    cout << "La multiplicacion de los polinomios es: " << endl;
    pol.print(p3);

    p3=pol.div(p1, p2);
    
    cout << "La division de los polinomios es: " << endl;
    pol.print(p3);
        

    //Parte de Matrices
    int i, j;
    
    Matriz ma;
    ma.filas = 5;
    ma.columnas = 5;
    double** array;
    array = new double*[ma.filas];
    for (i = 0; i < ma.filas; ++i) {
        array[i] = new double[ma.columnas];
    }

    for (i = 0; i < ma.filas; i++) {
        for (j = 0; j < ma.columnas; j++) {
            array[i][j] = 3;
        }
    }
    ma.arreglo = array;

    Matriz mb;
    mb.filas = 5;
    mb.columnas = 5;
    double** array2;
    array2 = new double*[ma.filas];
    for (i = 0; i < ma.filas; ++i) {
        array2[i] = new double[ma.columnas];
    }
    for (i = 0; i < mb.filas; i++) {
        for (j = 0; j < mb.columnas; j++) {
            array2[i][j] = 2;
        }
    }
    mb.arreglo = array2;


    Calculadora <Matriz> mt;
    Matriz m1;
    
    

    m1= mt.add(ma,mb); 
    mt.print(m1);
    
    m1= mt.sub(ma,mb); 
    mt.print(m1);
    
    
    m1= mt.mul(ma,mb); 
    mt.print(m1);
    
    m1= mt.div(ma,mb); 
    mt.print(m1);

    for (i = 0; i < ma.filas; ++i) {
        delete [] array[i];
    }
    delete [] array;

    for (i = 0; i < mb.filas; ++i) {
        delete [] array2[i];
    }
    delete [] array2;

    //Parte de fracciones
    Calculadora<Fracciones> fr;

    Fracciones fa;
    fa.numerador = 3;
    fa.denominador = 4;

    Fracciones fb;
    fb.numerador = 2;
    fb.denominador = 4;

    Fracciones f;

    f = fr.add(fa, fb);
    fr.print(f);

    f = fr.sub(fa, fb);
    fr.print(f);

    f = fr.mul(fa, fb);
    fr.print(f);

    f = fr.div(fa, fb);
    fr.print(f);


    return 0;
}
