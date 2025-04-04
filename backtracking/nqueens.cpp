#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<string>> solutions;

    bool isSafe(vector<string>& board, int row, int col, int n){
        // check vertical direction
        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // left upper diagonal

        for(int i=row-1, j=col-1; i >=0 && j>= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // right upper diagonal

        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }

    void solve(vector<string>& board, int n, int row){
        if(row == n){
            // if all the rows are explored push the solution in the solutions
            solutions.push_back(board);
            return;
        }

        for(int col=0; col<n; col++){
            // check if the current position is safe to place the queen
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q'; // placing the queen on [row][col]
                solve(board, n, row+1); // recursively increasing the row
                board[row][col] = '.'; // backtrack
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.')); // initializing the board with size of n with '.'
        solve(board, n, 0);
        return solutions;
    }
    
    void printSolutions() {
        for(int i=0; i<solutions.size(); i++){
            for(auto row: solutions[i]){
                cout << row << ", ";
            }
            cout << endl;
        }
    }
};

int main () {
    int n = 4;
    Solution nQueens;
    nQueens.solveNQueens(n);
    nQueens.printSolutions();
    return 0;
}