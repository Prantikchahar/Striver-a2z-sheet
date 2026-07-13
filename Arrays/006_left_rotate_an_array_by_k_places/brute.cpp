// Problem 6: Left Rotate an Array by K Places
// Brute Force Approach

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Method 1 - Build a Brand-New Array
// ---------------------------------------------------------
vector<int> leftRotateBrute(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++) temp[i] = arr[(i + k) % n];
    return temp;
}

// ---------------------------------------------------------
// Driver
// ---------------------------------------------------------
int main() {
    vector<pair<vector<int>, int>> tests = {
        {{1, 2, 3, 4, 5, 6, 7}, 2},   // -> [3,4,5,6,7,1,2]
        {{1, 2, 3}, 5},               // k%n=2 -> [3,1,2]
        {{1, 2, 3, 4}, 0},            // -> [1,2,3,4]
        {{1}, 3}                      // -> [1]
    };

    for (auto& [arr, k] : tests) {
        vector<int> result = leftRotateBrute(arr, k);

        cout << "Original: ";
        for (int x : arr) cout << x << " ";
        cout << "K=" << k << " -> [";
        for (int i = 0; i < result.size(); i++) cout << result[i] << (i + 1 < result.size() ? "," : "");
        cout << "]\n";
    }

    return 0;
}