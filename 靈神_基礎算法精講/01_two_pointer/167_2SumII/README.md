# 167. Two Sum II - Input Array Is Sorted
## Problem Link
[167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)

## Problem Summary
給定一個升序排列的整數陣列和一個目標值，請找出兩個數字，使它們的和等於目標值，並回傳它們的 1-indexed 下標。假設只有唯一一組解，且不允許使用額外空間（O(1)）。
## My Idea
<details>
  <summary>20250508</summary>
- left 指針指向 0，right 指針指向 n - 1。  
之後以 left < right 的條件下，開始去尋找兩數的和是否 = target。  
>target 的話就將右指針左移，< target 的話就將左指針右移，= target 的話就返回{left+1, right+1}，因為是1-indexed
</details>

## Code Summary
- 使用雙指針：left 從開頭、right 從結尾開始。
- 當兩數和小於 target，left++；若大於 target，right--。
- 若等於 target，回傳 {left + 1, right + 1}。

## Time & Space Complexity
- Time: O(n)，因為最多每個元素檢查一次。
- Space: O(1)，只用常數額外空間。

## Solution video
[靈神solution](https://www.bilibili.com/video/BV1bP411c7oJ/?spm_id_from=333.1391.0.0&vd_source=016a3123e35bd83c9093c6fd0a78a044)