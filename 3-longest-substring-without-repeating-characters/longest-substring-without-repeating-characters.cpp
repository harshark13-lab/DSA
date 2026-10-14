#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];

            // If the character is already in the window, shift the left pointer 
            // to the right of the last seen occurrence of this character.
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
                left = charIndexMap[currentChar] + 1;
            }

            // Update the latest index of the current character
            charIndexMap[currentChar] = right;

            // Calculate the maximum length found so far
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};