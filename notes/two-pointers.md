# Two Pointers Pattern

## When to use?

- Array problems with pairs
- Need O(n) instead of O(n²)
- Can make decision based on comparison

## Template

int l = 0, r = n - 1;
while(l < r){
// calculate something
if(move left?) l++;
else r--;
}

## Key Insight — Container With Most Water

Shorter wall is always the bottleneck.
Move the shorter wall pointer → chance of finding better wall.

## Time Complexity

- O(n) — single pass
- O(1) — no extra space

## Learned From

- Container With Most Water
