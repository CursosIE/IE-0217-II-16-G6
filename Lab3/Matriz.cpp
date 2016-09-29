#include "Matriz.h"

/**
 * @brief Constructor vacio de clase Matriz.
 */
Matriz::Matriz() {

}

/**
 * @brief Constructor sobrecargado de la clase Matriz.
 *
 * @param nombre Nombre de la figura.
 * @param color Color de la figura.
 */
Matriz::Matriz(int columnas, int filas, double** arreglo) {
    this->columnas = columnas;
    this->filas = filas;
    this->arreglo = arreglo;
}

/**
 * @brief Constructor de la clase Matriz.
 *
 * @param Matriz& Constante objeto.
 */
Matriz::Matriz(const Matriz& orig) {
}

/**
 * @brief Destructor de la clase Matriz.
 */
Matriz::~Matriz() {


}

/**
 * @brief Sobrecarga el operador + para sumar dos objetos tipo Matriz.
 */
Matriz Matriz::operator+(const Matriz &ELOTRO) {
    Matriz c;
    c.filas = this->filas;
    c.columnas = this->columnas;

    double** array;
    array = new double*[this->filas];
    for (int i = 0; i < this->filas; ++i) {
        array[i] = new double[this->columnas];
    }

    if (this->filas != ELOTRO.filas || this->columnas != ELOTRO.columnas) {
        cout << "Tamaño incorrecto de la matriz. Debe introducir una matriz cuadrada\n";
        for (int i = 0; i < this->filas; i++) {
            for (int j = 0; j < this->columnas; j++) {
                array[i][j] = 0;
            }
        }
        c.arreglo = array;
        return c;

    } else {


        for (int i = 0; i < this->filas; i++) {
            for (int j = 0; j < this->columnas; j++) {
                array[i][j] = this->arreglo[i][j] + ELOTRO.arreglo[i][j];
            }
        }
        c.arreglo = array;
        return c;

    }
    for (int i = 0; i < this->filas; ++i) {
        delete [] array[i];
    }
    delete [] array;

}

/**
 * @brief Sobrecarga el operador - para restar dos objetos tipo Matriz.
 */
Matriz Matriz::operator-(const Matriz &ELOTRO) {
    Matriz c;
    c.filas = this->filas;
    c.columnas = this->columnas;

    double** array;
    array = new double*[this->filas];
    for (int i = 0; i < this->filas; ++i) {
        array[i] = new double[this->columnas];
    }

    if (this->filas != ELOTRO.filas || this->columnas != ELOTRO.columnas) {
        cout << "Tamaño incorrecto de la matriz. Debe introducir una matriz cuadrada\n";
        for (int i = 0; i < this->filas; i++) {
            for (int j = 0; j < this->columnas; j++) {
                array[i][j] = 0;
            }
        }
        c.arreglo = array;
        return c;
    } else {

        for (int i = 0; i < this->filas; i++) {
            for (int j = 0; j < this->columnas; j++) {
                array[i][j] = this->arreglo[i][j] - ELOTRO.arreglo[i][j];
            }
        }
        c.arreglo = array;

        return c;
    }

    for (int i = 0; i < this->filas; ++i) {
        delete [] array[i];
    }
    delete [] array;
}

/**
 * @brief Sobrecarga el operador * para sumar dos objetos tipo Matriz.
 */
Matriz Matriz::operator*(const Matriz &ELOTRO) {
    Matriz c;
    c.filas = this->filas;
    c.columnas = this->columnas;

    double** array;
    array = new double*[this->filas];
    for (int i = 0; i < this->filas; ++i) {
        array[i] = new double[this->columnas];
    }

    if (this->columnas != ELOTRO.filas) {
        cout << "Tamaño incorrecto de matriz" << endl;
        for (int i = 0; i < this->filas; i++) {
            for (int j = 0; j < this->columnas; j++) {
                array[i][j] = 0;
            }
        }
        c.arreglo = array;
        return c;

    } else {


        for (int i = 0; i < this->filas; i++) {
            for (int j = 0; j < ELOTRO.columnas; j++) {
                for (int k = 0; k <this->columnas; k++)
                    array[i][j] += this->arreglo[i][k] * ELOTRO.arreglo[k][j];
            }
        }
        c.arreglo = array;

        return c;
    }

    for (int i = 0; i < this->filas; ++i) {
        delete [] array[i];
    }
    delete [] array;
}

/**
 * @brief Sobrecarga el operador / para dividir dos objetos tipo Matriz.
 */
Matriz Matriz::operator/(const Matriz &ELOTRO) {
    Matriz c;
    c.filas = this->filas;
    c.columnas = this->columnas;

    double** array;
    array = new double*[this->filas];
    for (int i = 0; i < this->filas; ++i) {
        array[i] = new double[this->columnas];
    }

    if (this->filas != ELOTRO.filas || this->columnas != ELOTRO.columnas) {
        cout << "Tamaño incorrecto de la matriz. Debe introducir una matriz cuadrada\n";
        for (int i = 0; i < this->filas; i++) {
            for (int j = 0; j < this->columnas; j++) {
                array[i][j] = 0;
            }
        }
        c.arreglo = array;
        return c;
    } else {
        for (int i = 0; i <this->filas; i++) {
            for (int j = 0; j < this->columnas; j++) {
                array[i][j] = this->arreglo[i][j] / ELOTRO.arreglo[i][j];
            }
        }
        c.arreglo = array;

        return c;
    }
    for (int i = 0; i < this->filas; ++i) {
        delete [] array[i];
    }
    delete [] array;
}

/**
 * @brief Sobrecarga el operador ~ para imprimir los atributos de la clase.
 */
void Matriz::operator~() {
    for (int i = 0; i < this->filas; i++) {
        cout << "\n";
        for (int j = 0; j < this->columnas; j++) {
            cout << this->arreglo[i][j] << "  ";
        }
    }
    cout << "\n\n";
}

