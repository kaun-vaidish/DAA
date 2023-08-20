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

class Solution
{
    public:
    int t[101][1002];
    Solution(){
        memset(t,-1,sizeof(t));
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        if(n==0||W==0){
            return 0;
        }
        
        if(t[n][W]!=-1){
            return t[n][W];
        }
        
        if(wt[n-1]<=W){
            return t[n][W] = max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
        }
        else{
            return t[n][W] = knapSack(W,wt,val,n-1);
        }
    }
};
int main()
 {
    //reading number of elements and weight
    int n, w;
    cin>>n>>w;
    
    int val[n];
    int wt[n];
    
    //inserting the values
    for(int i=0;i<n;i++)
        cin>>val[i];
    
    //inserting the weights
    for(int i=0;i<n;i++)
        cin>>wt[i];
    Solution ob;
    //calling method knapSack()
    cout<<ob.knapSack(w, wt, val, n)<<endl;
    

	return 0;
}
