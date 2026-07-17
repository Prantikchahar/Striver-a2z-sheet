// Problem 8: Linear Search
// Optimal Approach - Early-Exit Linear Scan

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Early-Exit Linear Scan
// ---------------------------------------------------------
int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;   // early exit on first match
    }
    return -1;                            // not found after checking everything
}

// ---------------------------------------------------------
// Driver
// ---------------------------------------------------------
int main() {
    vector<pair<vector<int>, int>> tests = {
        {{5, 3, 8, 2}, 8},        // -> 2
        {{5, 3, 8, 2}, 5},        // -> 0
        {{5, 3, 8, 2}, 100},      // -> -1
        {{7}, 7}                 // -> 0
    };

    for (auto& [arr, target] : tests) {
        int result = linearSearch(arr, target);

        cout << "Array: ";
        for (int x : arr) cout << x << " ";
        cout << "target=" << target << " -> " << result << "\n";
    }

    return 0;
}