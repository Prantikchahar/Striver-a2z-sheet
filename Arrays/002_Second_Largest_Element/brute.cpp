#include<bits/stdc++.h>
using namespace std;
// function 
int secondlargestelement_brute(vector<int> arr){
    sort(arr.begin(), arr.end()); 
    for (int i = (int)arr.size() - 2; i >= 0; i--) { 
        if (arr[i] != arr.back()) return arr[i];                 // skip duplicates of max 
        } 
        return -1;                                  // every element is equal — no valid second largest
    }

int main(){
    vector<int> arr = {2,5,7,8,8,1,4};
    cout<<"The second largest element using brute force method : "<<secondlargestelement_brute(arr)<<endl;
    return 0;
}
