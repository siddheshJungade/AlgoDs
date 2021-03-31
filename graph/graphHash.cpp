#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    // Adj list
    unordered_map<string,list<pair<string,int>>> l;
public:
    void addEdge(string x , string y , bool bidir ,int wt){
        l[x].push_back(make_pair(y,wt));
        if(bidir)
            l[y].push_back(make_pair(x,wt));
    }
    void printAdjList(){
        for(auto p : l){
            string city = p.first;
            list<pair<string,int>> li = p.second;
            cout << city << "=>" ;
            for(auto listItem : li){
                string dest = listItem.first;
                int dist = listItem.second;
                cout << dest<< " " << dist << ','; 
            }
            cout << "\n";
        }
    }

};

int main(int argc, char const *argv[])
{
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,5 );
    g.printAdjList();
    return 0;
}
