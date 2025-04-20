// #include <bits/stdc++.h>
#include <iostream>

#include <vector>

#include <cmath>

using namespace std;

class Solution {
    bool isSafe(vector < vector < int >> & board, int row, int col, int k, int n) {
        for (int i = 0; i < n; i++) {
            if (board[i][col] == k || board[row][i] == k) return false;
        }

        int block = sqrt(n);
        int startRow = row - row % block;
        int startCol = col - col % block;

        for (int i = 0; i < block; i++) {
            for (int j = 0; j < block; j++) {
                if (board[startRow + i][startCol + j] == k) return false;
            }
        }

        return true;
    }

    bool solve(vector < vector < int >> & board, int n) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == 0) {
                    for (int k = 1; k <= n; k++) {
                        if (isSafe(board, row, col, k, n)) {
                            board[row][col] = k;
                            if (solve(board, n)) {
                                return true;
                            }
                            board[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    public:
        void sudokuSolver(vector < vector < int >> & board, int n) {
            solve(board, n);

            for (int i = 0; i < board.size(); i++) {
                for (auto j: board[i]) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    // your code goes here
    int n = 4;
    vector < vector < int >> board(n, vector < int > (n, 0));
    Solution obj;
    obj.sudokuSolver(board, n);
}