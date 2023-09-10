/*
Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Explanation: Choose the last item that weighs 1 unit and holds a value of 3. 
*/

#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[],int wt[],int W,int n){

    int t[n][W];

    for(int i = 0 ; i< n+1 ; i++){
        t[i][0] = -1;
    }
    for(int i = 0 ; i < W+1;i++){
        t[0][W] = 0;
    }

    for(int i = 1 ; i< n+1 ; i++){
        for(int j = 1; j<W+1 ; j++){
            if(wt[i-1]<=W){
                t[i][j] = max((val[i-1]+t[i-1][W-wt[i-1]]) ,( t[i-1][W]));
            }else{
                t[i][j] = t[n-1][W];
            }
        }
    }

}

int main()
 {
    
    int n, w;
    cin>>n>>w;
    
    int val[n];
    int wt[n];
    
    for(int i=0;i<n;i++)
        cin>>val[i];
    
    for(int i=0;i<n;i++)
        cin>>wt[i];
    
    
    cout<<knapsack( val,wt, w, n)<<endl;
    

	return 0;
}
