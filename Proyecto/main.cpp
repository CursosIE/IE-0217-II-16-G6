/**
 * @file main.cpp
 * @author Jose Fernando Gonzalez Salas, Isaac Gomez Sanchez & Alonso Rojas Fernandez.
 * @date 20 de setiembre, 2016
 * @brief En este programa se utiliza el algoritmo BLAST para comparacion de secuencias en su version mas simple, comparando con una base de datos creada por el usuario con el proposito de observar su comportamiento de algoritmo y sus resultados.
 * En este caso dichos objetos son del tipo blastobject.
 */

#include "blastobject.h"
#include "getmatrix.h"
#include <time.h>

using namespace std;

int main(int argc, char** argv) {
	
    clock_t t = clock();    
	
    blastobject b;

    b.repeater(argv, 3);
  
    cout << "Tiempo de ejecucion: " << ((float)clock() - t)/CLOCKS_PER_SEC << " segundos." << endl;

    return 0;

}
