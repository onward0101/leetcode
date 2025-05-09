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
            vector<int> prefix(n, 0);
            vector<int> postfix(n, 0);
            prefix[0] = height[0];
            postfix[n - 1] = height[n - 1];
            for (int i = 1; i < n ; i++){
                prefix[i] = max(prefix[i - 1], height[i]);
                postfix[n - i - 1] = max(postfix[n - i], height[n - i - 1]);
            }
    
            int area = 0;
            for (int i = 0 ; i < n ; i++){
                area += (min(prefix[i], postfix[i]) - height[i]);
            }
            
            return area;
        }
    };
// @lc code=end