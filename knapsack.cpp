#include<iostream>
using namespace std;

class Item{
    public:
    int profit;
    int weight;
    float pw;
};

void bubbleSort(Item arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j].pw<arr[j+1].pw)
            {                
                Item temp=arr[j+1];                    
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

float knapsack(Item arr[],int n , float total_weight){
    float total_profit = 0.0;
    float remaining_weight = total_weight;
    for(int i = 0 ; i<n ; i++){
        if(arr[i].weight<=remaining_weight){
            remaining_weight-=arr[i].weight;
            total_profit+=arr[i].profit;
        }else{
            total_profit+=arr[i].profit*(remaining_weight/arr[i].weight);
            break;
        }
    }
    return total_profit;
}

int main(){
    int n;
    cout<<"Enter number of items in knapsack :";
    cin>>n;

    int total_weight ;
    cout<<"Enter maximum weight capacity of knapsack :";
    cin>>total_weight;
    
    Item arr[n];
    for(int i = 0 ; i<n ; i++){
        cout<<"Enter profit on "<<i+1<<"th item"<<endl;
        cin>>arr[i].profit;
        cout<<"Enter weight of "<<i+1<<"th item"<<endl;
        cin>>arr[i].weight;
        arr[i].pw=float(arr[i].profit)/float(arr[i].weight);
    }

    bubbleSort(arr,n);   
    cout<<"Maximum possible profit is :"<<knapsack(arr,n,total_weight);   
}