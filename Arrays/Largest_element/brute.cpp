 /*        Given an array of integers, find the maximum value present in it.
  Example: Input: arr = [3, 2, 1, 5, 2]
           Output: 5


      LOGIC:--->> If we arrange all elements in ascending order, the biggest one must land at the final index, by the very definition of “sorted”.
                 This trades a full sort for a trivially simple lookup at the end.

      ALGORITHM: -->>  1. Sort the array in non-decreasing order.
                       2. Return the element sitting at index n-1 (the last position).



           */
             //CODE 
     int largestElement_sortMethod(vector<int>& arr) {
                     sort(arr.begin(), arr.end());                         // rearrange ascending
                      return arr[arr.size() - 1];                         // last position holds the max
                      }

   // complexity analysis -->>
   /* 
           T.C -->> O(N log N) + O(1) ... i.e O(N log N)
           S.C -->> O(log N) auxiliary (recursion stack) — commonly rounded to O(1) in interviews
   */
