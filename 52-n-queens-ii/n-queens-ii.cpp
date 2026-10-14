#include <unordered_set>

class Solution {
private:
    void backtrack(int row, int n, int& count, 
                   std::unordered_set<int>& cols, 
                   std::unordered_set<int>& diag1, 
                   std::unordered_set<int>& diag2) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col; // Main diagonal identifier
            int d2 = row + col; // Anti-diagonal identifier

            // Check if column or diagonals are already occupied
            if (cols.count(col) || diag1.count(d1) || diag2.count(d2)) {
                continue;
            }

            // Place queen and mark paths
            cols.insert(col);
            diag1.insert(d1);
            diag2.insert(d2);

            // Move to the next row
            backtrack(row + 1, n, count, cols, diag1, diag2);

            // Remove queen (backtrack)
            cols.erase(col);
            diag1.erase(d1);
            diag2.erase(d2);
        }
    }

public:
    int totalNQueens(int n) {
        int count = 0;
        std::unordered_set<int> cols;
        std::unordered_set<int> diag1;
        std::unordered_set<int> diag2;

        backtrack(0, n, count, cols, diag1, diag2);
        return count;
    }
};