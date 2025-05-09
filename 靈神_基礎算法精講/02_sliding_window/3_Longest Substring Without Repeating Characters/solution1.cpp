/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> hash;
            int max_length = 0;
            int left = 0;
            for (int right = 0 ; right < s.length() ; right++){
                while(left < right && hash.find(s[right]) != hash.end()){
                    hash.erase(s[left]);
                    left++;
                }
                hash.insert(s[right]);
                max_length = max(max_length, right - left + 1);
            }
            return max_length;
        }
    };
// @lc code=end