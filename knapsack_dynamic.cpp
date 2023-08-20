#include<iostream>
using namespace std;

class Item{
    public:
    int profit;
    int weight;
};

int max(int a , int b){
    if(a>b)
    return a;
    else 
    return b;
}

void bubbleSort(Item arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j].weight>arr[j+1].weight)
            {                
                Item temp=arr[j+1];                    
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void knapsack(int n , int w ,Item arr[]){

    int maxprof[n+1][w+1];
    // for(int i = 0 ; i < n+1 ; i++){
    //     maxprof[i][0] = 0;
    // }
    
    // for(int j = 0 ;  j< w+1; j++){
    //     maxprof[0][j] = 0;
    // }
    
    for(int i = 0 ; i<n+1; i++){
        for(int j = 0 ; j< w+1 ; j++){
            if(i ==0 || j ==0)
            maxprof[i][j]=0;
            else
            maxprof[i][j] = max(maxprof[i-1][j], (maxprof[i-1][j-arr[i-1].weight ]+arr[i-1].profit));
        }
    }

    //return maxprof[n+1][w+1];
    for(int i = 0 ; i<n+1; i++){
        for(int j = 0 ; j< w+1 ; j++){
            cout<<maxprof[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter number of items in knapsack :";
    cin>>n;

    int w ;
    cout<<"Enter maximum weight capacity of knapsack :";
    cin>>w;

    Item arr[n];

    for(int i = 0 ; i<n ; i++){
        cout<<"Enter profit on "<<i+1<<"th item"<<endl;
        cin>>arr[i].profit;
        cout<<"Enter weight of "<<i+1<<"th item"<<endl;
        cin>>arr[i].weight;
    }

    bubbleSort(arr,n);
    // for(int i =0 ; i<n ; i++){
    //     cout<<arr[i].weight<<" "<<arr[i].profit<<endl;
    // }

    //cout<<"maximum rpofit is :"<<knapsack(n,w,arr);
    knapsack(n,w,arr);
}