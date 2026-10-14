#include <vector>
#include <string>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        int fact = 1;
        std::vector<int> numbers;
        
 
        for (int i = 1; i < n; ++i) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
 
        k--;
        std::string result = "";
        

        while (true) {
            int index = k / fact;
            result += std::to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            
            if (numbers.empty()) {
                break;
            }
            
            k %= fact;
            fact /= numbers.size();
        }
        
        return result;
    }
};