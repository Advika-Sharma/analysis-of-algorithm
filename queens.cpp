#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printSolution(const vector<int>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i] == j ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<int>& board, int row, int col) {
    for (int prev_row = 0; prev_row < row; prev_row++) {
        if (board[prev_row] == col || abs(board[prev_row] - col) == abs(prev_row - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueensUtil(vector<int>& board, int row, int N) {
    if (row == N) {
        printSolution(board, N);
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueensUtil(board, row + 1, N);
        }
    }
}

void solveNQueens(int N) {
    vector<int> board(N, -1);
    solveNQueensUtil(board, 0, N);
}

int main() {
    int N;
    cin >> N;
    solveNQueens(N);
    return 0;
}
