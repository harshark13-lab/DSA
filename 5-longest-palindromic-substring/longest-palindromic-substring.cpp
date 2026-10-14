#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Find the longest palindrome with a single character center (odd length)
            int len1 = expandAroundCenter(s, i, i);
            // Find the longest palindrome with a two-character center (even length)
            int len2 = expandAroundCenter(s, i, i + 1);

            int currentLen = std::max(len1, len2);

            if (currentLen > maxLength) {
                maxLength = currentLen;
                // Update the starting index of the longest palindrome found
                start = i - (currentLen - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }

private:
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }
};