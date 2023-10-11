#include <bits/stdc++.h>
using namespace std;

void bellman_ford(int v, vector<vector<int>>& edges, int s) {
    vector<int>cost(v,1e8);
    vector<int>prev(v,1e8);

    cost[s] = 0;
    prev[s] = 0;
    
    for(int i = 0 ; i < v ; i++){
        for(int j = 0 ; j < edges.size() ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if( cost[u]!=1e8 && cost[u] + wt < cost[v]){
                cost[v] = cost[u] + wt;
            }
        }
        cout<<"\n\nIteration"<<i+1<<"  :      ";
        for(int k = 0 ; k < v ; k++){
            cout<<cost[k]<<"    ";
        }
        if(cost==prev){
            cout<<"\n\nSame as previous thus no further calculation needed !";
            break;
        }
        prev = cost;
        if(i==v-1){
            cout<<"\n\nThere is a negative cycle !";
            break;
        }
    } 
}


int main() {

    int v, e; //e is no. of edges
    cout<<"Enter number of vertices ";
    cin >> v;
    cout<<"Enter number of edges ";
    cin >> e;
    vector<vector<int>>edges;
    int matrix[v][v];
    for(int i = 0 ; i < v ; i++){
        for(int j = 0 ; j < v ; j++){
            matrix[i][j] = 1e8;
        }
    }

    for (int i = 0; i < e; ++i) {
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
        matrix[u][v] = wt;
        temp.push_back(wt);
        edges.push_back(temp);
    }

    int src;
    cout<<"Enter source :";
    cin >> src;

    cout<<"\nThe adjacency matrix is :\n";
    for(int i = 0 ; i < v ; i++){
        cout<<endl;
        for(int j = 0 ; j < v ; j++){
            cout<<"     "<<matrix[i][j]<<"      " ;
        }
    }

    cout<<"\n\nThe set of edges is :  ";
    for(int i = 0 ; i < edges.size() ; i++){
        cout<<"("<<edges[i][0]<<","<<edges[i][1]<<")\t";
    }
    
    bellman_ford(v,edges,src);
    return 0;
}

