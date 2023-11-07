// #include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

int inf = INT_MAX;

void reduce(vector<vector<int>>&costMatrix){

    int n = costMatrix.size();

    for(int i = 0 ; i < n ; i++){
        int minVal  = inf;
        for(int j = 0 ; j < n ; j++){
            if(costMatrix[[i][j]<minVal]){
                minVal = costMatrix[j][j];
            }
        }
        if(minVal!=inf){
            for(int j = 0 ; j < n ; j++){
                if(costMatrix[i][j]!=inf){
                    costMatrix[i][j] -= minVal; 
                }
            }
        }
    }

    for(int j =0 ; j < n ; j++){
        int minVal = inf;
        for(int i = 0 ; i < n ; i++){
            if(costMatrix[i][j]<minVal){
                minVal = costMatrix[j][j];
            }
        }
        if(minVal!=inf){
            for(int i = 0 ; i < n ; i++){
                if(costMatrix[i][j]!=inf){
                    costMatrix[i][j] -= minVal; 
                }
            }
        }
    }

}


void bnb(vector<vector<int>>&costMatrix,int &minCost , int level , int pathLength , vector<int>&path , vector<int>&minPath){
    int n = costMatrix.size();
    if(level == n){
        pathLength += costMatrix[path[level-1]][path[0]];
        if(pathLength< minCost){
            minCost = pathLength;
            minPath = path;
        }
        return;
    }

    for(int i = 0 ; i < n ; i++){
        if(costMatrix[path[level-1]][i]!=inf){
            if(find(path.begin(),path.end,i)==path.end())
        }
    }
}