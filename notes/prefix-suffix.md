# Prefix & Suffix Pattern

## What is Prefix?

Everything to the LEFT of current index.

## What is Suffix?

Everything to the RIGHT of current index.

## Core Idea

```
For each index i:
- prefix[i] = product/sum of all elements LEFT of i
- suffix[i] = product/sum of all elements RIGHT of i
- answer[i] = prefix[i] * suffix[i]
```

## Visual Example — Product Except Self

```
nums   = [1,  2,  3,  4]
index     0   1   2   3

prefix[0] = 1           (nothing to the left)
prefix[1] = 1           (just nums[0] = 1)
prefix[2] = 1 * 2 = 2   (nums[0] * nums[1])
prefix[3] = 1 * 2 * 3 = 6

suffix[3] = 1           (nothing to the right)
suffix[2] = 4           (just nums[3] = 4)
suffix[1] = 4 * 3 = 12  (nums[3] * nums[2])
suffix[0] = 4 * 3 * 2 = 24

answer[i] = prefix[i] * suffix[i]
answer = [1*24, 1*12, 2*4, 6*1]
       = [24,   12,   8,   6] ✅
```

## Pattern — prefix[i] formula

```
prefix[0] = 1
prefix[i] = prefix[i-1] * nums[i-1]
```

## Pattern — suffix[i] formula

```
suffix[n-1] = 1
suffix[i]   = suffix[i+1] * nums[i+1]
```

## Code — O(n) time, O(n) space

```cpp
int n = nums.size();
vector<int> prefix(n), suffix(n), answer(n);

// Build prefix
prefix[0] = 1;
for(int i = 1; i < n; i++)
    prefix[i] = prefix[i-1] * nums[i-1];

// Build suffix
suffix[n-1] = 1;
for(int i = n-2; i >= 0; i--)
    suffix[i] = suffix[i+1] * nums[i+1];

// Build answer
for(int i = 0; i < n; i++)
    answer[i] = prefix[i] * suffix[i];
```

## Optimized — O(n) time, O(1) space

```cpp
// Store prefix directly in answer array
// Use single suffix variable

int n = nums.size();
vector<int> ans(n, 1);

// Prefix pass
for(int i = 1; i < n; i++)
    ans[i] = ans[i-1] * nums[i-1];

// Suffix pass — single variable
int suffix = 1;
for(int i = n-2; i >= 0; i--){
    suffix *= nums[i+1];
    ans[i] *= suffix;
}
```

## When to use Prefix/Suffix?

```
"For each element, do something with all OTHER elements"
→ Prefix + Suffix pattern

Examples:
- Product of array except self
- Sum of array except self
- Running total/cumulative sum
```

## Key Insight

```
Instead of recomputing left/right product every time (O(n²))
Precompute and store → O(n)
```

## Time & Space Complexity

- Basic → O(n) time, O(n) space
- Optimized → O(n) time, O(1) space

## Learned From

- Product of Array Except Self
  (arrays/product-except-self-medium.cpp)
