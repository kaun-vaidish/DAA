#include <bits/stdc++.h>
using namespace std;


// User function Template for C++


    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s) {
    vector<int>cost(v,1e8);
    cost[s] = 0;
    
    
    for(int i = 0 ; i < v ; i++){
        for(int j = 0 ; j < edges.size() ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if( cost[u]!=1e8 && cost[u] + wt < cost[v]){
                cost[v] = cost[u] + wt;
            }
        }
    }
    
    
    for(int j = 0 ; j < edges.size() ; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if( cost[u]!=1e8 && cost[u] + wt < cost[v]){
            cout<<"There is a negative cycle ! ";
            return {-1};
        }
    }
    
    return cost;
}



int main() {

    int v, m; //m is no. of edges
    cout<<"Enter number of vertices ";
    cin >> v;
    cout<<"Enter number of edges ";
    cin >> m;
    vector<vector<int>> edges;

    for (int i = 0; i < m; ++i) {
        vector<int> temp;
        int u ;
        cout<<"Enter source starting point of edge : ";
        cin>>u;
        temp.push_back(u);
        int v ;
        cout<<"Enter destination point of edge : ";
        cin>>v;
        temp.push_back(v);
        int wt ;
        cout<<"Enter weight of edge : ";
        cin>>wt;
        temp.push_back(wt);
        edges.push_back(temp);
    }

    int src;
    cout<<"Enter source :";
    cin >> src;

    vector<int> res = bellman_ford(v, edges, src);

    cout<<"The minimum distance array is : ";
    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}

