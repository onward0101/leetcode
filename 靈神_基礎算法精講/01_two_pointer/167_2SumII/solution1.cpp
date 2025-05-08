/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int left = 0;
            int right = numbers.size() - 1;
            while(left < right){
                int result = numbers[left] + numbers[right] ;
                if (target > result)
                    left++;
                else if (target < result)
                    right--;
                else
                    return {left + 1, right + 1};
            }
            return {-1, -1};
        }
    };
// @lc code=end