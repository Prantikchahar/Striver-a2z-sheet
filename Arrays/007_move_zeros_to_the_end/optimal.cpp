// Problem 7: Move Zeros to the End
// Optimal Approach - Two Pointers With Swap

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Two Pointers With Swap
// ---------------------------------------------------------
void moveZeroes(vector<int>& arr) {
    int n = arr.size();
    int j = 0;                                // pointer to next non-zero "slot"
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);             // brings non-zero forward, pushes zero back
            j++;
        }
    }
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

    for (auto arr : tests) {
        moveZeroes(arr);

        cout << "-> [";
        for (int i = 0; i < arr.size(); i++) cout << arr[i] << (i + 1 < arr.size() ? "," : "");
        cout << "]\n";
    }

    return 0;
}