/**
 * @brief Encabezado de clase Matriz.
 */

#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
using namespace std;

/**
 * @brief Aquí se define la clase Matriz.
 * @param columnas Columnas de la matriz.
 * @param filas Filas de la Matriz.
 */
class Matriz{
public:
    Matriz();
    Matriz(int columnas, int filas, double**arreglo);
    Matriz(const Matriz& orig);
    virtual ~Matriz();
    
   
   
    Matriz operator+(const Matriz &ELOTRO);
    Matriz operator-(const Matriz &ELOTRO);
    Matriz operator*(const Matriz &ELOTRO);
    Matriz operator/(const Matriz &ELOTRO);
    virtual void operator~();
    
    int columnas;
    int filas;
    double** arreglo;

  
};
#endif

