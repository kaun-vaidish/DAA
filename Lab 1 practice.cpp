#include<bits/stdc++.h>
using namespace std;

struct item{
    int weight;
    int profit;
    float pw;
    float fraction;
};


void fractional(item items[],int n , int capacity){
    
    int profit = 0;
    int remaining_capacity = capacity;

    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(items[i].pw > items[j].pw){
                // swap(items[i],items[j]);
                int temp = items[i].weight;
                items[i].weight = items[j].weight;
                items[j].weight = temp;

                temp = items[i].profit;
                items[i].profit = items[j].profit;
                items[j].profit = temp;

            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(items[i].weight<=remaining_capacity){
            items[i].fraction = 1;
            remaining_capacity -= items[i].weight;
            profit += items[i].profit;
        }else{
            items[i].fraction = float(remaining_capacity)/float(items[i].weight);
            remaining_capacity -= items[i].fraction*items[i].weight;
            profit += items[i].fraction*items[i].profit;
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout<<"Item "<< i+1 << " : " << items[i].fraction<<endl; 
    }

    for(int i = 0 ; i < n ; i++){
        cout<<items[i].weight<<" "<<items[i].profit<<" "<<items[i].fraction<<" "<<endl;
    }

    cout<<"Profit : "<<profit<<endl;
    cout<<"Capacity : "<<capacity-remaining_capacity<<endl;
}

void dynamic(item items[] , int n , int capacity){

    int remaining_capacity = capacity;

    int dp[n+1][capacity+1];
    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < capacity+1 ; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 1 ; i < n+1 ; i++){
        for(int j = 1 ; j < capacity+1 ; j++){
            if(items[i-1].weight <= j){
                dp[i][j] = max( dp[i-1][j] , dp[i-1][j-items[i-1].weight]+items[i-1].profit );
                // profit += items[i-1].profit;
                
                items[i-1].fraction = 1;
            }else{
                dp[i][j] = dp[i-1][j];
                items[i-1].fraction = 0;
            }
        }
    }

    for(int i = 0 ; i < n+1 ; i++){
        for(int j = 0 ; j < capacity+1 ; j++){
            cout<<dp[i][j]<<"     ";
        }
        cout<<endl;
    }

    cout<<"Profit : "<<dp[n][capacity]<<endl;
}

int main(){
    int n;
    cout<<"Enter number of items : ";
    cin>>n;
    int capacity;
    cout<<"Enter capacity of knapsack : ";
    cin>>capacity;

    item items[n];

    for(int i = 0 ; i < n ; i++){
        cout<<"Enter weight of item : ";
        cin>>items[i].weight;
        cout<<"Enter profit of item : ";
        cin>>items[i].profit;

        items[i].pw = float(items[i].profit)/float(items[i].weight);
    }

    dynamic(items,n,capacity);

    
}
