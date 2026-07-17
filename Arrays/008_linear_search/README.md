# 8. Linear Search

> **Intuition:** The moment a match is found, the answer is already known — continuing to scan is wasted work.

---

## Problem Statement

Given an array and a target value, return the index of the target if it is present, else return -1.

### Constraints

- The array is unsorted — this is exactly why binary search does not apply here.

### Example

**Input**
```text
arr = [5, 3, 8, 2], target = 8
``

**Output**
```text
2
```

---

# Brute Force Approach

## Method 1 - Scan Fully, Track Index Without Early Exit

### Logic

Walk through every element, and whenever a match is found, remember its index — but keep scanning to the end regardless (no early exit). This is "correct but naive" because it does unnecessary work once a match is already confirmed.

### Algorithm

1. foundIndex = -1.
2. For i = 0 to n-1:
3. If arr[i] == target: foundIndex = i (do not break).
4. Return foundIndex.

### Code

[brute.cpp](./brute.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) always (best case = worst case) |
| Space | O(1) |

---

# Better Approach

Not applicable as a distinct tier for this problem — the only meaningful improvement over the no-early-exit scan is adding an early return the moment a match is found, and that improvement is exactly the optimal approach below.

---

# Optimal Approach

## Early-Exit Linear Scan

### Logic

The moment a match is found, the answer is already known — there is no reason to keep scanning. Returning immediately turns the best-case complexity into O(1) (target at the front) while keeping the worst case at O(N) (target at the back or absent).

### Algorithm

1. For i = 0 to n-1:
2. If arr[i] == target: return i.
3. Return -1 (not found after checking everything).

### Code

[optimal.cpp](./optimal.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) worst case, O(1) best case |
| Space | O(1) |

---

# Interview Notes

- Trivial alone, but interviewers use it to check baseline coding hygiene: correct early return, correct -1 fallback, no off-by-one errors.
- Common follow-up: "What if the array were sorted?" → expect an immediate pivot to Binary Search, O(log N).

---

