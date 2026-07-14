# 7. Move Zeros to the End

> **Intuition:** Swapping instead of overwriting makes the zero-relocation happen automatically as a side effect — no second pass needed.

---

## Problem Statement

Move all zeros in the array to the end while maintaining the relative order of the non-zero elements, in-place.

### Constraints

- In-place, O(1) extra space.
- Must preserve relative order of non-zero elements — this rules out simply counting zeros and appending them at the end; the non-zero elements must actually be shifted forward in their original sequence.

### Example

**Input**
```text
arr = [0, 1, 0, 3, 12]
```

**Output**
```text
[1, 3, 12, 0, 0]
```

---

# Brute Force Approach

## Method 1 - Build a Fresh Array

### Logic

Scan once and collect every non-zero element (in order) into a new array. Once collection is done, the number of missing zeros is known — pad the remainder of the new array with that many zeros.

### Algorithm

1. temp = empty list.
2. For each x in arr: if x != 0, append x to temp.
3. While temp.size() < arr.size(): append 0 to temp.
4. Return temp.

### Code
 
 [brute.cpp](./brute.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) |
| Space | O(N) |

---

# Better Approach

## Overwrite in Place, Then Fill Zeros Separately

### Logic

Use a write pointer j to compact non-zero elements to the front of the same array via plain overwriting (no swap). After the scan, j marks exactly how many non-zero elements exist — everything from j to the end must now be explicitly set to zero in a second pass.

### Algorithm

1. j = 0.
2. For i = 0 to n-1: if arr[i] != 0: arr[j] = arr[i]; j++.
3. While j < n: arr[j] = 0; j++.

### Code

[better.cpp](./better.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) (two passes, 2× constant factor) |
| Space | O(1) |

---

# Optimal Approach

## Two Pointers With Swap

### Logic

Swapping (rather than overwriting) automatically relocates zeros to the back without any extra bookkeeping or second pass — whatever zero was occupying the write pointer's slot gets pushed to where the non-zero element used to be, which is always further back (or the same position), maintaining correctness in a single traversal.

### Algorithm

1. j = 0 (next slot for a non-zero element).
2. For i = 0 to n-1:
3. If arr[i] != 0: swap(arr[i], arr[j]); j++.

### Code

[optimal.cpp](./optimal.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) |
| Space | O(1) |

---

# Interview Notes

- Interviewers specifically check whether you use swap vs. plain overwrite — overwrite-without-fill is a common subtle bug, and even overwrite-with-a-second-pass (the Better approach) is often flagged with "can you do it in one pass?"
- Common follow-up: "Minimize the number of swaps" — the given solution already does this, since a swap only happens when a non-zero element is found.
- Edge cases: all zeros ([0,0,0] → unchanged), no zeros ([1,2,3] → unchanged, j chases i every step).

---

