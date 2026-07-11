#include<bits/stdc++.h>
using namespace std;
// function 
int secondlargestelement_better(vector<int> arr){ 
    int mx = arr[0]; 
    for (int x : arr) mx = max(mx, x);            // pass 1: find the max 
    int second = INT_MIN; 
    bool found = false; 
    for (int x : arr) {                         // pass 2: find max excluding mx 
        if (x != mx) 
        { 
            second = max(second, x); found = true; 
            } 
        } 
        return found ? second : -1;                           
  }

int main(){
    vector<int> arr = {2,5,7,8,8,1,4};
    cout<<"The second largest element using brute force method : "<<secondlargestelement_better(arr)<<endl;
    return 0;
}
