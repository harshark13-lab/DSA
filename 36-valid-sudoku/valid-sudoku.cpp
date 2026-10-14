#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_set<std::string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char current = board[i][j];
                if (current == '.') {
                    continue;
                }

                std::string rowStr = std::string(1, current) + " in row " + std::to_string(i);
                std::string colStr = std::string(1, current) + " in col " + std::to_string(j);
                std::string boxStr = std::string(1, current) + " in box " + std::to_string(i / 3) + "-" + std::to_string(j / 3);

                if (seen.count(rowStr) || seen.count(colStr) || seen.count(boxStr)) {
                    return false;
                }

                seen.insert(rowStr);
                seen.insert(colStr);
                seen.insert(boxStr);
            }
        }

        return true;
    }
};