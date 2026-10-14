#include <vector>
#include <string>
#include <unordered_set>

class Solution {
private:
    void backtrack(int row, int n, std::vector<std::string>& board, 
                   std::vector<std::vector<std::string>>& result,
                   std::unordered_set<int>& cols, 
                   std::unordered_set<int>& diag1, 
                   std::unordered_set<int>& diag2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col; // Main diagonal identifier
            int d2 = row + col; // Anti-diagonal identifier

            // Check if column or diagonals are already occupied
            if (cols.count(col) || diag1.count(d1) || diag2.count(d2)) {
                continue;
            }

            // Place queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(d1);
            diag2.insert(d2);

            // Move to the next row
            backtrack(row + 1, n, board, result, cols, diag1, diag2);

            // Remove queen (backtrack)
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(d1);
            diag2.erase(d2);
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> board(n, std::string(n, '.'));
        std::unordered_set<int> cols;
        std::unordered_set<int> diag1;
        std::unordered_set<int> diag2;

        backtrack(0, n, board, result, cols, diag1, diag2);
        return result;
    }
};