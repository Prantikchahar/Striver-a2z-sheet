# 001. Largest Element in an array

> **Intuition:** keep track of the maximum element while traversing the array once.

---

## Problem Statement

Given an array of integers, find the maximum value present in it.

### Constraints

1 ≤ N ≤ 10^5. The array may contain negative numbers and duplicate values. Anything worse than O(N log N) is risky at
this size; O(N) is the expected answer.

### Example

**Input**
```text
arr = [3, 2, 1, 5, 2]
```

**Output**
```text
5
```

---

# Brute Force Approach

## Method 1 - Sort and Pick the Last Element

### Logic

If we arrange all elements in ascending order, the biggest one must land at the final index, by the very definition of “sorted”. This trades a full
sort for a trivially simple lookup at the end.

### Algorithm

1. Sort the array in non-decreasing order.
2. Return the element sitting at index n-1 (the last position).

### Code

`brute.cpp`

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N logN) |
| Space | O(log N) auxiliary (recursion stack) — commonly rounded to O(1) in interviews |

---

## Method 2 - Compare Every Element Against Every Other Element

### Logic

An element is “the largest” if and only if it is greater than or equal to every other element in the array. So for each candidate index i, scan the
entire rest of the array and check whether anything beats it. The first candidate that survives every comparison is the answer.

### Algorithm

1. For each index i from 0 to n-1:
2. Assume arr[i] is the largest (isLargest = true).
3. For each index j from 0 to n-1:
4. If arr[j] > arr[i], set isLargest = false and stop the inner loop.
5. If isLargest is still true after the inner loop, return arr[i].

### Code

`brute.cpp`

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N^2) |
| Space | O(1) |

---

# Better Approach

*Not Applicable.*

---

# Optimal Approach

## Single Pass — Running Champion

### Logic

The compare-all-pairs brute force redundantly re-derives the same information over and over. If instead we keep a running champion as we
scan once, each new element only needs to be compared against the current best — because losing to the current best implies losing to
everyone the current best has already beaten. This collapses O(N2) comparisons down to exactly N-1 comparisons.

### Algorithm

1. If the array is empty, handle as an edge case (no maximum exists).
2. Set max_val = arr[0] (seed with a real element, never with 0).
3. For i = 1 to n-1:
4. If arr[i] > max_val: max_val = arr[i]
5. Return max_val.

### Code

`optimal.cpp`

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) |
| Space | O(1) |

---

# Interview Notes

--Expected to be written bug-free in under 2 minutes — this is treated as a warm-up question.

--If you start by describing the O(N2) compare-all idea out loud, immediately self-correct: “Actually, I don’t need to re-compare against everyone
— I can just track a running max.” Interviewers reward this self-correction.

--Some interviewers test edge-case awareness by asking: “What if the array has one element? All same elements? All negative?”



