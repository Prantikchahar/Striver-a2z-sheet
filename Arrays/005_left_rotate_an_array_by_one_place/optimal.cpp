// Problem 5: Left Rotate an Array by One Place
// Optimal Approach - Save First, Shift, Place Last

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Save First, Shift, Place Last
// ---------------------------------------------------------
void leftRotateByOne(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;                  // nothing to rotate
    int temp = arr[0];                   // save the element about to be overwritten
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];             // shift everyone one step left
    }
    arr[n - 1] = temp;                   // saved element lands at the end
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

    for (auto arr : tests) {
        leftRotateByOne(arr);

        cout << "-> [";
        for (int i = 0; i < arr.size(); i++) cout << arr[i] << (i + 1 < arr.size() ? "," : "");
        cout << "]\n";
    }

    return 0;
}