 //CODE ---->>

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int largestElement_optimal(vector<int>& arr){
    int n = arr.size();
    if(arr.empty())  return -1;                // guard: no elements
    int max = arr[0];                         // seed with first element, NOT 0
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max = arr[i];                   // dethrone the old champion
        }
    }
    return max;
}


int main(){
    vector<int> arr = {3,5,7,9,1};
    cout<<"The largest element using optimal approach : "<<largestElement_optimal(arr)<<endl;
    
    return 0;
}
