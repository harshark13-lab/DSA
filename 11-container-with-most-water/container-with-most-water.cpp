#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {

            int width = right - left;
            int currentHeight = std::min(height[left], height[right]);
            
 
            maxWater = std::max(maxWater, width * currentHeight);


            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};