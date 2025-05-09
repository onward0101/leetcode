# 42. Trapping Rain water
## Problem Link
[42. Trapping Rain water](https://leetcode.com/problems/trapping-rain-water/description/)

## Problem Summary
給定 n 個非負整數，代表柱子高度，寬度皆為 1。  
請計算下雨後整個海拔圖可以接住多少單位的雨水。
## My Idea
<details>
  <summary>20250509</summary>

解法一(使用輔助陣列)

每個位置可以接多少水，取決於「左邊最大高度」與「右邊最大高度」兩者的最小值減去當前高度。  
- 建立兩個陣列：`prefix_max` 與 `postfix_max`，分別記錄從左到右、從右到左的最大高度。
- 接著遍歷每個位置，計算可接水量並加總

解法二(雙指針 + 常數空間)
- 若左邊最大值 < 右邊最大值，說明可以確定左邊可以接水，並移動左指針。
- 反之則移動右指針。
- 每一步都加上當前位置的可接水量。
</details>

## Code Summary 
1. solution1.cpp
- 使用兩個陣列：
  - `prefix[i]`：從左到第 i 根柱子的最大高度
  - `postfix[i]`：從右到第 i 根柱子的最大高度
- 每個位置能接的水為：`min(prefix[i], postfix[i]) - height[i]`
- 遍歷整個陣列，把每個位置能接的水加總起來
2. solution2.cpp
- 用兩個變數分變儲存前綴最大值以及後綴最大值
- 如果前綴最大值比後綴最大值小，左邊桶子的容量就是前綴最大值-當前高度，如果後綴最大值比前綴最大值小，右邊桶子的容量就是後綴最大值-當前高度
- 遍歷整個陣列，把每個位置能接的水加總起來

## Time & Space Complexity
1. solution1.cpp
  - Time:  O(n)，需要遍歷兩次計算最大高度，再遍歷一次計算總雨水量
  - Space: O(n)，額外使用兩個長度為 n 的陣列
2. solution2.cpp
  - Time:  O(n)，每個位置最多處理一次
  - Space: O(1)，只使用固定的變數

## Solution video
[靈神solution](https://www.bilibili.com/video/BV1Qg411q7ia/?spm_id_from=333.1391.0.0&vd_source=016a3123e35bd83c9093c6fd0a78a044)