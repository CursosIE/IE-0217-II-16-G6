#ifndef FIGURAS_H
#define FIGURAS_H

#include <cstdlib>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

// Clase base
class Figuras
{
    public:
        Figuras();
        Figuras(string nombre, string color);
        Figuras(const Figuras& orig);
        virtual ~Figuras();

        string nombre;
        string color;


	virtual void calcularArea();
	virtual void calcularPerimetro();

	virtual void operator~();
	virtual void operator!();
};

// Clases derivadas de Figuras
class Cuadrado: public Figuras
{
   public:
	Cuadrado();
        Cuadrado(string nombre, string color, double lado);
        Cuadrado(const Cuadrado& orig);
        virtual ~Cuadrado();

        string nombre;
        string color;
        double lado;
        double area;
        double perimetro;

        virtual void calcularArea(double lado);
        virtual void calcularPerimetro(double lado);
        virtual void operator~();
	virtual void operator!();
};

class Triangulo: public Figuras
{
   public:
        Triangulo();
        Triangulo(string nombre, string color, double base, double altura, double hipotenusa);
        Triangulo(const Triangulo& orig);
        virtual ~Triangulo();

        string nombre;
        string color;
        double base;
        double altura;
        double hipotenusa;
        double area;
        double perimetro;

        virtual void calcularArea(double base, double altura);
        void calcularPerimetro(double base, double altura, double hipotenusa);
        virtual void operator~();
	virtual void operator!();
};

class Circulo: public Figuras
{
   public:
		Circulo();
        Circulo(string nombre, string color, double radio);
        Circulo(const Circulo& orig);
        virtual ~Circulo();

        string nombre;
        string color;
        double radio;
        double area;
        double perimetro;

        const double PI  = 3.141592653589793238463;
        virtual void calcularArea(double radio);
        virtual void calcularPerimetro(double radio);
        virtual void operator~();
	virtual void operator!();
};

#endif // FIGURAS_H
