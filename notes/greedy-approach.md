# Greedy Approach

## What is Greedy?

At each step, make the best possible decision
without worrying about future steps.
"Locally optimal choice → Globally optimal solution"

## Best Time to Buy & Sell Stock — Greedy applied

Instead of checking every buy/sell combination (O(n²)),
track two things in one pass:

- minPrice → cheapest price seen so far
- maxProfit → best profit seen so far

At each day:

1. Is today cheaper than minPrice? → update minPrice
2. Is today's profit better than maxProfit? → update maxProfit

## Key Insight

You don't need to know the future.
Just track the minimum price seen so far —
selling at any future price gives the best profit from that min.

## Code Pattern

```cpp
int minPrice = INT_MAX;
int maxProfit = 0;

for(int i = 0; i < prices.size(); i++){
    if(prices[i] < minPrice)
        minPrice = prices[i];

    int profit = prices[i] - minPrice;
    if(profit > maxProfit)
        maxProfit = profit;
}
```

## When to use Greedy?

- Optimization problems (max/min find karna ho)
- One pass mein solve ho sake
- Future decisions past decisions pe depend na karein

## Time Complexity

- O(n) — single pass
- O(1) — no extra space

## Learned From

- Best Time to Buy and Sell Stock
