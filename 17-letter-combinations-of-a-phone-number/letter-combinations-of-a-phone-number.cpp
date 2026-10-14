#include <string>
#include <vector>

class Solution {
private:
    const std::vector<std::string> mapping = {
        "",     
        "",     
        "abc",  
        "def",  
        "ghi",  
        "jkl",  
        "mno",  
        "pqrs", 
        "tuv",  
        "wxyz"  
    };

    void backtrack(int index, const std::string& digits, std::string& currentStr, std::vector<std::string>& result) {
       
        if (index == digits.length()) {
            result.push_back(currentStr);
            return;
        }

        
        char digit = digits[index];
        std::string letters = mapping[digit - '0'];

        
        for (char letter : letters) {
            currentStr.push_back(letter);           
            backtrack(index + 1, digits, currentStr, result); 
            currentStr.pop_back();                 
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }
        
        std::string currentStr = "";
        backtrack(0, digits, currentStr, result);
        return result;
    }
};