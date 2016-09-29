/**
 * @brief Encabezado de clase Fracciones.
 */

#ifndef FRACCIONES_H
#define FRACCIONES_H

#include <iostream>
using namespace std;

/**
 * @brief Aquí se define la clase Fracciones.
 * @param numerador Numerador de la fracción.
 * @param denominador Denominador de la fracción.
 */
class Fracciones {
public:
    Fracciones();
    Fracciones(int numerador, int denominador);
    Fracciones(const Fracciones& orig);
    virtual ~Fracciones();

    int numerador;
    int denominador;

    Fracciones operator+(const Fracciones &ELOTRO);
    Fracciones operator-(const Fracciones &ELOTRO);
    Fracciones operator*(const Fracciones &ELOTRO);
    Fracciones operator/(const Fracciones &ELOTRO);
    virtual void operator~();

};



#endif 
