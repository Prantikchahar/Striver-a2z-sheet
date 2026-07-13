// Problem 6: Left Rotate an Array by K Places
// Better Approach - Rotate by One, K Times

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Building block from Problem 5 - Left Rotate by One Place
// ---------------------------------------------------------
void leftRotateByOne(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

// ---------------------------------------------------------
// Better Approach - Rotate by One, K Times
// ---------------------------------------------------------
void leftRotateKTimes(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;
    while (k--) leftRotateByOne(arr);   // reuses Problem 5's function
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

    for (auto [arr, k] : tests) {
        leftRotateKTimes(arr, k);

        cout << "K=" << k << " -> [";
        for (int i = 0; i < arr.size(); i++) cout << arr[i] << (i + 1 < arr.size() ? "," : "");
        cout << "]\n";
    }

    return 0;
}