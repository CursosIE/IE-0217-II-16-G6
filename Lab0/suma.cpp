/**
 * @file suma.cpp
 * @author Jose Fernando Gonzalez Salas & Isaac Gomez Sanchez
 * @date 23 de agosto, 2016
 * @brief Este programa realiza la suma de datos introducidos en la consola al ejecutar el mismo. Obtiene numeros introducidos por el usuario seguidamente al ejecutar el programa suma.c++ . El usuario debe recordar compilar el programa antes de ejecutarlo. Este programa cuenta con manejo de excepciones en caso de no ingresar un dato para la suma.
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/**
 * @brief Suma los datos ingresados.
 *
 * La funcion toma el arreglo de datos del usuario y lo recorre, comenzando desde el segundo dato para evitar el nombre del ejecutable.
 *
 * @param contador Cantidad de datos ingresados por el usuario.
 * @param sumandos Arreglo con los datos del usuario para sumar.
 * @warning El primer dato del arreglo es el nombre del ejecutable.
 */

double sumar (int contador, char *sumandos[]) { 
	double resultado;
	for (int i=0; i<contador; i++){					
			resultado +=  atof(sumandos[i]) ;					
	}	
	return(resultado);
}


/**
 * @brief Funcion principal del programa a ejecutar.
 *
 * La funcion corre el programa con los datos introducidos por el usuario e ingresa a las funciones correspondientes para obtener el resultado.
 *
 * @param argc Cantidad de datos ingresados por el usuario.
 * @param argv Arreglo con los datos del usuario ingresado en la consola.
 * @warning El primer dato del arreglo es el nombre del ejecutable.
 */

int main(int argc, char *argv[]){

while(true){	
	if (argc > 1) {		
			double N = sumar(argc, argv); 
			cout << "La suma es: " << N <<endl;
			break;
	}
	else{
		cout <<"Ingrese uno o más parámetros.\n";
	}
}
}
