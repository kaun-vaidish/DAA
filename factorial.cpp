#include<iostream>
using namespace std;

void factorial(int n){
    int a = 1;
    for(int i = 1 ; i< n+1;i++){
        a = a*i;
    }
    cout<<a;
}

int factrec(int n){
    if(n>1){   
        return n*factrec(n-1);
    }else{
        return 1 ;
    }
    
}

int main(){
    //factorial(5);
    cout<<factrec(4);
}