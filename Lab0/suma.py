#!/usr/bin/python

## @file suma.py
# @author Jose Fernando Gonzalez Salas & Isaac Gomez Sanchez
# @date 23 de agosto, 2016
# @brief Este programa realiza la suma de datos introducidos en la consola al ejecutar el mismo. Obtiene numeros introducidos por el usuario seguidamente al ejecutar el programa suma.py . El usuario debe recordar compilar el programa antes de ejecutarlo. Este programa cuenta con manejo de excepcione en caso de ingresar un dato no valido para la suma.

# Librerias necesarias para las funciones utilizadas
import sys

## @brief Funcion que utiliza una lista ingresada en la consola seguidamente de la llamada al script y suma cada uno de sus elementos.
#
# Ingresa por medio de sys.argv
def suma():
	total = 0.0
	for x in range(1, len(sys.argv)):
		try:
			num = float(sys.argv[x])
			total = total + num
		except ValueError:
			total = "Se ha encontrado un caracter no valido"
	return total

# Ejecucion del script
print suma()	
