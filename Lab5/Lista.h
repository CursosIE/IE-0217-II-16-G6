#ifndef LISTA_H
#define LISTA_H

class Lista { //lista de doubles
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();

    virtual void agregar(double e) = 0;
    virtual void agregarEnOrdenAscendente(double e) = 0;
    virtual void eliminar(double e) = 0;
    virtual void eliminarK(int k) = 0;

    virtual int buscar(double e) = 0;

    virtual int siguienteK(int k) = 0;
    virtual int anteriorK(int k) = 0;

    virtual double recuperar(int k) = 0;
    virtual void imprimir() = 0;
private:

};

#endif /* LISTA_H */

