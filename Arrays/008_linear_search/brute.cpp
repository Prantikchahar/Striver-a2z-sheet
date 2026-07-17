// Problem 8: Linear Search
// Brute Force Approach

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Method 1 - Scan Fully, Track Index Without Early Exit
// ---------------------------------------------------------
int linearSearchNoEarlyExit(vector<int>& arr, int target) {
    int foundIndex = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            foundIndex = i;    // remember it, but don't stop
        }
    }
    return foundIndex;
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
        int result = linearSearchNoEarlyExit(arr, target);

        cout << "Array: ";
        for (int x : arr) cout << x << " ";
        cout << "target=" << target << " -> " << result << "\n";
    }

    return 0;
}