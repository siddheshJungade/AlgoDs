#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> l;
public:
    void addEdge(int x , int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src){
        queue<T> q;
        map<T,bool> visited;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for( auto nbr : l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }  
    }
    //this will traverse dfs 
    void dfs_helper(T src ,map<T,bool> &visited){
        cout << src << " ";
        visited[src] = true;
        for(T nbr : l[src]){
            if(not visited[nbr]){
                dfs_helper(nbr,visited);
            }
        }

    }
    
    void dfs(T src) {
        map<T,bool> visited;
        // this will mark all node not visited
        for(auto h : l){
            T node = h.first;
            visited[node] = false;
        }
        // call the helper
        dfs_helper(src , visited);
    }

};

int main(int argc, char const *argv[])
{
    
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);

    g.bfs(0);
    cout << endl;
    g.dfs(0);

    
    return 0;
}
