#include<bits/stdc++.h>
using namespace std;

void bellmanFord(vector<vector<int>>&edges , int v , int e , int src){
    vector<int>cost(v,1e8);
    vector<int>prev(v,1e8);
    cost[src] = 0;
    prev[src] = 0;

    for(int i = 0 ; i < v ; i++){
        for(int j = 0 ; j < e ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(cost[u]!=1e8 && cost[u]+wt<cost[v]){
                cost[v] = cost[u]+wt;
            }
        }

        cout<<endl<<"Iteration "<<i+1<<": ";
        for(int j = 0 ; j < v ; j++){
            cout<<cost[j]<<"    ";
        }       

        if(prev == cost){
            cout<<endl<<"No cost changes , so no further calculation ";
            break;
        }
        prev = cost;

        if(i == v-1){
            cout<<"Graph cointain negative cycle ";
            break;
        }
    }
}

int main(){
    int v , e , src;
    cout<<"Enter number of vertices : ";
    cin>>v;
    cout<<"Enter number of edges : ";
    cin>>e;
    cout<<"Enter source of the graph : ";
    cin>>src;

    vector<vector<int>> edges;

    vector<vector<int>>matrix(v,vector<int>(v,1e8));
    for(int i = 0 ; i < e ; i++){
        vector<int>temp;
        int u,v,wt;
        cout<<"Enter starting point of edge : ";
        cin>>u;
        cout<<"Enter ending point of edge : ";
        cin>>v;
        cout<<"Enter weight of the edge : ";
        cin>>wt;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(wt);
        edges.push_back(temp);
        matrix[u][v] = wt;
    }

    cout<<"The adjacency matrix is : "<<endl;
    for(int i = 0 ; i < v ; i++){
        for (int j = 0 ; j < v ; j++){
            cout<<matrix[i][j]<<"        ";
        }
        cout<<endl;
    }

    cout<<"The set of edges is : "<<endl;
    for(int i = 0 ; i < e ; i++){
        cout<<"("<<edges[i][0]<<","<<edges[i][1]<<")";
    }

    bellmanFord(edges,v,e,src);
    return 0;


}