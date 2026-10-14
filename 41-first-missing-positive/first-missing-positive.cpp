#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();

        // Step 1: Replace any numbers <= 0 or > n with a number out of range (like n + 1)
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Step 2: Use the index as a hash key by marking the value at index (nums[i] - 1) as negative
        for (int i = 0; i < n; ++i) {
            int val = std::abs(nums[i]);
            if (val >= 1 && val <= n) {
                int idx = val - 1;
                if (nums[idx] > 0) {
                    nums[idx] = -nums[idx]; // Mark as visited
                }
            }
        }

        // Step 3: The first index with a positive value indicates the missing positive integer
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        // If all numbers from 1 to n are present, the answer is n + 1
        return n + 1;
    }
};