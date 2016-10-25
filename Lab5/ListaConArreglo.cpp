#include "ListaConArreglo.h"

ListaConArreglo::ListaConArreglo() {
    data = 0;
    tam = 0;
    ultimo = -1;
}

ListaConArreglo::ListaConArreglo(const ListaConArreglo& orig) {
}

ListaConArreglo::~ListaConArreglo() {
}
//////////////////////////////////

ListaConArreglo::ListaConArreglo(int N) {
    this->data = new double[N];
    tam = N;
    ultimo = tam - 1;
}

void ListaConArreglo::agregar(double e) {
    if (data == 0) {
        data = new double[1];
        tam = 1;
        ultimo = 0;
        data[0] = e;
    } else {
        if (ultimo == tam - 1) {
            double* temp = new double[tam * 2];
            for (int i = 0; i < tam; i++) {
                temp[i] = data[i];
            }
            ultimo++;
            tam++;
            temp[ultimo] = e;
            delete data; // ojo con lss deletes
            data = temp;
        } else {
            ultimo++;
            tam++;
            data[ultimo] = e;
        }
    }
}

void ListaConArreglo::eliminar(double e) {
    int k = buscar(e);
    eliminarK(k);
}

void ListaConArreglo::eliminarK(int k) {
    for (int i = k; i < tam - 1; i++) {
        data[i] = data[i + 1];
    }
    tam--;
    ultimo--;
}

int ListaConArreglo::buscar(double e) {
    for (int i = 0; i < tam; i++) {
        if (data[i] == e) {
            return i;
        }

    }
    return -1;
}

int ListaConArreglo::siguienteK(int k) {
    if (k + 1 < tam) {
        return data[k + 1];
    } else {
        return -1;
    }
}

int ListaConArreglo::anteriorK(int k) {
    if (k - 1 >= 0) {
        return data[k - 1];
    } else {
        return -1;
    }

}

double ListaConArreglo::recuperar(int k) {
    return data[k];
}

void ListaConArreglo::imprimir() {
    for (int i = 0; i < tam; i++) {
        std::cout << data[i] << "\t";
    }
    std::cout << std::endl;
}

void ListaConArreglo::agregarEnOrdenAscendente(double e) {
}