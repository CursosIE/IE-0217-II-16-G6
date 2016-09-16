#include "Figuras.h"

/**
 * @brief Constructor vacio de clase Figuras.
 */
Figuras::Figuras() {};

/**
 * @brief Constructor sobrecargado de la clase Figuras.
 *
 * @param nombre Nombre de la figura.
 * @param color Color de la figura.
 */
Figuras::Figuras(string nombre, string color) {
    this->nombre = nombre;
    this->color = color;
};

/**
 * @brief Constructor de la clase Figuras.
 *
 * @param Figuras& Constante objeto.
 */
Figuras::Figuras(const Figuras& orig){};

/**
 * @brief Destructor de la clase Figuras.
 */
Figuras::~Figuras(){};

/**
 * @brief Llama a la funcion en la clase Figuras.
 */
void Figuras::calcularArea(){};

/**
 * @brief Llama a la funcion en la clase Figuras.
 */
void Figuras::calcularPerimetro() {};

/**
 * @brief Sobrecarga el operador ~ para imprimir los atributos de la clase.
 */
void Figuras::operator~(){
	cout << this->nombre << this->color << endl; 
};

/**
 * @brief Sobrecarga el operador ! para imprimir los calculos de la clase.
 */
void Figuras::operator!(){
    cout << "0" << endl;
    cout << "0" << endl;
};

				/*  Clases derivadas   */


//Cuadrado

/**
 * @brief Constructor vacio de la clase Cuadrado.
 */
Cuadrado::Cuadrado() {}

/**
 * @brief Constructor sobrecargado de la clase Cuadrado.
 *
 * @param nombre Nombre de la figura.
 * @param color Color de la figura.
 * @param lado Valor del lado de la figura.
 */
Cuadrado::Cuadrado(string nombre, string color, double lado) {
	this->nombre=nombre;
        this->color=color;
        this->lado=lado;
        this->area;
        this->perimetro;
}

/**
 * @brief Constructor de la clase Cuadrado.
 *
 * @param Cuadrado& Constante objeto.
 */
Cuadrado::Cuadrado(const Cuadrado& orig) {};


/**
 * @brief Destructor de la clase Cuadrado.
 */
Cuadrado::~Cuadrado() {};

/**
 * @brief Llama a la funcion en la clase Figuras.
 */
void Cuadrado::calcularArea(double lado) {
        this->area=(lado * lado);
	return;	
};

/**
 * @brief Llama a la funcion en la clase Figuras.
 */
void Cuadrado::calcularPerimetro(double lado){
	this->perimetro=lado * 4;
	return;
};

/**
 * @brief Sobrecarga el operador ~ para imprimir los atributos de la clase.
 */
void Cuadrado::operator~(){
	cout << this->nombre << endl;
	cout << this->color << endl;
	cout << this->lado <<  endl; 
};

/**
 * @brief Sobrecarga el operador ! para imprimir los calculos de la clase.
 */
void Cuadrado::operator!(){
    cout << this->area << endl;
    cout << this->perimetro << endl;
};


//Triangulo

/**
 * @brief Constructor vacio de la clase Triangulo.
 */
Triangulo::Triangulo() {}

/**
 * @brief Constructor sobrecargado de la clase Triangulo.
 *
 * @param nombre Nombre de la figura.
 * @param color Color de la figura.
 * @param base Valor de la base de la figura.
 * @param altura Valor de la altura de la figura.
 * @param hipotenusa Valor de la hipotenusa de la figura.
 */
Triangulo::Triangulo(string nombre, string color, double base, double altura, double hipotenusa) {
        this->nombre=nombre;
        this->color=color;
	this->base=base;
	this->altura=altura;
	this->hipotenusa=hipotenusa;
        this->area;
        this->perimetro;
}

/**
 * @brief Constructor de la clase Triangulo.
 *
 * @param Triangulo& Constante objeto.
 */
Triangulo::Triangulo(const Triangulo& orig) {};

/**
 * @brief Destructor de la clase Cuadrado.
 */
Triangulo::~Triangulo() {};

/**
 * @brief Calcula el area del triangulo con sus parametros.
 *
 * @param base Valor de la base de la figura.
 * @param altura Valor de la altura de la figura.
 */
void Triangulo::calcularArea(double base, double altura) {
    this->area=(base * altura / 2);
    return;
}

/**
 * @brief Calcula el perimetro del triangulo con sus parametros.
 *
 * @param base Valor de la base de la figura.
 * @param altura Valor de la altura de la figura.
 * @param hipotenusa Valor de la hipotenusa de la figura.
 */
void Triangulo::calcularPerimetro(double base, double altura, double hipotenusa){
    this->perimetro=(base + altura + hipotenusa);
    return;
}

/**
 * @brief Sobrecarga el operador ~ para imprimir los atributos de la clase.
 */
void Triangulo::operator~(){
	cout << this->nombre << endl;
	cout << this->color << endl;
	cout << this->base << endl;
	cout << this->altura << endl;
	cout << this->hipotenusa << endl; 
}

/**
 * @brief Sobrecarga el operador ! para imprimir los calculos de la clase.
 */
void Triangulo::operator!(){
    cout << this->area << endl;
    cout << this->perimetro << endl;
}

//Circulo

/**
 * @brief Constructor vacio de la clase Circulo.
 */
Circulo::Circulo() {}

/**
 * @brief Constructor sobrecargado de la clase Triangulo.
 *
 * @param nombre Nombre de la figura.
 * @param color Color de la figura.
 * @param radio Valor del radio de la figura.
 */
Circulo::Circulo(string nombre, string color, double radio) {
        this->nombre=nombre;
        this->color=color;
	this -> radio=radio;
        this->area;
        this->perimetro;
}

/**
 * @brief Constructor de la clase Circulo.
 *
 * @param Circulo& Constante objeto.
 */
Circulo::Circulo(const Circulo& orig) {}

/**
 * @brief Destructor de la clase Circulo.
 */
Circulo::~Circulo() {

}

/**
 * @brief Calcula el area del circulo con sus parametros.
 *
 * @param radio Valor del radio de la figura.
 */
void Circulo::calcularArea(double radio) {
    this->area=(radio * radio * PI);
    return;    
}

/**
 * @brief Calcula el perimetro del circulo con sus parametros.
 *
 * @param radio Valor del radio de la figura.
 */
void Circulo::calcularPerimetro(double radio){
    this->perimetro=(2 * PI * radio);
    return;		
}

/**
 * @brief Sobrecarga el operador ~ para imprimir los atributos de la clase.
 */
void Circulo::operator~(){
	cout << this->nombre  << endl;
	cout << this->color << endl;
	cout << this->radio << endl; 
}

/**
 * @brief Sobrecarga el operador ~ para imprimir los atributos de la clase.
 */
void Circulo::operator!(){
    cout << this->area << endl;
    cout << this->perimetro << endl;
}




