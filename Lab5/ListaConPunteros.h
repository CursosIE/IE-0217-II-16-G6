/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConPunteros.h
 * Author: hgeihsen
 *
 * Created on October 4, 2016, 3:00 PM
 */

#ifndef LISTACONPUNTEROS_H
#define LISTACONPUNTEROS_H

class ListaConPunteros: public Lista {
public:
    ListaConPunteros();
    ListaConPunteros(int tamanho, Zelda* cabeza, Zelda* cola);
    ListaConPunteros(const ListaConPunteros& orig);
    virtual ~ListaConPunteros();
    
    int tamanho;
    Zelda* cabeza;
    Zelda* cola;
    
     void agregar(double e);
    void agregarEnOrdenAscendente(double e);
    void eliminar(double e);
    void eliminarK(int k);

    int buscar(double e);

    int siguienteK(int k);
    int anteriorK(int k);

    double recuperar(int k);

    void imprimir();
    
private:

};

#endif /* LISTACONPUNTEROS_H */

