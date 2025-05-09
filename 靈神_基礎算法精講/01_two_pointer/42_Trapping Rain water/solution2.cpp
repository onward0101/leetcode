/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain water
 */

// @lc code=start
class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            int prefix_max = 0;
            int postfix_max = 0;
            int left = 0;
            int right = n - 1;
            int area = 0;
            while (left <= right){
                prefix_max = max(prefix_max, height[left]);
                postfix_max = max(postfix_max, height[right]);
                if (prefix_max < postfix_max){
                    area += (prefix_max - height[left]);
                    left++;
                } else {
                    area += (postfix_max - height[right]);
                    right--;    
                }
            }
            
            return area;
        }
    };
// @lc code=end