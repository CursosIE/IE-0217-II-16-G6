compilar:
	g++ -o traductorARN.c++ traductorARN.cpp

borrar:
	rm traductorARN.c++

ejecutar: compilar
	./traductorARN.c++ $(filter-out $@,$(MAKECMDGOALS))
