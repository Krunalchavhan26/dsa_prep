# Binary Search

## What is Binary Search?

Instead of checking every element (O(n)),
divide the search space in half each time → O(log n)

## When to use?

- To do searching in sorted array
- Rotated sorted array
- O(log n) time required
- "Find minimum/maximum" in sorted structure
- Any problem where you can eliminate half the options

## Core Idea

```
At each step, check the middle element.
Eliminate the half that cannot contain the answer.
Repeat until one element remains.
```

## Key Rule — Most Important!

```
l = mid + 1  → safely eliminate mid (mid is definitely NOT the answer)
r = mid      → cannot eliminate mid (mid COULD be the answer)
```

## Standard Template

```cpp
int l = 0, r = nums.size() - 1;

while(l < r){
    int mid = l + (r - l) / 2;  // avoid overflow (not (l+r)/2)

    if(condition to go right){
        l = mid + 1;
    } else {
        r = mid;
    }
}
return nums[l];  // l == r at the end
```

## Why mid = l + (r - l) / 2 and not (l + r) / 2?

```
If l and r are large:
l + r can overflow int!

l + (r - l) / 2 is safe — no overflow
```

## Dry Run — Find Minimum in Rotated Array

```
nums = [3, 4, 5, 1, 2]
l=0, r=4

Step 1: mid=2, nums[mid]=5, nums[r]=2
        5 > 2? YES → minimum is in right half
        l = mid+1 = 3

Step 2: mid=3, nums[mid]=1, nums[r]=2
        1 > 2? NO → minimum is in left half (including mid)
        r = mid = 3

Step 3: l=3, r=3 → loop ends
return nums[3] = 1 ✅
```

## Key Insight — Rotated Sorted Array

```
[3, 4, 5, | 1, 2]
           ↑ rotation point = minimum

If nums[mid] > nums[r]:
    minimum is in RIGHT half → l = mid + 1

If nums[mid] <= nums[r]:
    minimum is in LEFT half (including mid) → r = mid
```

## Time & Space Complexity

- Time → O(log n) — half eliminated each step
- Space → O(1) — no extra space

## Common Mistakes

- Using r = mid - 1 when mid could be the answer
- Using (l + r) / 2 instead of l + (r - l) / 2
- Infinite loop when l and r don't converge

## Learned From

- Find Minimum in Rotated Sorted Array
  (arrays/find-minimum-rotated-array-medium.cpp)
