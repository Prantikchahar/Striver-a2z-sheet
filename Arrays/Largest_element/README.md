# Largest Element in an array


## PROBLEM STATEMENT 
 
     Given an array of integers, find the maximum value present in it. 

###  Example

           Input: arr = [3, 2, 1, 5, 2]
           Output: 5


#                            BRUTE FORCE METHOD(S)

##        METHOD 1 — Sort and Pick the Last Element
 
###         ALGORITHM--
                1. Sort the array in non-decreasing order.
                2. Return the element sitting at index n-1 (the last position). 

###         COMPLEXITY ANALYSIS --
                1. Time Complexity →  O(N log N)
                2. Space Complexity →  O(log N) auxiliary (recursion stack) — commonly rounded to O(1) in interviews


##       METHOD 2 — Compare Every Element Against Every Other Element

###        ALGORITHM --
              1. For each index i from 0 to n-1:
              2. Assume arr[i] is the largest (isLargest = true).
              3. For each index j from 0 to n-1:
              4. If arr[j] > arr[i], set isLargest = false and stop the inner loop.
              5. If isLargest is still true after the inner loop, return arr[i].
 
###        COMPLEXITY ANALYSIS --
               1. Time Complexity →  O(N^2)
               2. Space Complexity →  O(1)


#                          OPTIMAL APPROACH --->>

##         SINGLE PASS —>

###           ALGORITHM --
               1. If the array is empty, handle as an edge case (no maximum exists).
               2. Set max_val = arr[0] (seed with a real element, never with 0).
               3. For i = 1 to n-1:
               4. If arr[i] > max_val: max_val = arr[i]
               5. Return max_val.


###          COMPLEXITY ANALYSIS --
               1. Time Complexity →  O(N)
               2. Space Complexity →  O(1)


