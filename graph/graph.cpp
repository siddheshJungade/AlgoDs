#include<iostream>
#include<list>
using namespace std;
class Graph {
    int V;
    // Array list;
    list<int> *l;
public:
    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }
    void addEdge(int x ,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    } 
    void printAdjList(){
        for (int i = 0; i < V; i++)
        {
               cout << i << "->"; 
            for(int lstNode : l[i])
                cout << lstNode << " ";
            cout << "\n";
        }
    }

};

int main(int argc, char const *argv[])
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.printAdjList();
    
    return 0;
}
