# 11. Container With Most Water
## Problem Link
[11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/description/)

## Problem Summary
給定一組非負整數，代表每根柱子的高度。
選擇兩根柱子構成容器，其容量為 較短柱子的高度 x 兩者之間距離
請找出可容納最多水的容器容量。
## My Idea
<details>
  <summary>20250509</summary>
當前容器的容量是由兩根柱子較短的那根乘上他們之間的距離。因此，先定義一個變數儲存當前的最大值，接著令left 指針指向第一根柱子，right指針指向最後一根柱子。
在left < right 的情況下，首先計算當前的面積，並且與當前最大值進行比較，之後移動較短的那根柱子，因為面積與較短的那根有關。
</details>

## Code Summary (solution1.cpp)
- 使用雙指針：left 從開頭、right 從結尾。
- 每次計算面積：`(right - left) * min(height[left], height[right])`
- 更新最大值。
- 移動高度較短的那一端，因為面積由短邊限制。

## Time & Space Complexity
- Time:  O(n)，雙指針
- Space: O(1)

## Solution video
[靈神solution](https://www.bilibili.com/video/BV1Qg411q7ia/?spm_id_from=333.1391.0.0&vd_source=016a3123e35bd83c9093c6fd0a78a044)