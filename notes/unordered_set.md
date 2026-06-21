# unordered_set in C++

## When to use?

- When you need to check if an element exists
- When you need to detect duplicates
- When you need to store unique elements only

## Methods

- seen.insert(x) → add element to set
- seen.count(x) → 1=exists, 0=not exists
- seen.find(x) → returns iterator, check != seen.end()
- seen.size() → total number of elements
- seen.erase(x) → remove element from set

## Time Complexity

- insert → O(1) average
- count → O(1) average
- find → O(1) average

## vs unordered_map

- unordered_set → stores KEY only (existence check)
- unordered_map → stores KEY + VALUE (lookup by key)

## Example

unordered_set<int> seen;
seen.insert(5); // {5}
seen.count(5); // 1 - exists
seen.count(9); // 0 - not exists

## Learned From

- Contains Duplicate (arrays/contains-duplicate.cpp)
