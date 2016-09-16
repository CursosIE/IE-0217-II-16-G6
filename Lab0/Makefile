compilar:
	chmod +x sumando.py
	cp sumando.py suma.py
	gcc -std=c99 -o suma.o suma.c
	g++ -o suma.c++ suma.cpp

borrar:
	rm suma.py
	rm suma.o
	rm suma.c++


ejecutar: compilar
	./suma.py $(filter-out $@,$(MAKECMDGOALS))
	./suma.o $(filter-out $@,$(MAKECMDGOALS))
	./suma.c++ $(filter-out $@,$(MAKECMDGOALS))
