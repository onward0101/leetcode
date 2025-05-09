/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
            int current_max = 0;
            while (left < right){
                int area = (right - left) * min(height[left], height[right]);
                current_max = max(current_max, area);
                if (height[left] < height[right])
                    left++;
                else
                    right--;
            }
            return current_max;
        }
    };
// @lc code=end