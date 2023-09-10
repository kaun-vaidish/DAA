/*
Given a value V and array coins[] of size M, the task is to make the change for V cents,
given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins.
find the minimum number of coins to make the change. If not possible to make change then return -1.

Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin*/


#include <bits/stdc++.h>
using namespace std;

class Solution{

	public:
	
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[M+1][V+1];
	    
	    for(int i = 0 ; i< M+1 ; i++){
	        dp[i][0] = 0;
	    }
	    for(int i = 1 ; i< V+1 ; i++){
	        dp[0][i] = INT_MAX-1;
	    }
	    
	    for(int i = 1 ; i< M+1 ; i++){
	        for(int j = 1 ; j < V+1 ; j++){
	            if(coins[i-1]<=j){
	                dp[i][j] = min(1+dp[i][j-coins[i-1]] , dp[i-1 ][j]);
	            }else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    if(dp[M][V] == INT_MAX-1){
	        return -1;
	    }else
	        return dp[M][V];
	} 
	  
};


int main() 
{

    int v, m;
    cin >> v >> m;

    int coins[m];
    for(int i = 0; i < m; i++)
        cin >> coins[i];

    
    Solution ob;
    cout << ob.minCoins(coins, m, v) << "\n";
        
    return 0;
}

