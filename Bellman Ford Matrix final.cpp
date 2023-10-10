// #include <bits/stdc++.h>
// using namespace std;

//     /*  Function to implement Bellman Ford
//     *   edges: vector of vectors which represents the graph
//     *   s: source vertex to start traversing graph with
//     *   v: number of vertices
//     */
// vector<int> bellman_ford(int v, int &edges[][3], int s) {
//     vector<int>cost(v,INT_MAX);
//     cost[s] = 0;
    
    
//     for(int i = 0 ; i < v ; i++){
//         for(int j = 0 ; j < v ; j++){
//             int u = i;
//             int v = j;
//             int wt = edges[u][v];
//             if( cost[u]!=INT_MAX && cost[u] + wt < cost[v]){
//                 cost[v] = cost[u] + wt;
//             }
//         }
//     }
    
//     int i = v;
//     for(int j = 0 ; j < v ; j++){
//         int u = i;
//         int v = j;
//         int wt = edges[u][v];
//         if( cost[u]!=INT_MAX && cost[u] + wt < cost[v]){
//             cost[v] = cost[u] + wt;
//         }
//     }
    
//     return cost;
// }



// int main() {

//     int v, m; //m is no. of edges
//     cout<<"Enter number of vertices ";
//     cin >> v;
//     cout<<"Enter number of edges ";
//     cin >> m;
//     int edges[v][v];

//     for(int i = 0 ; i < v ; i++){
//         for(int j = 0 ; j < v ; j++){
//             edges[i][j] = INT_MAX;
//         }
//     }

//     for (int i = 0; i < m; ++i) {

//         int u ;
//         cout<<"Enter source starting point of edge : ";
//         cin>>u;
        
//         int v ;
//         cout<<"Enter destination point of edge : ";
//         cin>>v;
        
//         int wt ;
//         cout<<"Enter weight of edge : ";
//         cin>>wt;
        
//         edges[u][v] = wt;
//     }

//     int src;
//     cout<<"Enter source :";
//     cin >> src;

//     vector<int> res = bellman_ford(v, edges, src);

//     cout<<"The minimum distance array is : ";
//     for (auto x : res) {
//         cout << x << " ";
//     }
//     cout << "\n";
    
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int v, int edges[][100], int s) {
    vector<int> cost(v, INT_MAX);
    cost[s] = 0;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {

            if(edges[i][j]!=-1){
                int u = i;
                int v = j;
                
                int wt = edges[u][v];
                if (cost[u] != INT_MAX && cost[u] + wt < cost[v]) {
                    cost[v] = cost[u] + wt;
                }
            }
        }
    }

    return cost;
}

int main() {
    int v, m; // m is the number of edges
    cout << "Enter number of vertices ";
    cin >> v;
    cout << "Enter number of edges ";
    cin >> m;
    int edges[100][100]; // Assuming a maximum size of 100x100 for the array

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            edges[i][j] = -1;
        }
    }

    for (int i = 0; i < m; ++i) {
        int u, v, wt;
        cout << "Enter source starting point of edge : ";
        cin >> u;
        cout << "Enter destination point of edge : ";
        cin >> v;
        cout << "Enter weight of edge : ";
        cin >> wt;

        edges[u][v] = wt;
    }

    int src;
    cout << "Enter source :";
    cin >> src;

    vector<int> res = bellman_ford(v, edges, src);

    cout << "The minimum distance array is : ";
    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
