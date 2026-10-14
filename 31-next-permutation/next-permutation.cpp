#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: Find the first decreasing element from the right
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no such element exists, the permutation is the last one; reverse the whole array to get the lowest
        if (pivot == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the element just larger than nums[pivot] from the right
        int successor = -1;
        for (int i = n - 1; i > pivot; --i) {
            if (nums[i] > nums[pivot]) {
                successor = i;
                break;
            }
        }

        // Step 3: Swap the pivot and the successor
        std::swap(nums[pivot], nums[successor]);

        // Step 4: Reverse the suffix starting right after the pivot to get the smallest lexicographical order
        std::reverse(nums.begin() + pivot + 1, nums.end());
    }
};