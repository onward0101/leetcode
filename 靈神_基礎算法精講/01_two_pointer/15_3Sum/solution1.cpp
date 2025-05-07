/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> ans;
            sort(nums.begin(), nums.end());
            int n = nums.size();
            for (int i = 0 ; i < n - 2 ; i++){
                if (i > 0 && nums[i] == nums[i-1]) continue;
                if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break; 
                if (nums[i] + nums[n - 1] + nums[n - 2] < 0) continue;
                int target = nums[i];
                int left = i + 1 ;
                int right = n - 1;
                while (left < right){
                    if (target + nums[left] + nums[right] < 0)
                        left++;
                    else if (target + nums[left] + nums[right] > 0)
                        right--;
                    else{
                        ans.push_back({target, nums[left], nums[right]});
                        left++;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        right--;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                }
            }
            return ans;
        }
    };
// @lc code=end