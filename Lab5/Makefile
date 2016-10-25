compile:
	g++ -o a.out main.cpp ListaConArreglo.cpp Lista.cpp Pila.cpp Zelda.cpp

clean:
	rm a.out

execute: compile
	./a.out $(filter-out $@,$(MAKECMDGOALS))
