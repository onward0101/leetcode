# Sliding Window 題型

## 通用模板

適用於大多數連續子陣列/子字串處理：

```cpp
int left = 0;
for (int right = 0; right < s.size(); right++) {
    // 擴大視窗，處理右端點
    ...

    // 如果不合法，收縮左端點
    while (條件不合法) {
        ... // 移除左端點的效果
        left++;
    }

    // 更新答案
    ...
}
```

---

## 題型分類與範例

### 1. 固定條件限制（總和/乘積）

#### Leetcode 209. Minimum Size Subarray Sum

> 找出最短子陣列長度，使其總和 ≥ target

```cpp
int current_sum = 0, min_length = INT_MAX, left = 0;
for (int right = 0; right < nums.size(); right++) {
    current_sum += nums[right];
    while (current_sum >= target) {
        min_length = min(min_length, right - left + 1);
        current_sum -= nums[left++];
    }
}
```

#### Leetcode 713. Subarray Product Less Than K

> 子陣列乘積 < k 的個數

```cpp
int prod = 1, left = 0, ans = 0;
for (int right = 0; right < nums.size(); right++) {
    prod *= nums[right];
    while (prod >= k && left <= right) {
        prod /= nums[left++];
    }
    ans += (right - left + 1);
}
```

---

### 2. 無重複元素（唯一性）

#### Leetcode 3. Longest Substring Without Repeating Characters

```cpp
unordered_set<char> seen;
int left = 0, max_length = 0;
for (int right = 0; right < s.length(); right++) {
    while (seen.count(s[right])) {
        seen.erase(s[left++]);
    }
    seen.insert(s[right]);
    max_length = max(max_length, right - left + 1);
}
```

---

### 3. 最多/恰好 K 種元素

#### Leetcode 340. Longest Substring with At Most K Distinct Characters

```cpp
unordered_map<char, int> freq;
int left = 0;
for (int right = 0; right < s.size(); right++) {
    freq[s[right]]++;
    while (freq.size() > K) {
        freq[s[left]]--;
        if (freq[s[left]] == 0) freq.erase(s[left]);
        left++;
    }
    // 更新答案
}
```

#### Leetcode 992. Subarrays with K Different Integers

```cpp
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
}

int atMost(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    int res = 0, left = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (count[nums[right]]++ == 0) k--;
        while (k < 0) {
            if (--count[nums[left++]] == 0) k++;
        }
        res += (right - left + 1);
    }
    return res;
}
```

---

### 4. 字元頻率對齊類（異位詞 / 最小子串）

####  Leetcode 76. Minimum Window Substring

####  Leetcode 567. Permutation in String

核心概念：

* 用兩個 map 存 target 與視窗內的頻率
* 當頻率全部滿足時，再縮小視窗以找到最小解

---

### 5. 允許錯誤次數的最長子串

####  Leetcode 1004. Max Consecutive Ones III

####  Leetcode 424. Longest Repeating Character Replacement

```cpp
unordered_map<char, int> freq;
int max_count = 0, left = 0;
for (int right = 0; right < s.size(); right++) {
    freq[s[right]]++;
    max_count = max(max_count, freq[s[right]]);
    if ((right - left + 1) - max_count > k) {
        freq[s[left++]]--;
    }
    // 更新結果
}
```

---

### 6. 進階結構滑窗（中位數、覆蓋範圍）

####  Leetcode 480. Sliding Window Median

> 使用雙堆或 multiset 處理動態中位數

####  Leetcode 632. Smallest Range Covering K Lists

> 小根堆 + 滑窗追蹤範圍覆蓋

---

## 題單整理

| 題號  | 題目                                             | 重點技巧           |
| --- | ---------------------------------------------- | -------------- |
| 3   | Longest Substring Without Repeating Characters | 唯一性 / set      |
| 209 | Minimum Size Subarray Sum                      | sum ≥ target   |
| 713 | Subarray Product < k                           | 乘積條件 / 視窗個數    |
| 424 | Longest Repeating Character Replacement        | 允許容錯次數         |
| 76  | Minimum Window Substring                       | 頻率對齊 / 滿足度計數   |
| 992 | Subarrays with K Different Integers            | 恰好 K 類型 / 差值技巧 |
| 567 | Permutation in String                          | 頻率一致滑窗檢查       |
| 480 | Sliding Window Median                          | 雙堆統計結合滑窗       |

---
