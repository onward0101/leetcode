# 3. Longest Substring Without Repeating Characters
## Problem Link
[3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

## Problem Summary
給定一個字串 `s`，請找出其中不含重複字元的最長**連續子字串**長度。  
輸入可能為空字串，請考慮邊界情況。(某次提交錯誤)
## My Idea
<details>
  <summary>20250509</summary>

解法一
使用滑動視窗解法。用一個 `unordered_set` 儲存目前子字串中不重複的字元。
- 初始化 `left = 0`，遍歷 `right`：
  - 如果當前字元 `s[right]` 不在 set 中，加入它。
  - 如果已存在於 set 中，開始移動左指針 `left`，並從 set 中移除 `s[left]`，直到沒有重複字元。
- 每次都更新目前的最長長度。
解法二
一樣使用滑動窗口解法，只是使用`map<char, int>`來紀錄字元出現的次數
可讓處理重複字元更彈性（適用於可重複上限 > 1 的變體）。
</details>

## Code Summary 
1. solution1.cpp
- 使用 `unordered_set<char>` 記錄目前視窗內的字元。
- 左指針 `left` 表示滑動視窗的起點，右指針 `right` 遍歷字串。
- 每次當 `s[right]` 已經出現在 set 中，就移動 `left`，直到 `s[right]` 不在 set。
- 將`s[right]`加入set
- 每次更新視窗大小，並更新最大長度 `max_length`。
2. solution2.cpp
- 使用 `unordered_map<char, int>` 記錄目前視窗內的字元與出現次數。
- 左指針 `left` 表示滑動視窗的起點，右指針 `right` 遍歷字串。
- 將`s[right]`的出現次數+1
- 當 `s[right]` 出現次數>1，就移動 `left`，直到 `s[right]` 出現次數=1。
- 每次更新視窗大小，並更新最大長度 `max_length`。

## Time & Space Complexity
1. solution1.cpp
- Time: O(n)，每個字元最多進入與移除 set 一次
- Space: O(n)，最壞情況下所有字元都不同，set 大小為 n
1. solution2.cpp
- Time: O(n)，每個字元最多進入與離開 map 一次
- Space: O(n)，最壞情況下所有字元都不同，map 大小為 n
## Solution video
[靈神solution](https://www.bilibili.com/video/BV1hd4y1r7Gq?spm_id_from=333.788.player.switch&vd_source=016a3123e35bd83c9093c6fd0a78a044)