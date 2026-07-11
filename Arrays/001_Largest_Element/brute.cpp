
    //    CODE

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//method 1 -->
int largestElement_sorting(vector<int>& arr){
    sort(arr.begin(),arr.end());                  // rearrange ascending
    return arr[arr.size()-1];                    // returning the last index value
}

//method 2--
int largestElement_compare(vector<int>& arr){
    int n = arr.size();
    if(arr.empty())  return -1;
    for(int i=0;i<n;i++){
        bool islargest = true;
        for(int j=0;j<n;j++){
            if(arr[j]>arr[i]){                 // someone beats this candidate
                islargest = false;          
                break;
            }
        }
        if(islargest) return arr[i];          // survived every comparison
    }
    return -1;                               // unreachable for non-empty arrays
}

int main(){
    vector<int> arr = {3,5,7,9,1};
    cout<<"The largest element using method 1 : "<<largestElement_sorting(arr)<<endl;
    cout<<"The largest element using method 2 : "<<largestElement_compare(arr)<<endl;
    return 0;
}
