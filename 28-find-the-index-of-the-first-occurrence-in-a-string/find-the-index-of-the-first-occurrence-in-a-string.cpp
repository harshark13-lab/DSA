#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (m > n) return -1;

        // Slide the window of length m over haystack
        for (int i = 0; i <= n - m; ++i) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }

        return -1;
    }
};