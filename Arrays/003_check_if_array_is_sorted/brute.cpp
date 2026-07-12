// Problem 3: Check if the Array is Sorted and Rotated
// Brute Force Approaches

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Method 1 - Try Every Rotation Amount, Check If Sorted
//  ---------------------------------------------------------
bool checkBrute(vector<int>& nums) {
    int n = nums.size();
    for (int shift = 0; shift < n; shift++) {
        bool ok = true;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[(i + shift) % n] > nums[(i + 1 + shift) % n]) { ok = false; break; }
        }
        if (ok) return true;
    }
    return false;
}

// ---------------------------------------------------------
// Method 2 - Sort a Copy, Match Against Every Rotation
// ---------------------------------------------------------
bool checkBrute_sortedCompare(vector<int> nums) {
    int n = nums.size();
    vector<int> sortedVersion = nums;
    sort(sortedVersion.begin(), sortedVersion.end());
    for (int shift = 0; shift < n; shift++) {
        bool matches = true;
        for (int i = 0; i < n; i++) {
            if (nums[(i + shift) % n] != sortedVersion[i]) { matches = false; break; }
        }
        if (matches) return true;
    }
    return false;
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

        bool r1 = checkBrute(arr);
        bool r2 = checkBrute_sortedCompare(arr);

        cout << "-> Method1: " << (r1 ? "true" : "false")
             << " | Method2: " << (r2 ? "true" : "false") << "\n";
    }

    return 0;
}
