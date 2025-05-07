# 15. 3Sum
## Problem Link
[15. 3sum](https://leetcode.com/problems/3sum/description/)

## Problem Summary
找到數列的任三個數的和是0，並且不能包含重複的pair.
## My Idea
<details>
  <summary>20250508</summary>
- 首先，將整個數列進行排序，接著從排序好的數列中，從頭開始遍歷到倒數第三個元素。  
left 指針指向 i + 1，right 指針指向 n - 1。  
之後以 left < right 的條件下，開始去尋找三數的和是否 = 0。  
>0 的話就將右指針左移，< 0 的話就將左指針右移，= 0 的話就將答案存下來，並且移動左右指針。此外，為了避免重複，可以使用 while 迴圈跳過相同值。
</details>

## Troubles
1. 沒有考慮到會有重複的pair
2. left 以及right 重複的時候的判斷放錯位置
3. for 的範圍錯誤(n - 2)

## Code Summary (solution1.cpp)
- 對 `nums` 排序。
- 固定一個數 `i`，用雙指針找出 `nums[i] + nums[left] + nums[right] == 0` 的組合。
- 為避免重複：
  - 跳過重複的 `i`。
  - 找到解後，左右指針跳過重複值。
- 為了提早退出：
  - 若最小三數和已 > 0，跳出。
  - 若最大三數和 < 0，略過當前 `i`。

## Time & Space Complexity
- Time: O(nlogn)，排序 O(n log n) + 雙指針 O(n)
- Space: O(1)，不含答案輸出空間

## Solution video
[靈神solution](https://www.bilibili.com/video/BV1bP411c7oJ/?spm_id_from=333.1391.0.0&vd_source=016a3123e35bd83c9093c6fd0a78a044)