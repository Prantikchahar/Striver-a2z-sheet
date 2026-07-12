// Problem 3: Check if the Array is Sorted and Rotated
// Optimal Approach - Single-Pass Drop Count

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Single-Pass Drop Count
// ---------------------------------------------------------
bool check(vector<int>& nums) {
    int n = nums.size();
    int drops = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) drops++;   // % n wraps last→first
    }
    return drops <= 1;   // 0 = already sorted, 1 = validly rotated
}

// ---------------------------------------------------------
// Driver
// ---------------------------------------------------------
int main() {
    vector<vector<int>> tests = {
        {3, 4, 5, 1, 2},   // true  (rotated by 3)
        {1, 2, 3, 4, 5},   // true  (rotation by 0)
        {2, 1, 3, 4},      // false
        {1, 1, 1, 1},      // true  (all equal)
        {1}                // true  (single element)
    };

    for (auto& arr : tests) {
        cout << "Array: ";
        for (int x : arr) cout << x << " ";

        cout << "-> " << (check(arr) ? "true" : "false") << "\n";
    }

    return 0;
}