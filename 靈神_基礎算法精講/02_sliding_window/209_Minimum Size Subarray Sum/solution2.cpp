/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int min_length = nums.size() + 1;
            int left = 0;
            int current_sum = 0;
            for (int right = 0 ; right < nums.size() ; right++){
                current_sum += nums[right];
                while(current_sum >= target){
                    min_length = min(min_length, right-left+1);
                    current_sum -= nums[left];
                    left++;
                }      
            }
    
            return min_length == nums.size() + 1 ? 0 : min_length;
        }
    };
// @lc code=end