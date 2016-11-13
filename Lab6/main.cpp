/**
 * @file main.cpp
 * @author Jose Fernando Gonzalez Salas & Isaac Gomez Sanchez
 * @date 13 de noviembre, 2016
 * @brief Se implementa la estructura abstracta de grafo usando la matriz de adyacecia y las búsquedas de profundidad y ancho.
 */

#include "Graph.h"

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    g.DFS();
    cout << endl;
    g.BFS(2);
    cout << endl;
 
    return 0;
}
