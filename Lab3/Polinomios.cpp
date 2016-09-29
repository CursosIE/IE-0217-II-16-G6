#include <iostream>
#include <math.h>
#include "Polinomios.h"

/**
 * @brief Constructor vacio de clase Polinomios.
 */
Polinomios::Polinomios() {

    this -> base = 1;
    this -> coeficientes = 0;

};

/**
 * @brief Constructor sobrecargado de la clase Polinomios.
 *
 * @param base Orden del polinomio.
 * @param coeficientes Puntero de coeficientes del polinomio.
 */
Polinomios::Polinomios(int base, double* coeficientes) {

    this -> base = base;
    this -> coeficientes = coeficientes;
    
};

/**
 * @brief Constructor de la clase Polinomios.
 *
 * @param Polinomios& Constante objeto.
 */
Polinomios::Polinomios(const Polinomios& orig) {
}


/**
 * @brief Destructor de la clase Polinomios.
 */
Polinomios::~Polinomios(){};

/**
 * @brief Sobrecarga el operador + para sumar dos objetos tipo Polinomios.
 *
 * @param &ELOTRO Objeto del tipo Polinomio.
 */
Polinomios Polinomios::operator + (const Polinomios &ELOTRO){
   
    int a;

    if (this->base < ELOTRO.base) {

        a = ELOTRO.base;

    }

    else {

        a = this -> base;

    }

    double *res = new double [a];

    for (int i = 0; i < a; i++) {
  
    res[i] = ELOTRO.coeficientes[i] + coeficientes[i];

    }

    Polinomios resultado(a, res);

    delete [] res;

    return resultado;
        
}


/**
 * @brief Sobrecarga el operador - para restar dos objetos tipo Polinomios.
 *
 * @param &ELOTRO Objeto del tipo Polinomio.
 */
Polinomios Polinomios::operator - (const Polinomios &ELOTRO){
    
    int a;

    if (this->base < ELOTRO.base) {

        a = ELOTRO.base;

    }

    else {

        a = this -> base;

    }

    double *res = new double [a];

    for (int i = 0; i < a; i++) {
  
    res[i] = coeficientes[i] - ELOTRO.coeficientes[i];

    }

    Polinomios resultado(a, res);

    delete [] res;

    return resultado;
        
}

/**
 * @brief Sobrecarga el operador * para multiplicar dos objetos tipo Polinomios.
 *
 * @param &ELOTRO Objeto del tipo Polinomio.
 */
Polinomios Polinomios::operator*(const Polinomios &ELOTRO){
    
    int a = this -> base;

    int b = ELOTRO.base;

    double *res = new double [a + b];

    for (int i = 0; i < a; i++) {
   
        for (int j = 0; j < b; j++) {
  
             res[i + j] = ELOTRO.coeficientes[i] * coeficientes[j];

        }

    }

    Polinomios resultado(a + b, res);

    delete [] res;

    return resultado;
        
}

/**
 * @brief Sobrecarga el operador / para dividir dos objetos tipo Polinomios.
 * Genera dos vectores, el vector q es el resultado de la division y el numero
 * entero del tipo int que es el residuo
 *
 * @param &ELOTRO Objeto del tipo Polinomio.
 */
Polinomios Polinomios::operator /(const Polinomios &ELOTRO)
{
	int i, dd, dq, dN, base2;				

        dN = this -> base;
        base2 = ELOTRO.base;
	
	dq = dN - base2;  
 
 	double *N = new double [dN];					
	
        for ( i = 0; i < dN; i++ ) {

        	N[i] = this -> coeficientes[i];
	
        }
	
        double *D = new double [base2];
	
         for ( i = 1; i < dN; i++ ) {
	
        	D[i] = ELOTRO.coeficientes[i];


        }
 
	double *d = new double [dN];
	 
	double *q = new double [dq];

        for( i = 0 ; i < dq; i++ ) {
		q[i] = 0;

	}
	 
	if( base2 < 0) {
		cout << "El grado debe ser mayor a 0.";
	}


	if( dN >= base2 ) {
		while(dN >= base2) {

			for( i = 0 ; i < dN; i++ ) {
				d[i] = 0;

			}
			for( i = 0 ; i < base2; i++ ) {
				d[i + dN - base2] = D[i];


			}
			dd = dN - 1;
            		q[dN - base2] = N[dN - 1]/d[dd];


			for( i = 0 ; i < dq; i++ ) {
				d[i] = d[i] * q[dN - base2 - 1];

			}

 

			for( i = 0 ; i < dN; i++ ) {
				N[i] = N[i] - d[i];

			}
			dN --;
			 
		}
 
	}
 
	Polinomios resultado(dq, q);
        
        delete [] N;
        delete [] D;
        delete [] d;
        delete [] q;

        return resultado;

}

/**
 * @brief Sobrecarga el operador ~ para imprimir los atributos de la clase.
 */
void Polinomios::operator~(){

   cout << coeficientes[0] << " " ;

   for(int i = 1; i < base; i++) {
        
        cout << "+ " << coeficientes[i] << "x" << i << " ";
        
    };

    cout << endl;
    
}
