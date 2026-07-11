# 002. Second Largest Element

> **Intuition:** Track the largest and second largest elements while scanning the array , update them whenever a bigger element is found

---

## Problem Statement

Given an array of integers, find the element that is strictly smaller than the largest element, but larger than every other
element — i.e. the second distinct largest value.

### Constraints

Must be solved in a single pass with O(1) extra space, without sorting. Duplicates of the maximum must be ignored —
the word “strictly” is doing all the work here.

### Example

**Input**
```text
arr = [1, 2, 4, 7, 7, 5]
```

**Output**
```text
5 (the largest is 7; the repeated 7 does not count as the second largest)
```

---

# Brute Force Approach

## Method 1 - Sort and Scan Backward for a Strictly Smaller Value

### Logic

After sorting ascending, the largest sits at the last index. Walk backward from the second-last index until a value is found that differs from the
largest — that value is the answer. The backward scan is necessary specifically to skip over duplicate copies of the max.

### Algorithm

1. Sort the array in ascending order.
2. Let last = arr[n-1] (the maximum value).
3. Walk i from n-2 down to 0:
4. If arr[i] != last, return arr[i].
5. If the loop finishes without returning, every element is equal — return -1 (no valid answer).

### Code

[brute.cpp](./brute.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N logN) |
| Space | O(N)for the defensive copy (or O(log N) if sorting in place) |

---

# Better Approach

### Logic

First pass finds the true maximum using the same running-champion idea from Problem 1. Second pass then finds the largest value that is not
equal to that maximum.

### Algorithm

1. Pass 1: mx = arr[0]; for each x in arr: mx = max(mx, x).
2. Pass 2: second = −∞, found = false;
3. for each x in arr: if x != mx: second = max(second, x), found = true.
4. Return second if found, else -1.

### Code

[better.cpp](./better.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) (with a 2× constant factor versus a single pass) |
| Space | O(1) |


---

# Optimal Approach

## Single Pass With Demotion

### Logic

A new maximum instantly makes the previous maximum the new second-largest — no separate pass is needed. At each step there are two
cases: either the current element beats the current largest (crown it, demote the old largest to second), or it doesn’t beat the largest but still
beats the current second-largest (promote it to second, without disturbing the largest).

### Algorithm

1. Set largest = second = −∞ (or -1, if the array is known to be non-negative).
2. For each x in arr:
3. If x > largest: second = largest (demote old king); largest = x (crown new king).
4. Else if x < largest AND x > second: second = x (beats the runner-up only).
5. Return second.

### Code

[optimal.cpp](./optimal.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) |
| Space | O(1) |

---

# Interview Notes

- If you jump straight to the one-pass solution, verbally explain the two-pass version first — interviewers want to see your reasoning path, not just
  the final trick.
- Common follow-up: “Now generalize to the K-th largest” → naturally leads to a Heap / QuickSelect discussion.
- Edge cases interviewers probe: an all-equal array ([5,5,5] → no valid second largest), and arrays of size 1 or 2.
 
 

---

