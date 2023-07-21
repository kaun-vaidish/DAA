#include<iostream>
using namespace std;



void prntarr(int arr[],int n){
    for (int i = 0 ; i <n;i++ ){
        cout<<arr[i]<<" ";
    }
}

void prntrec(int arr[],int n){
   if(n>0){
    prntrec(arr,n-1);
    cout<<arr[n-1];    
    
   }
  
}

void prntrecreverse(int arr[],int n){
    if(n>0){
    cout<<arr[n-1];  
    prntrecreverse(arr,n-1);    
   }
}

int main(){
    cout<<"Enter length of array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }
  
    //prntrec(arr,n);
    prntrecreverse(arr,n);
}