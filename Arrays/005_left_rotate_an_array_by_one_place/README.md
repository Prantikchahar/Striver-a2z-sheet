# 5. Left Rotate an Array by One Place

> **Intuition:** Only one element (the original first element) is ever truly at risk of being lost — save it before anything shifts, and everything else can move freely.

---

## Problem Statement

Shift every element of the array one position to the left; the first element wraps around to become the last element.

### Constraints

- Must be done in-place with O(1) extra space.
- Only one element (the original first element) truly needs to be saved before it is overwritten — everything else simply shifts down by one slot.

### Example

**Input**
```text
arr = [1, 2, 3, 4, 5]
```

**Output**
```text
[2, 3, 4, 5, 1]
```

---

# Brute Force Approach

## Method 1 - Build a Brand-New Array

### Logic

Build a new array where each position i holds whatever was at position (i+1) % n in the original — this directly encodes "everyone moves one step left, first wraps to last" without worrying about overwrite order at all.

### Algorithm

1. Create a new array temp of size n.
2. For i = 0 to n-1: temp[i] = arr[(i+1) % n].
3. Return temp.

### Code

[brute.cpp](./brute.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) |
| Space | O(N) |

---

# Better Approach

Not applicable.

---

# Optimal Approach

## Save First, Shift, Place Last

### Logic

Save the element that is about to be overwritten (arr[0]) into a temporary variable before any shifting begins. Then freely shift every element one slot left. Finally, place the saved value into the now-empty last slot.

### Algorithm

1. If n <= 1, return (nothing to rotate).
2. temp = arr[0].
3. For i = 1 to n-1: arr[i-1] = arr[i].
4. arr[n-1] = temp.

### Code

[optimal.cpp](./optimal.cpp)

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(N) |
| Space | O(1) |

---

# Interview Notes

- Trivial on its own, but interviewers use it as a setup question before asking "now generalize to rotate by K" — so understand why you save first, not just that you save first.

---


