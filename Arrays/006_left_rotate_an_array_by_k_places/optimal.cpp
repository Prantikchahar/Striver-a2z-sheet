// Problem 6: Left Rotate an Array by K Places
// Optimal Approach - Reversal Algorithm (Block Swap via Triple Reversal)

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Helper - reverse arr[start..end] in place
// ---------------------------------------------------------
void reverseRange(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++; end--;
    }
}

// ---------------------------------------------------------
// Reversal Algorithm (Block Swap via Triple Reversal)
// ---------------------------------------------------------
void leftRotateByK(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;                              // handles K > N safely
    if (k == 0) return;                  // no rotation needed
    reverseRange(arr, 0, k - 1);         // reverse first block
    reverseRange(arr, k, n - 1);         // reverse second block
    reverseRange(arr, 0, n - 1);         // reverse the whole array
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
        leftRotateByK(arr, k);

        cout << "K=" << k << " -> [";
        for (int i = 0; i < arr.size(); i++) cout << arr[i] << (i + 1 < arr.size() ? "," : "");
        cout << "]\n";
    }

    return 0;
}