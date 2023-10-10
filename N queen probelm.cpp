#include <iostream>
#include <vector>
using namespace std;

#include <bits/stdc++.h>


class Solution {
public:

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
};

int main() {
    Solution solution;
    int n = 4; //number of queen , ca =n be , n=1 , n=8
    vector<vector<string>> result = solution.solveNQueens(n);

    // Display the result
    for (const auto& solution : result) {
        for (const auto& row : solution) {
            cout << row << "\t"<<endl;
        }
        cout << "-   -    -   -   -   -" << endl;
    }

    return 0;
}
