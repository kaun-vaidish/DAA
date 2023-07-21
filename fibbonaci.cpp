#include<iostream>
using namespace std;

void nonrecursive(){
     int a = 0;
    int  b = 1;
    cout<<a<<" ";
    cout<<b<<" ";
    while(b<100){        
        int sum = a+b;
        cout<<sum<<" ";
        a = b;
        b = sum;
    }
}

void recursive(int a , int b){
    
    if(b<100){
        int sum = a+b;
        a = b;
        b = sum;
        cout<<sum<<" ";
        recursive(a,b);
    }else{
        return;
    }
}

int main(){
   //nonrecursive();
    cout<<"0 1 ";
    recursive(0,1);

}