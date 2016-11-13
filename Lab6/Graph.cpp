#include "Graph.h"

/**
 * @brief Constructor de clase Graph.
 *
 * @param V Numero de vertices
 */
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

/**
 * @brief Agrega un vertice
 *
 * @param v Posicion a agregar
 * @param w Dato a agregar
 */
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

/**
 * @brief Busca en todos los nodos
 *
 * @param v Posicion a agregar
 * @param visited Arreglo donde indica si visito o no el nodo
 */ 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

/**
 * @brief Busqueda DFS
 *
 */
void Graph::DFS()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFSUtil(i, visited);
}

/**
 * @brief Busqueda BFS
 *
 */
void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;
 
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
