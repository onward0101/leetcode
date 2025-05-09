# 713. Subarray Product Less Than K
## Problem Link
[713. Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/)

## Problem Summary
給定一個正整數陣列 `nums` 和整數 `k`，找出所有「乘積嚴格小於 `k`」的**連續子陣列**個數。
## My Idea
<details>
  <summary>20250509</summary>
使用滑動視窗解法。由於是「乘積小於 k」，我們用一個變數 `prod` 維護目前視窗內的乘積。
  - 將 `nums[right]` 乘進 `prod`
  - 當 `prod >= k` 時，收縮左邊界，並除掉 `nums[left]`，直到 `prod < k`
- 每次當視窗合法（`prod < k`）時，表示從 `left` 到 `right` 有 `(right - left + 1)` 個子陣列符合條件

</details>

## Code Summary 
1. solution1.cpp
- 使用變數 `left` 表示滑動視窗左端，`prod` 表示目前視窗內乘積
- 遍歷右端點 `right`：
  - 將 `nums[right]` 乘進 `prod`
  - 如果 `prod >= k`，代表視窗不合法，開始移動 `left`，並除掉 `nums[left]`
- 每次當 `prod < k` 時，將 `(right - left + 1)` 加進答案中，代表這段視窗中的所有子陣列都符合條件

## Time & Space Complexity
1. solution1.cpp
  - Time:  O(n)，每個元素最多進出滑動視窗一次
  - Space: O(1)，僅使用變數 `prod`, `left`, `ans`

## Solution video
[靈神solution](https://www.bilibili.com/video/BV1hd4y1r7Gq?spm_id_from=333.788.player.switch&vd_source=016a3123e35bd83c9093c6fd0a78a044)