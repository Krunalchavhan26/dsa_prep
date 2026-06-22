# XOR (Exclusive OR) in DSA

## What is XOR?

XOR works at bit level — same bits cancel, different bits survive.

## Basic Rules

- 0 ^ 0 = 0 (same → cancel)
- 1 ^ 1 = 0 (same → cancel)
- 0 ^ 1 = 1 (different → survive)
- 1 ^ 0 = 1 (different → survive)

## Key Properties

- a ^ a = 0 same number XOR = always 0 (cancel)
- a ^ 0 = a any number XOR 0 = itself (no change)
- a ^ b ^ a = b order doesn't matter, same numbers cancel

## Real Life Analogy

Like a light switch:

- Press same switch twice → back to original (cancel)
- Press once → change happens (survive)

## Why start result = 0?

Because a ^ 0 = a
First number stays as-is, nothing gets affected.

## Code Pattern

    int result = 0;
    for(int i = 0; i < nums.size(); i++){
        result ^= nums[i];  // same as result = result ^ nums[i]
    }
    return result;

## Dry Run — [2, 2, 1]

    result = 0
    i=0: result = 0 ^ 2 = 2
    i=1: result = 2 ^ 2 = 0  (cancel!)
    i=2: result = 0 ^ 1 = 1  (survive!)
    return 1 ✅

## When to use XOR in DSA?

- Find single/unique element in array
- Swap two numbers without temp variable
- Detect duplicate in array
- Bit manipulation problems

## Shorthand

- result ^= nums[i]
- same as result = result ^ nums[i]

## Learned From

- Single Number (arrays/single-number-easy.cpp)
