/*
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
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        if(n==0||W==0){
            return 0;
        }
        
        if(wt[n-1]<=W){
            return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
        }
        else{
            return knapSack(W,wt,val,n-1);
        }
    }
};

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
    Solution ob;
    
    cout<<ob.knapSack(w, wt, val, n)<<endl;
    

	return 0;
}
