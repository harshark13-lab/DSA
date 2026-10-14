#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        if (n == 1) return "1";

        std::string current = "1";

        for (int i = 2; i <= n; ++i) {
            std::string next = "";
            int len = current.length();
            
            for (int j = 0; j < len; ++j) {
                int count = 1;
               
                while (j + 1 < len && current[j] == current[j + 1]) {
                    count++;
                    j++;
                }
            
                next += std::to_string(count) + current[j];
            }
            current = next;
        }

        return current;
    }
};