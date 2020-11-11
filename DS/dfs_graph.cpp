// Main function of the C++ program.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T> 
void dfs_helper(T src, map<T, bool> &vis, map<T, vector<T> > m){
    vis[src]=true;
    cout<<src<<" ";
    for(int i=0; i<m[src].size(); i++){
        if(vis.count(m[src][i])==0){
            dfs_helper(m[src][i], vis, m);
        }
    }
}

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

    void dfs(T src){
        map <T, bool> vis;
        dfs_helper(src, vis, m);
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
    G.addVertex("West Bengal");
    G.addVertex("Assam");

    //adding edges between cities
    G.addEdge("Delhi", "Mumbai");
    G.addEdge("Delhi", "Punjab");
    G.addEdge("Delhi", "Hyderabad");
    G.addEdge("Mumbai", "Jaipur");
    G.addEdge("Punjab", "Jaipur");
    G.addEdge("Hyderabad", "Bangalore");
    G.addEdge("Hyderabad", "West Bengal");
    G.addEdge("West Bengal", "Assam");
    
    //printing the bfs traversal, starting from Delhi
    G.dfs("Delhi");
}
