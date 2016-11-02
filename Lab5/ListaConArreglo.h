

#ifndef LISTACONARREGLO_H
#define LISTACONARREGLO_H
#include <iostream>
#include "Lista.h"

template <class T>
class ListaConArreglo : public Lista<T> {
public:

    ListaConArreglo() {
    };

    ListaConArreglo(int N) {
        this->data = new T[N];
        tam = N;
        ultimo = tam - 1;
    };

    ListaConArreglo(const ListaConArreglo& orig) {
    };

    ~ListaConArreglo() {
    };

    void agregar(const T &e) {
        if (data == 0) {
            data = new T[1];
            tam = 1;
            ultimo = 0;
            data[0] = e;
            //std::cout << "agregar:if(data == 0)" << std::endl;
        } else {
            if (ultimo == tam - 1) {
                T* temp = new T[tam * 2];
                for (int i = 0; i < tam; i++) {
                    temp[i] = data[i];
                }
                ultimo++;
                tam++;
                temp[ultimo] = e;
                delete data; // ojo con lss deletes
                //std::cout << "agregar:else: if(ultimo == tam -1)" << std::endl;
                data = temp;
            } else {
                ultimo++;
                tam++;
                data[ultimo] = e;
                //std::cout << "agregar:else: else" << std::endl;
            }
        }
    };

    void sumark(int k, const T &e) {
        T* temp = new T[tam * 2];
        for (int i = 0; i < tam; i++) {
            temp[i] = data[i];
        }
        //ultimo++;
        //tam++;
        temp[k] += e;
        delete data; // ojo con lss deletes
        //cout << "sumark" << endl;
        data = temp;
    };

    void agregark(int k, const T &e) {
        T* temp = new T[tam * 2];
        for (int i = 0; i < tam; i++) {
            temp[i] = data[i];
        }
        //ultimo++;
        //tam++;
        temp[k] = e;
        delete data; // ojo con lss deletes
        //cout << "agregark" << endl;
        data = temp;
    };

    void eliminar(const T &e) {
        int k = buscar(e);
        eliminarK(k);
    };

    void eliminarK(int k) {
        for (int i = k; i < tam - 1; i++) {
            data[i] = data[i + 1];
        }
        tam--;
        ultimo--;
    };

    int buscar(const T &e) {
        for (int i = 0; i < tam; i++) {
            if (data[i] == e) {
                return i;
            }

        }
        return -1;
    };

    T siguienteK(int k) {
        if (k + 1 < tam) {
            return data[k + 1];
        } else {
            return 0;
        }
    };

    T anteriorK(int k) {
        if (k - 1 >= 0) {
            return data[k - 1];
        } else {
            return 0;
        }
    };

    T recuperar(int k) {
        return data[k];
    };

    void imprimir() {
        for (int i = 0; i < tam; i++) {
            std::cout << data[i] << "\t";
        }
        std::cout << std::endl;
    };

    bool vacio() {
        if (this->tam == 0) {
            return true;
        } else {
            return false;
        }
    }

    int tam = 0;
private:

    int ultimo = -1;
    T* data; //almacenar los elementos


};


#endif /* LISTACONARREGLO_H */

