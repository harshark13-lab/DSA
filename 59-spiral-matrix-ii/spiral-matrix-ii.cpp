#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            // 1. Fill from Left to Right along the Top row
            for (int col = left; col <= right; ++col) {
                matrix[top][col] = num++;
            }
            top++;

            // 2. Fill from Top to Bottom along the Right column
            for (int row = top; row <= bottom; ++row) {
                matrix[row][right] = num++;
            }
            right--;

            // 3. Fill from Right to Left along the Bottom row
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    matrix[bottom][col] = num++;
                }
                bottom--;
            }

            // 4. Fill from Bottom to Top along the Left column
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    matrix[row][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};