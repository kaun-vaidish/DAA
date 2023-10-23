#include<bits/stdc++.h>
using namespace std;

bool isSafe( vector<string>&board ,  int row , int column , int n ){

    int tempRow = row;
    int tempCol = column;

    while(row>=0 && column>=0){
        if(board[row][column] == 'Q'){
            return false;
        }
        row--;
        column--;
    }

    row = tempRow;
    column = tempCol;
    while(column>=0){
        if(board[row][column] == 'Q'){
            return false;
        }
        column--;
    }

    row = tempRow;
    column = tempCol;
    while(row<n && column>=0){
        if(board[row][column] == 'Q'){
            return false;
        }
        row++;
        column--;
    }

    return true;
}

void solve(vector<vector<string>>&result , vector<string>&board , int n , int column){
    if(column == n){
        result.push_back(board);
        return;
    }

    for(int row = 0 ; row < n ; row++){
        if(isSafe(board,row,column,n)){
            board[row][column] = 'Q';
            solve(result,board,n,column+1);
            board[row][column] = '.';
        }
    }
}

vector<vector<string>> Nqueen(int n){
    vector<vector<string>> result;
    vector<string>board(n,string(n,'.'));
    solve(result , board , n , 0);
    return result;
}

int main(){
    int n ;
    cout<<"Enter no. of queen : ";
    cin>>n;
    vector<vector<string>>ans = Nqueen(n);

    for(int i = 0 ; i < ans.size();i++){
        vector<string>solution = ans[i];
        for(int j = 0 ; j < solution.size(); j++){
            cout<<solution[j]<<endl;
        }
        cout<<"-   -   -   -   -   -   "<<endl;
    }
}