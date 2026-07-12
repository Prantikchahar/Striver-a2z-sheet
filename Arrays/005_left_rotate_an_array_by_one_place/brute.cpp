// Problem 5: Left Rotate an Array by One Place
// Brute Force Approach

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// - Build a Brand-New Array
// ---------------------------------------------------------
vector<int> leftRotateExtraSpace(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    for (int i = 0; i < n; i++) temp[i] = arr[(i + 1) % n];
    return temp;
}

// ---------------------------------------------------------
// Driver
// ---------------------------------------------------------
int main() {
    vector<vector<int>> tests = {
        {1, 2, 3, 4, 5},   // -> [2,3,4,5,1]
        {1, 2},            // -> [2,1]
        {1}                // -> [1]
    };

    for (auto& arr : tests) {
        vector<int> result = leftRotateExtraSpace(arr);

        cout << "Original: ";
        for (int x : arr) cout << x << " ";

        cout << "-> [";
        for (int i = 0; i < result.size(); i++) cout << result[i] << (i + 1 < result.size() ? "," : "");
        cout << "]\n";
    }

    return 0;
}