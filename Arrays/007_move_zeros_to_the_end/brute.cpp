// Problem 7: Move Zeros to the End
// Brute Force Approach

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Method 1 - Build a Fresh Array
// ---------------------------------------------------------
vector<int> moveZeroesBrute(vector<int>& arr) {
    vector<int> temp;
    for (int x : arr) if (x != 0) temp.push_back(x);
    while (temp.size() < arr.size()) temp.push_back(0);
    return temp;
}

// ---------------------------------------------------------
// Driver
// ---------------------------------------------------------
int main() {
    vector<vector<int>> tests = {
        {0, 1, 0, 3, 12},   // -> [1,3,12,0,0]
        {0, 0, 0},          // -> [0,0,0]
        {1, 2, 3},          // -> [1,2,3]
        {0}                 // -> [0]
    };

    for (auto& arr : tests) {
        vector<int> result = moveZeroesBrute(arr);

        cout << "Original: ";
        for (int x : arr) cout << x << " ";
        cout << "-> [";
        for (int i = 0; i < result.size(); i++) cout << result[i] << (i + 1 < result.size() ? "," : "");
        cout << "]\n";
    }

    return 0;
}