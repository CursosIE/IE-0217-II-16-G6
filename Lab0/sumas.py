import sys

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
