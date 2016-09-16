/**
 * @file traductorARN.cpp
 * @author Jose Fernando Gonzalez Salas & Isaac Gomez Sanchez
 * @date 5 de setiembre, 2016
 * @brief Este programa realiza la traduccion del codigo genetico de una linea de codones a su respectivo ARN. Comenzando siempre y terminando con un codon de parada establecidos en los cuadros de traduccion oficiales.
 * @see https://en.wikipedia.org/wiki/Genetic_code#RNA_codon_table
 */

#include <iostream>
 
using namespace std;

/**
 * @brief Compara las secuencias de caracteres con la tabla de traduccion
 *
 * La funcion recorre el arreglo ingresado para luego regresar el caracter correspondiente a la traduccion del ARN segun la tabla de referencia.
 *
 * @param lista Secuencia de caracteres ingresados por el usuario.
 * @param contador Variable de control para el contador que recorre el arreglo
 * @warning El primer dato de la lista es el nombre del ejecutable.
 */
char comparador(char** lista, int contador){
    
    if (lista[1][contador] == 'U'){
            
            if (lista[1][contador+1] == 'U'){
                
                if (lista[1][contador+2] == 'U' || lista[1][contador+2] == 'C' ){
                    
                    return 'F';
                    //i = i - 2;
                    
                }
                
                else if (lista[1][contador+2] == 'A' || lista[1][contador+2] == 'G' ){
                    
                    return 'L';
                    
                }
                
            }
                                
            else if (lista[1][contador+1] == 'C'){
                
                return 'S';
                    
                }
            
            else if (lista[1][contador+1] == 'A'){
                
                if (lista[1][contador+2] == 'U' || lista[1][contador+2] == 'C' ){
                    
                    return 'Y';
                    //i = i - 2;
                    
                }
                
                else if (lista[1][contador+2] == 'A' || lista[1][contador+2] == 'G' ){
                    
                    return '\0';
                    
                }
            
            }
            
            else if (lista[1][contador+1] == 'G'){
                
                if (lista[1][contador+2] == 'U' || lista[1][contador+2] == 'C' ){
                    
                    return 'C';
                    //i = i - 2;
                    
                }
                
                else if (lista[1][contador+2] == 'A'){
                    
                    return '\0';
                    
                }
                
                else if (lista[1][contador+2] == 'G'){
                    
                    return 'W';
                    
                }
            
            }
        
    }

    
    else if (lista[1][contador] == 'C'){
            
            if (lista[1][contador+1] == 'U'){
                
                return 'L';    
                    
            }
                                
            else if (lista[1][contador+1] == 'C'){
                
                return 'C';
                    
            }
            
            else if (lista[1][contador+1] == 'A'){
                
                if (lista[1][contador+2] == 'U' || lista[1][contador+2] == 'C' ){
                    
                    return 'H';
                    //i = i - 2;
                    
                }
                
                else if (lista[1][contador+2] == 'A' || lista[1][contador+2] == 'G' ){
                    
                    return 'Q';
                    
                }
            
            }
            
            else if (lista[1][contador+1] == 'G'){
                
                return 'R';
            
            }
        
    }
    
    else if (lista[1][contador] == 'A'){
            
            if (lista[1][contador+1] == 'U'){
                
                if (lista[1][contador+2] == 'U' || lista[1][contador+2] == 'C' || lista[1][contador+2] == 'A'  ){
                    
                    return 'I';
                    //i = i - 2;
                    
                }
                
                else if (lista[1][contador+2] == 'G' ){
                    
                    return 'M';
                    
                }
                
            }
                                
            else if (lista[1][contador+1] == 'C'){
                
                return 'T';
                    
            }
            
            else if (lista[1][contador+1] == 'A'){
                
                if (lista[1][contador+2] == 'U' || lista[1][contador+2] == 'C' ){
                    
                    return 'N';
                    //i = i - 2;
                    
                }
                
                else if (lista[1][contador+2] == 'A' || lista[1][contador+2] == 'G' ){
                    
                    return 'K';
                    
                }
            
            }
            
            else if (lista[1][contador+1] == 'G'){
                
                if (lista[1][contador+2] == 'U' || lista[1][contador+2] == 'C' ){
                    
                    return 'S';
                    //i = i - 2;
                    
                }
                
                else if (lista[1][contador+2] == 'A' || lista[1][contador+2] == 'G' ){
                    
                    return 'R';
                    
                }
                    
            }
        
    }
        
    
    else if (lista[1][contador] == 'G'){
            
            if (lista[1][contador+1] == 'U'){
                
                return 'V';
                
            }
                                
            else if (lista[1][contador+1] == 'C'){
                
                return 'A';
                    
                }
            
            else if (lista[1][contador+1] == 'A'){
                
                if (lista[1][contador+2] == 'U' || lista[1][contador+2] == 'C' ){
                    
                    return 'D';
                    //i = i - 2;
                    
                }
                
                else if (lista[1][contador+2] == 'A' || lista[1][contador+2] == 'G' ){
                    
                    return 'E';
                    
                }
            
            }
            
            else if (lista[1][contador+1] == 'G'){
                
                return 'G';
            
            }
        
    }        
}

/**
 * @brief Imprime la secuencia resultante.
 *
 * La funcion imprime uno por uno los caracteres que corresponden al arreglo ingresado.
 *
 * @param cadena Arreglo a imprimir.
 * @warning La funcion deja de imprimir al encontrar la bandera de parada dada por el codon establecido.
 */
void imprimir(char* cadena)
{
	cout << "|";
	for (int i=0; cadena[i] != '\0'; i++)
	{
		cout << cadena[i] ;
	}
	cout << "|\n";
}

/**
 * @brief Traduce el ARN.
 *
 * La funcion toma el arreglo de datos del usuario y lo recorre para traducir la secuencia hasta llegar al codon de parada.
 *
 * @param codigo Arreglo de datos ingresados por el usuario.
 * @param respuesta Arreglo resultante de la traduccion.
 * @warning El primer dato del arreglo es el nombre del ejecutable.
 */
void traducirARNaAA (char** codigo, char* respuesta)
{	
	bool terminar = true;
	int i=0;
	while(terminar)	 
	{
		respuesta[i] = comparador(codigo, i*3+3);
			if (respuesta[i]== '\0')
			{
				terminar = false; 
			}
		i++;
	}		
	imprimir(respuesta);	
}

/**
 * @brief Inicia el programa.
 *
 * Funcion principal del programa en donde se ejecutan las funciones en orden para dar el resultado de la traduccion de manera correcta.
 *
 * @param argc Cantidad de datos ingresados por el usuario.
 * @param argv Arreglo con los datos del usuario para traducir.
 * @warning El primer dato del arreglo es el nombre del ejecutable.
 */
int main (int argc, char** argv)
{
	char* resultado= new char;
	traducirARNaAA(argv, resultado);	
	delete resultado ;
}
