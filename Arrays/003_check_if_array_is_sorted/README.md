# 3. Check if the Array is Sorted and Rotated

> **Intuition:** A sorted-then-rotated array can only "drop" (a value followed by something smaller) at most once when walked circularly.

---

## Problem Statement

Given an array, determine whether it was originally sorted in non-decreasing order and then rotated some number of positions (possibly zero).

### Constraints

- 1 ≤ N ≤ 100 typically — N is small, so the challenge is correctness, not raw speed.
- The array is circular: the last element's neighbor is the first element, not "nothing".

### Example

**Input**
```text
arr = [3, 4, 5, 1, 2]
```

**Output**
```text
true (original array was [1,2,3,4,5], rotated by 3 positions)
```

---

# Brute Force Approach

## Method 1 - Try Every Rotation Amount, Check If Sorted

### Logic

For every possible shift amount from 0 to n-1, treat that shift as the "unrotation" and check whether the resulting sequence (read circularly starting from that shift) is non-decreasing. If any shift produces a sorted sequence, the answer is true.

### Algorithm

1. For shift = 0 to n-1:
2. ok = true
3. For i = 0 to n-2:
4. If arr[(i+shift)%n] > arr[(i+1+shift)%n]: ok = false; break
5. If ok: return true
6. Return false.

### Code

[brute.cpp](./brute.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N²) |
| Space | O(1) |

---

## Method 2 - Sort a Copy, Match Against Every Rotation

### Logic

First sort a copy of the array to know the "ideal" fully sorted version. Then check whether the original array equals some rotation of that sorted copy, by aligning them at every possible starting offset.

### Algorithm

1. sortedVersion = sorted copy of nums.
2. For shift = 0 to n-1:
3. matches = true
4. For i = 0 to n-1:
5. If nums[(i+shift)%n] != sortedVersion[i]: matches = false; break
6. If matches: return true
7. Return false.

### Code

[brute.cpp](./brute.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N²) |
| Space | O(N) |

---

# Better Approach

Not applicable 

---

# Optimal Approach

## Single-Pass Drop Count

### Logic

There's no need to locate the rotation point at all — just count how many times the "ascending" trend breaks, treating the array as circular. A perfectly sorted array has zero drops. A validly rotated sorted array has exactly one drop (at the rotation point; the wrap-around from last to first accounts for this correctly). Two or more drops means the array could never have come from rotating a single sorted sequence.

### Algorithm

1. drops = 0
2. For i = 0 to n-1:
3. If arr[i] > arr[(i+1) % n]: drops++
4. Return drops <= 1.

### Code

[optimal.cpp](./optimal.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) |
| Space | O(1) |

---

# Interview Notes

- Using `(i+1) % n` instead of an if-branch for the wrap-around signals comfort with circular-array idioms — interviewers notice this.
- Common follow-up: "What if duplicates are allowed?" — the strict `>` check already handles this correctly, since ties never count as drops.
- Edge cases interviewers like: a single-element array (trivially true, 0 drops), and an all-equal array (true, 0 drops).

---




