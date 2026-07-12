// Problem 4: Remove Duplicates from Sorted Array
// Brute Force Approaches

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Method 1 - Hash Set, Then Copy Back
// ---------------------------------------------------------
int removeDuplicatesBrute(vector<int>& nums) {
    set<int> s(nums.begin(), nums.end());   // extra space!
    int i = 0;
    for (int x : s) nums[i++] = x;
    return i;
}

// ---------------------------------------------------------
// Method 2 - Nested Loop, Manually Shift on Every Duplicate Found
// ---------------------------------------------------------
int removeDuplicatesBrute_shiftMethod(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    while (i < n - 1) {
        if (arr[i] == arr[i + 1]) {
            for (int j = i + 1; j < n - 1; j++) arr[j] = arr[j + 1];   // shift left
            n--;                                                       // effective array shrinks by one
        } else {
            i++;
        }
    }
    return n;
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
        vector<int> a1 = arr;
        vector<int> a2 = arr;

        int k1 = removeDuplicatesBrute(a1);
        int k2 = removeDuplicatesBrute_shiftMethod(a2);

        cout << "Original: ";
        for (int x : arr) cout << x << " ";

        cout << "-> Method1: k=" << k1 << " [";
        for (int i = 0; i < k1; i++) cout << a1[i] << (i + 1 < k1 ? "," : "");
        cout << "]";

        cout << " | Method2: k=" << k2 << " [";
        for (int i = 0; i < k2; i++) cout << a2[i] << (i + 1 < k2 ? "," : "");
        cout << "]\n";
    }

    return 0;
}