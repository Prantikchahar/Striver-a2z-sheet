#include<bits/stdc++.h>
using namespace std;
// function 
int secondlargestelement_optimal(vector<int> arr){
    int n = arr.size(); 
    if (n < 2) return -1; 
    int largest = -1, secondLargest = -1;                  // assumes non-negative values 
    for (int i = 0; i < n; i++) { 
        if (arr[i] > largest) { 
            secondLargest = largest;                // old king demoted 
            largest = arr[i];                      // new king crowned 
        } else if (arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];                        // beats runner-up only
            }
    }
    return secondLargest;
}

int main(){
    vector<int> arr = {2,5,7,8,8,1,4};
    cout<<"The second largest element using brute force method : "<<secondlargestelement_optimal(arr)<<endl;
    return 0;
}
