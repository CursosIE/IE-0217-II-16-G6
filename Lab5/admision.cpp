#include "admision.h"

using namespace std;

/**
 * @brief Imprime una cadena de caracteres dada por el usuario.
 *
 * @param cadena Arreglo del usuario a imprimir.
 * @param tamano Dimension del arreglo.
 */
void imprimir(char* cadena, int tamano) {
    cout << "|";
    for (int i = 0; i < tamano; i++) {
        cout << cadena[i];
    }
    cout << "|\n";
}

/**
 * @brief Funcion general en donde suceden los procesos de admision al juego. El metodo toma im arreglo y lo recorre, separando en tres arreglos distintos cada letra que encuentra en su camino. Luego incluye con un ratio especifico todos los datos de los arreglos y los coloca en un arreglo auxiliar. El proceso concluye con el recorrido de esta fila final, agregando cada dato no vacio a un objeto del tipo Lista.
 *
 * @param lista Arreglo del usuario a imprimir.
 * @param tamano Dimension del arreglo.
 */
ListaConArreglo<char> * admision(char ** lista, int tamano) {

    char * e = new char;

    char * t = new char;

    char * d = new char;

    char * linea = new char;

    int contE = 0;

    int contT = 0;

    int contD = 0;

    for (int i = 0; i < tamano; i++) {

        if (lista[1][i] == 'E') {
            e[contE] = lista[1][i];
            contE++;
        }
        else if (lista[1][i] == 'T') {
            t[contT] = lista[1][i];
            contT++;
        }
        else if (lista[1][i] == 'D') {
            d[contD] = lista[1][i];
            contD++;
        }
        else {
        }

    }

    int pos = 0;

    int n = 0;

    int r = 0;

    bool parar = true;

    while (parar) {

        if (e[r] == '\0' && t[r] == '\0' && d[r] == '\0') {
            parar = false;
        }
        else {

            for (int i = 0; i < tamano; i++) {
                if (i == 0) {
                    linea[0 + n] = e[0 + r];
                    pos++;
                }
                else if (i == 1 + n) {
                    linea[1 + n] = e[1 + r];
                    pos++;
                }
                else if (i == 3 + n) {
                    linea[3 + n] = e[2 + r];
                    pos++;
                }
                else if (i == 4) {
                    linea[4 + n] = e[4 + r];
                    pos++;
                }
            }

            for (int i = 0; i < tamano; i++) {
                if (i == 2 + n) {
                    linea[2 + n] = t[0 + r];
                    pos++;
                }
                else if (i == 5 + n) {
                    linea[5 + n] = t[1 + r];
                    pos++;
                }

            }

            for (int i = 0; i < tamano; i++) {
                if (i == 6 + n) {
                    linea[6 + n] = d[0 + r];
                    pos++;
                } else {
                    linea[i] = linea[i];
                }
            }
        }
        n = n + 7;
        r = r + 1;
    }

    imprimir(linea, tamano);
    delete [] e;
    delete [] t;
    delete [] d;

    ListaConArreglo<char>* L = new ListaConArreglo<char>();

    for (int z = tamano; z >= 0; z--) {

        if (linea[z] != '\0') {
            L->agregar(linea[z]);
        }
    }

    L->imprimir();
    return L;
}

/**
 * @brief Retorna el tamano de un arreglo.
 *
 * @param lista Arreglo del usuario a imprimir.
 */
int size(char ** lista) {
    bool parar = true;
    int size = 0;
    int i = 0;
    while (parar) {
        if (lista[1][i] != '\0') {
            size++;
            i++;
        } else {
            parar = false;
        }
    }
    return size;
}
/*int main(int argc, char** argv) {
    admision(argv, 7);
}*/

