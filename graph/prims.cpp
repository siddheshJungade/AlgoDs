#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;
#define V 5

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

int minEdge(int Edge[], bool mstSet[])
{
    int min = INT_MAX;
    int minIdx;
    for (int i = 0; i < V; i++)
    {
        if (mstSet[i] == false and Edge[i] < min)
            min = Edge[i], minIdx = i;
    }
    return minIdx;
}
void prims(int graph[V][V])
{
    int Ans[V];

    int Edge[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        Edge[i] = INT_MAX, mstSet[i] = false;

    Edge[0] = 0;
    Ans[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minEdge(Edge, mstSet);

        mstSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] and mstSet[v] == false and graph[u][v] < Edge[v])
                Ans[v] = u, Edge[v] = graph[u][v];
        }
    }
    printMST(Ans, graph);
};
int main(int argc, char const *argv[])
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    prims(graph);

    return 0;
}
