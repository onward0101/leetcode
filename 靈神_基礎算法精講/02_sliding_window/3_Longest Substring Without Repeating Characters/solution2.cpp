/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            map<char, int> hash;
            int max_length = 0;
            int left = 0;
            for (int right = 0 ; right < s.length() ; right++){
                hash[s[right]]++;
                while(hash[s[right]] > 1){
                    hash[s[left]]--;
                    left++;
                }
                max_length = max(max_length, right - left + 1);
            }
            return max_length;
        }
    };
// @lc code=end