#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            // If the current index cannot be reached, we can't go any further
            if (i > maxReach) {
                return false;
            }
            // Update the furthest index we can reach from the current position
            maxReach = std::max(maxReach, i + nums[i]);
            
            // Optimization: if we can already reach or exceed the last index, return true
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }
        
        return true;
    }
};