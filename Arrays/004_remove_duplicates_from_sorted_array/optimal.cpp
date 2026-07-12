// Problem 4: Remove Duplicates from Sorted Array
// Optimal Approach - Two Pointers (Read / Write)

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Two Pointers (Read / Write)
// ---------------------------------------------------------
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;                                    // last known-unique index
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {                 // found a genuinely new value
            i++;
            nums[i] = nums[j];                    // write it into the next slot
        }
    }
    return i + 1;                                 // count of uniques (0-indexed -> +1)
}

// ---------------------------------------------------------
// Driver
// ---------------------------------------------------------
int main() {
    vector<vector<int>> tests = {
        {1, 1, 2, 2, 2, 3},   // k = 3 -> [1,2,3]
        {1, 2, 3},            // k = 3 -> [1,2,3]
        {1, 1, 1, 1},         // k = 1 -> [1]
        {5}                   // k = 1 -> [5]
    };

    for (auto arr : tests) {
        int k = removeDuplicates(arr);

        cout << "-> k=" << k << " [";
        for (int i = 0; i < k; i++) cout << arr[i] << (i + 1 < k ? "," : "");
        cout << "]\n";
    }

    return 0;
}