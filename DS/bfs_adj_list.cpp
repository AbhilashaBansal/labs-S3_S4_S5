#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T> 
class Graph{
    //using adjacency list
    list <T> l;
    map <T, vector<T> > m;
    public: 
    void addVertex(T ver){
        l.push_back(ver);
    }
    void addEdge(T x, T y){
        m[x].push_back(y);
        m[y].push_back(x);
    }
    void bfs(T src){
        map <T, bool> vis;
    //   for(map<T, list<T> >::iterator it = m.begin(); it!=m.end(); it++){
    //       T node = it->first;
    //       vis[node] = false;
    //   }
      
        queue <T> q;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(int i=0; i<m[node].size(); i++){
                T nbr = m[node][i];
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
            cout<<node<<" ";
        }
    }
};

int main()
{
    Graph <string> G;
    //adding cities as vertices
    G.addVertex("Delhi");
    G.addVertex("Mumbai");
    G.addVertex("Punjab");
    G.addVertex("Jaipur");
    G.addVertex("Hyderabad");
    G.addVertex("Bangalore");

    //adding edges between cities
    G.addEdge("Delhi", "Mumbai");
    G.addEdge("Delhi", "Punjab");
    G.addEdge("Delhi", "Hyderabad");
    G.addEdge("Mumbai", "Jaipur");
    G.addEdge("Punjab", "Jaipur");
    G.addEdge("Hyderabad", "Bangalore");
    
    //printing the bfs traversal, starting from Delhi
    G.bfs("Delhi");
}
