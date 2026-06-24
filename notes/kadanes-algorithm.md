# Kadane's Algorithm

## Problem

Find maximum sum subarray in O(n).

## Core Idea

At each element, decide:

- Extend current subarray
- Start fresh (reset to 0 if currentSum < 0)

## Code Pattern

int maxSum = INT_MIN, currentSum = 0;
for(int val : nums){
currentSum += val;
maxSum = max(currentSum, maxSum);
if(currentSum < 0) currentSum = 0;
}

## Time Complexity

- O(n) — single pass
- O(1) — no extra space

## Learned From

- Maximum Subarray (arrays/maximum-subarray-medium.cpp)
