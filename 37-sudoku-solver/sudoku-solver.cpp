#include <vector>

class Solution {
private:
    bool isValid(std::vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            // Check row
            if (board[row][i] == c) return false;
            // Check column
            if (board[i][col] == c) return false;
            // Check 3x3 sub-box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }

    bool solve(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; // Place candidate

                            if (solve(board)) {
                                return true; // Found a valid solution
                            }

                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // Trigger backtracking if no number fits
                }
            }
        }
        return true; 
    }

public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }
};