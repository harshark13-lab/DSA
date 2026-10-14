#include <string>
#include <vector>

class Solution {
private:
    void backtrack(std::string current, int openCount, int closeCount, int n, std::vector<string>& result) {

        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }


        if (openCount < n) {
            backtrack(current + '(', openCount + 1, closeCount, n, result);
        }

 
        if (closeCount < openCount) {
            backtrack(current + ')', openCount, closeCount + 1, n, result);
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack("", 0, 0, n, result);
        return result;
    }
};