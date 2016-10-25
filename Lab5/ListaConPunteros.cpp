#include "ListaConPunteros.h"
#include "Zelda.h"

ListaConPunteros::ListaConPunteros() {
}

ListaConPunteros::ListaConPunteros(Zelda* cabeza, Zelda* cola) {
    this->cabeza=cabeza;
    this->tamanho=0;
    this->cola=cola;
}

ListaConPunteros::ListaConPunteros(const ListaConPunteros& orig) {
}

ListaConPunteros::~ListaConPunteros() {
}

void ListaConPunteros::agregar(double e) {
    if (dato == 0) {
        dato = new double[1];
        tamanho = 1;
        cola = 0;
        dato[0] = e;
    } else {
        if (cola == tamanho - 1) {
            double* temp = new double[tamanho * 2];
            for (int i = 0; i < tamanho; i++) {
                temp[i] = dato[i];
            }
            cola++;
            tamanho++;
            temp[cola] = e;
            delete dato; // ojo con lss deletes
            dato = temp;
        } else {
            cola++;
            tamanho++;
            dato[cola] = e;
        }
    }
}

void ListaConPunteros::eliminar(double e) {
    int k = buscar(e);
    eliminarK(k);
}

void ListaConPunteros::eliminarK(int k) {
    for (int i = k; i < tamanho - 1; i++) {
        dato[i] = dato[i + 1];
    }
    tamanho--;
    cola--;
}

int ListaConPunteros::buscar(double e) {
    for (int i = 0; i < tamanho; i++) {
        if (dato[i] == e) {
            return i;
        }

    }
    return -1;
}

int ListaConPunteros::siguienteK(int k) {
    if (k + 1 < tamanho) {
        return dato[k + 1];
    } else {
        return -1;
    }
}

int ListaConPunteros::anteriorK(int k) {
    if (k - 1 >= 0) {
        return dato[k - 1];
    } else {
        return -1;
    }

}

double ListaConPunteros::recuperar(int k) {
    return dato[k];
}

void ListaConPunteros::imprimir() {
    for (int i = 0; i < tamanho; i++) {
        std::cout << dato[i] << "\t";
    }
    std::cout << std::endl;
}

void ListaConPunteros::agregarEnOrdenAscendente(double e) {
}

