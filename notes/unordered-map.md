# unordered_map in C++

## What is unordered_map?

A key-value store — like a phonebook.

- Key = name
- Value = phone number
- Lookup is O(1) average

## Declaration

```cpp
unordered_map<int, int> map;      // key=int, value=int
unordered_map<int, string> map;   // key=int, value=string
unordered_map<string, int> map;   // key=string, value=int
```

## Common Methods

```cpp
map[key] = value;      // insert or update
map.count(key);        // 1=exists, 0=not exists
map[key];              // get value by key
map.erase(key);        // remove key
map.size();            // total elements
```

## unordered_map vs unordered_set

|          | unordered_set     | unordered_map    |
| -------- | ----------------- | ---------------- |
| Stores   | Key only          | Key + Value      |
| Use case | Existence check   | Key→Value lookup |
| Example  | Duplicates detect | Two Sum          |

## Time Complexity

- insert → O(1) average
- lookup → O(1) average
- erase → O(1) average

## Code Pattern — Two Sum

```cpp
unordered_map<int, int> map;  // {number, index}

for(int i = 0; i < nums.size(); i++){
    int need = target - nums[i];
    if(map.count(need)){         // check first
        return {map[need], i};
    }
    map[nums[i]] = i;            // store after
}
```

## Key Rule

Always CHECK first, then STORE.
If you store first, you might match a number with itself.

## Dry Run — Two Sum [2,7,11,15] target=9

```cpp
map = {}
i=0: need=7, not in map → store {2:0}
i=1: need=2, found at index 0 → return {0,1} ✅
```

## When to use unordered_map?

- Two Sum style problems (find complement)
- Frequency counting (how many times X appeared)
- Caching / memoization
- Index lookup by value

## Learned From

- Two Sum optimized (arrays/two-sum-optimized.cpp)
