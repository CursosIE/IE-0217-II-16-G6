#ifndef POLINOMIOS_H
#define POLINOMIOS_H

#include <string>

using namespace std;

class Polinomios {
public:
    Polinomios();
    Polinomios(int base, double* coeficientes);
    Polinomios(const Polinomios& orig);
    virtual ~Polinomios();

    int base;
    double* coeficientes;

    Polinomios operator+(const Polinomios &ELOTRO);
    Polinomios operator-(const Polinomios &ELOTRO);
    Polinomios operator*(const Polinomios &ELOTRO);
    Polinomios operator /(const Polinomios &ELOTRO);
    void operator~();

private:
    double resultado[];

};

#endif // POLINOMIOS_H
