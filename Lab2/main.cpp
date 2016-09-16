/**
 * @file main.cpp
 * @author Jose Fernando Gonzalez Salas & Isaac Gomez Sanchez
 * @date 12 de setiembre, 2016
 * @brief Este programa realiza el calculo del area y el perimetro con los parametros establecidos de cada figura geometrica. Cada una de estas figuras posee sus caracteristicas propias de color y nombre.
 */

#include "Figuras.h"
int main(int argc, char** argv) {
	
	
	
    Figuras p;
    p.nombre = "Figura\n";
    p.color = "¡¡Neeeeegroooo!! \\m/_ (*0*) _\\m/  ";
	p.calcularArea();
 	p.calcularPerimetro(); 	
 	~p;
        !p;

	Cuadrado  q;
	q.nombre = "Cuadrado";
	q.color = "Blanco";
	q.lado = 3;
	q.calcularArea(3);
	q.calcularPerimetro(3);
        ~q;
        !q;
	
	Triangulo r;
	r.nombre = "Triangulo";
	r.color = "Azul";
	r.base = 3;
	r.altura = 3;
	r.hipotenusa = 3;
	r.calcularArea(3,3);
	r.calcularPerimetro(3,3,3);
	~r;
        !r;
	
	Circulo s;
	s.nombre = "Circulo";
	s.color = "Rojo";
	s.radio = 3;
	s.calcularArea(3);
	s.calcularPerimetro(3);   
	~s;
        !s;
	    
    return 0;
}
