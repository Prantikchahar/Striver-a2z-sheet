# 4. Remove Duplicates from Sorted Array

> **Intuition:** Because the array is already sorted, duplicates of any value are guaranteed to sit adjacent to each other — so a single "last known-unique value" pointer is always enough to detect something new.

---

## Problem Statement

Given a sorted (non-decreasing) array, remove duplicates in-place so that each unique value appears only once at the front of the array, and return the count of unique values k.

### Constraints

- Must be done in-place — O(1) extra space, no new array allowed.
- Because the array is already sorted, duplicates of any value are guaranteed to sit adjacent to each other.

### Example

**Input**
```text
arr = [1, 1, 2, 2, 2, 3]
```

**Output**
```text
k = 3, with the array's first 3 elements now being [1, 2, 3]
```

---

# Brute Force Approach

## Method 1 - Hash Set, Then Copy Back

### Logic

A set automatically keeps only unique values (and, for an ordered set, keeps them sorted). Insert every element, then overwrite the front of the original array with the set's contents in order.

### Algorithm

1. Build an ordered set s from all elements of nums.
2. i = 0; for each value x in s (in sorted order): nums[i] = x; i++.
3. Return i (the count of unique values).

### Code

[brute.cpp](./brute.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N log N) |
| Space | O(N) |

---

## Method 2 - Nested Loop, Manually Shift on Every Duplicate Found

### Logic

A more mechanical approach that avoids any extra container: scan the array, and whenever arr[i] == arr[i+1], physically shift every element after i+1 one position left (overwriting the duplicate), and shrink the effective length. Repeat until no adjacent duplicates remain.

### Algorithm

1. i = 0; n = arr.size().
2. While i < n-1:
3. If arr[i] == arr[i+1]: shift every element from i+1 onward one slot left; n--.
4. Else: i++.
5. Return n.

### Code

[brute.cpp](./brute.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N²) worst case |
| Space | O(1) |

---

# Better Approach

Not applicable — .

---

# Optimal Approach

## Two Pointers (Read / Write)

### Logic

The index i never needs to move unless a genuinely new value is found — sorted order guarantees duplicates are adjacent, so a single comparison against the last written value is always enough to detect "new".

### Algorithm

1. If nums is empty, return 0.
2. i = 0 (last known-unique index).
3. For j = 1 to n-1:
4. If nums[j] != nums[i]: i++; nums[i] = nums[j].
5. Return i + 1.

### Code

[optimal.cpp](./optimal.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) |
| Space | O(1) |

---

# Interview Notes

- This exact two-pointer template reappears constantly — memorize the shape, not just this specific problem.
- Common follow-up: "What if duplicates are allowed to appear at most twice?" (LeetCode 80) — requires comparing against `nums[i-1]` as well as `nums[i]`.
- Interviewers explicitly test: do you return `i` or `i+1`? Getting this wrong signals carelessness.

---
