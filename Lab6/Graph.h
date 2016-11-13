
#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<list>

using namespace std;
 
class Graph
{
    int V;   
    list<int> *adj;   
    void DFSUtil(int v, bool visited[]); 
public:
    Graph(int V);  
    void addEdge(int v, int w);   
    void DFS(); 
    void BFS(int s);   
};

#endif /* GRAPH_H */

