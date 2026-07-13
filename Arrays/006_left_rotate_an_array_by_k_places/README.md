# 6. Left Rotate an Array by K Places

> **Intuition:** A left rotation by K is really just two blocks swapping places — and reversing each block, then reversing the whole array, achieves that swap with zero extra space.

---

## Problem Statement

Rotate the array left by K positions, in-place.

### Constraints

- K can be larger than N and must be handled with K % N, since rotating by exactly N returns the array to its original state.

### Example

**Input**
```text
arr = [1, 2, 3, 4, 5, 6, 7], K = 2
```

**Output**
```text
[3, 4, 5, 6, 7, 1, 2]
```

---

# Brute Force Approach

## Method 1 - Build a Brand-New Array

### Logic

Directly compute, for every output position i, which original position it should pull from — that is (i + K) % n, since after rotating left by K, whatever was K positions ahead becomes the new element at position i.

### Algorithm

1. k = k % n.
2. Create new array temp of size n.
3. For i = 0 to n-1: temp[i] = arr[(i+k) % n].
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

## Rotate by One, K Times

### Logic

Reuse the already-solved rotate-by-one building block from Problem 5, and simply apply it K times in a row. Each application shifts everything one step further left.

### Algorithm

1. k = k % n.
2. Repeat k times: call leftRotateByOne(arr).

### Code

[better.cpp](./better.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N·K) |
| Space | O(1) |

---

# Optimal Approach

## Reversal Algorithm (Block Swap via Triple Reversal)

### Logic

reverse(0, K-1) + reverse(K, N-1) + reverse(0, N-1) achieves a left rotation by K in exactly three linear passes, with no extra array. Reversing each block locally scrambles it, but reversing the whole array afterward is exactly the operation needed to both un-scramble each block and swap their positions in one motion.

### Algorithm

1. k = k % n; if k == 0, return (no rotation needed).
2. reverseRange(arr, 0, k-1) — reverse the first block.
3. reverseRange(arr, k, n-1) — reverse the second block.
4. reverseRange(arr, 0, n-1) — reverse the whole array.

### Code

[optimal.cpp](./optimal.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) (three linear passes) |
| Space | O(1) |

---

# Interview Notes

- This is one of the most-asked "clever trick" array questions — the reversal algorithm is expected knowledge, not something to derive from scratch under time pressure, so memorize the three-reversal pattern.
- Common follow-up: "How would you right-rotate by K instead?" → same trick, just rotate by n - k (or reverse the blocks in the opposite order).
- Edge cases: K = 0 (no-op), K = N (no-op after modulo), K > N (handled safely by the modulo).

---
#  Try Yourself

-- Right rotate an array by k places ...