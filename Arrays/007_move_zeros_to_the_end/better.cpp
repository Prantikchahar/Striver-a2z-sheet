// Problem 7: Move Zeros to the End
// Better Approach - Overwrite in Place, Then Fill Zeros Separately

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Better Approach - Overwrite in Place, Then Fill Zeros Separately
// ---------------------------------------------------------
void moveZeroesBetter(vector<int>& arr) {
    int n = arr.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[j] = arr[i];       // overwrite (not swap)
            j++;
        }
    }
    while (j < n) {                // second pass: fill the rest with zeros
        arr[j] = 0;
        j++;
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
        moveZeroesBetter(arr);

        cout << "-> [";
        for (int i = 0; i < arr.size(); i++) cout << arr[i] << (i + 1 < arr.size() ? "," : "");
        cout << "]\n";
    }

    return 0;
}