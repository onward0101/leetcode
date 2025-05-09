# 209. Minimum Size Subarray Sum
## Problem Link
[209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

## Problem Summary
給定一個正整數數列，以及一個目標值，找出最小長度的子數列，其和是>=target，如果沒有找到就返回0
## My Idea
<details>
  <summary>20250509</summary>

解法一
初始化左右端點，遍歷右端點，每次都加上當前的值，如果當前的值大於目標值，就開始減掉左端點的值，但同時也要注意要大於目標值。接著再與最小長度進行比較

</details>

## Code Summary 
1. solution1.cpp
- 使用`min_length` 紀錄目前找到的最小子陣列長度，初始值設為 `nums.size() + 1`
- 使用 `left` 表示左端點，遍歷 `right` 為右端點，維護滑動視窗
- 每次將 `nums[right]` 加入總和 `current_sum`
- 當 `current_sum >= target`，透過 while 迴圈收縮 `left`，直到總和小於 target 為止
- 每次找到有效子陣列時，更新 `min_length`
2. solution2.cpp
- 在`current_sum >= target` 時就更新答案
- 每次進入 while 迴圈時：
  - 更新最小長度
  - 收縮視窗左界（從 `left` 開始），並扣除相應的值
- Time: O(n)，每個元素最多被處理兩次（一次進，一次出）
- Space: O(1)

## Time & Space Complexity
1. solution1.cpp
  - Time:  O(n)，每個元素最多只被加入與移除一次（雙指針滑動）
  - Space: O(1)，只使用常數額外空間（不含輸入與輸出）

## Solution video
[靈神solution](https://www.bilibili.com/video/BV1hd4y1r7Gq?spm_id_from=333.788.player.switch&vd_source=016a3123e35bd83c9093c6fd0a78a044)