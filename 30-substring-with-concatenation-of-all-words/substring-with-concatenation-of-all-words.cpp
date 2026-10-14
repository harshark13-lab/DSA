#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;

        if (s.length() < totalLen) return result;

 
        std::unordered_map<std::string, int> wordMap;
        for (const std::string& word : words) {
            wordMap[word]++;
        }


        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            std::unordered_map<std::string, int> seenMap;
            int count = 0;

            while (right + wordLen <= s.length()) {
                std::string sub = s.substr(right, wordLen);
                right += wordLen;

    
                if (wordMap.find(sub) != wordMap.end()) {
                    seenMap[sub]++;
                    count++;

                    while (seenMap[sub] > wordMap[sub]) {
                        std::string leftSub = s.substr(left, wordLen);
                        seenMap[leftSub]--;
                        left += wordLen;
                        count--;
                    }

                 
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                 
                    seenMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};