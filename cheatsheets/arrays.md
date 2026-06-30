# Arrays — DSA Cheat Sheet

## The Mindset Shift

Beginners think: "How do I solve this problem?"
Experienced devs think: "What pattern is this?"

This cheat sheet exists to help you recognize patterns fast,
specifically for Array problems.

---

## Step 1: Understand the Problem (always first, no exceptions)

- What is the input? (size, range of values, sorted or not)
- What is the output? (single value, array, boolean)
- What are the constraints? (n up to 10^5? then O(n log n) max)
- What are the edge cases?
  - Empty array
  - Single element
  - All same elements
  - All negative numbers
  - Already sorted / reverse sorted

A constraint like "n <= 10^5" is a hint:

- O(n²) → ~10^10 ops → TOO SLOW → need O(n) or O(n log n)
- O(n) → ~10^5 ops → safe

---

## Step 2: Ask — What does this problem actually need?

| Need                                 | Pattern/Structure                     |
| ------------------------------------ | ------------------------------------- |
| Fast existence check                 | unordered_set                         |
| Fast lookup by key                   | unordered_map                         |
| Find pair/triplet with target sum    | Two Pointers (if sortable) or HashMap |
| Subarray with some property          | Sliding Window or Prefix Sum          |
| Sorted array search                  | Binary Search                         |
| Max/min in one pass                  | Greedy                                |
| "Except self" / cumulative result    | Prefix + Suffix                       |
| Min/max subarray sum                 | Kadane's Algorithm                    |
| Find unique element among duplicates | XOR                                   |
| Need to sort then process            | Sort first, then linear scan          |

---

## Step 3: Pattern Recognition — Arrays Specific

### unordered_set — existence check

Use when: "has this been seen before?", detect duplicates

```cpp
unordered_set<int> seen;
seen.insert(x);
seen.count(x);   // 1 = exists, 0 = not
```

Time: O(1) avg insert/lookup

### unordered_map — key-value lookup

Use when: need complement/pair lookup, frequency count

```cpp
unordered_map<int,int> map;  // {value, index} or {value, frequency}
map[key] = value;
map.count(key);
```

Time: O(1) avg insert/lookup
Pattern: ALWAYS check before store (avoid matching element with itself)

### Two Pointers

Use when: sorted array, need pair/triplet matching a condition

```cpp
int l = 0, r = n - 1;
while(l < r){
    if(condition) l++;
    else r--;
}
```

Time: O(n)

### Sliding Window

Use when: subarray/substring with a size constraint or running condition

```cpp
int l = 0;
for(int r = 0; r < n; r++){
    // expand window using nums[r]
    while(window invalid){
        // shrink window using nums[l]
        l++;
    }
}
```

Time: O(n)

### Binary Search

Use when: sorted (or rotated sorted) array, need O(log n)

```cpp
int l = 0, r = n - 1;
while(l < r){
    int mid = l + (r - l) / 2;
    if(condition) l = mid + 1;  // mid is definitely not the answer
    else r = mid;               // mid could be the answer
}
return nums[l];
```

Time: O(log n)
Key rule: l = mid+1 eliminates mid; r = mid keeps mid as a candidate

### Prefix Sum / Prefix-Suffix

Use when: "for each element, do something with all other elements",
repeated range-sum queries

```cpp
// Prefix product/sum
prefix[0] = base;  // 1 for product, 0 for sum
for(int i = 1; i < n; i++)
    prefix[i] = prefix[i-1] OP nums[i-1];

// Suffix product/sum
suffix[n-1] = base;
for(int i = n-2; i >= 0; i--)
    suffix[i] = suffix[i+1] OP nums[i+1];

answer[i] = prefix[i] OP suffix[i];
```

Time: O(n), Space: O(n) → can optimize to O(1) extra space

### Kadane's Algorithm

Use when: max/min sum of a contiguous subarray

```cpp
int maxSum = INT_MIN, currentSum = 0;
for(int val : nums){
    currentSum += val;
    maxSum = max(currentSum, maxSum);
    if(currentSum < 0) currentSum = 0;  // reset if it hurts future sums
}
```

Time: O(n)

### XOR

Use when: find the single/unique element among duplicates (each other appears even number of times)

```cpp
int result = 0;
for(int val : nums) result ^= val;
return result;
```

Properties: a^a=0, a^0=a, order doesn't matter
Time: O(n), Space: O(1)

### Greedy (one-pass tracking)

Use when: track a running min/max while scanning once

```cpp
int minSoFar = INT_MAX, best = 0;
for(int price : prices){
    minSoFar = min(minSoFar, price);
    best = max(best, price - minSoFar);
}
```

Time: O(n)

### Gaussian Sum (math trick)

Use when: missing number / expected vs actual sum problems

```cpp
int expectedSum = n * (n + 1) / 2;
int actualSum = accumulate(nums.begin(), nums.end(), 0);
int missing = expectedSum - actualSum;
```

---

## Step 4: Optimize — Ask Yourself

- Can I reduce time complexity?
  - O(n²) → O(n) using HashMap/Set?
  - O(n) → O(log n) using Binary Search (if sorted)?
- Can I reduce space complexity?
  - O(n) extra array → O(1) using running variables?
  - Two separate prefix/suffix arrays → one array + one variable?
- Can I preprocess something?
  - Sort first? (enables Two Pointers)
  - Build prefix sums first? (enables O(1) range queries)

---

## Quick Decision Tree for Arrays

```
Is array sorted (or can be sorted)?
├── YES → Consider Binary Search or Two Pointers
└── NO  → Can I avoid sorting?
          ├── Need existence/frequency? → HashMap/HashSet
          ├── Need running max/min?     → Greedy / Kadane's
          ├── Need "except self" logic? → Prefix + Suffix
          ├── Need unique element?      → XOR
          └── Need subarray w/ window?  → Sliding Window
```

---

## Common Bugs Checklist (from real mistakes made)

- [ ] return statement placed OUTSIDE the loop (not inside)
- [ ] inner loop starts at i+1, not i (avoid self-comparison)
- [ ] use INT_MIN for max tracking, not 0 (fails with all-negative arrays)
- [ ] Two Sum returns INDEXES, not values
- [ ] C++ object creation: `Solution sol;` — no `new` needed
- [ ] check map/set BEFORE inserting current element (Two Sum pattern)
- [ ] r = mid (not mid - 1) when mid could still be the answer
- [ ] mid = l + (r - l) / 2 to avoid integer overflow

---

## Problems Solved So Far (reference)

| Problem                     | Pattern            | Time     |
| --------------------------- | ------------------ | -------- |
| Two Sum                     | HashMap            | O(n)     |
| Contains Duplicate          | HashSet            | O(n)     |
| Best Time to Buy/Sell Stock | Greedy             | O(n)     |
| Move Zeroes                 | Two-pass insertPos | O(n)     |
| Missing Number              | Gaussian Sum       | O(n)     |
| Single Number               | XOR                | O(n)     |
| Maximum Subarray            | Kadane's           | O(n)     |
| Product Except Self         | Prefix+Suffix      | O(n)     |
| Find Min in Rotated Array   | Binary Search      | O(log n) |
