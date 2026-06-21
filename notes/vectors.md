# Vectors in C++

## What is a Vector?

- Dynamic array — size can change at runtime
- Need to include `#include <vector>`

## Declaration

```cpp
vector<int> v;                    // empty
vector<int> v = {1, 2, 3};       // with values
vector<int> v(5, 0);             // size 5, all zeros
```

## Common Operations

```cpp
v.push_back(10);   // end mein add
v.pop_back();      // end se remove
v.size();          // length
v[0];              // access by index
v.front();         // first element
v.back();          // last element
```

## Vector vs Array

|           | Array | Vector  |
| --------- | ----- | ------- |
| Size      | Fixed | Dynamic |
| push_back | ❌    | ✅      |
| size()    | ❌    | ✅      |
