using namespace std;
#include <bits/stdc++.h>


bool isSafe(int row, int col, const vector<string>& board, int n) {
    int temprow = row;
    int tempcol = col;

    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }

    row = temprow;
    col = tempcol;

    while (col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }

        col--;
    }

    row = temprow;
    col = tempcol;

    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));  // Initialize board with n x n dots

    solve(0, board, ans, n);
    return ans;
}


int main() {
    
    int n ; //number of queen , ca =n be , n=1 , n=8
    cout<<"Enter number of queens : ";
    cin>>n;
    vector<vector<string>> result = solveNQueens(n);

    // Display the result
    for (int i = 0; i < result.size(); i++) {
        vector<string> solution = result[i];
        for (int j = 0; j < solution.size(); j++) {
            // string row = solution[j];
            cout << solution[j] << "\t" << endl;
        }
        cout <<endl<< "-   -    -   -   -   -" << endl;
    }
    return 0;
}
