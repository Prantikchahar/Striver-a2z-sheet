
             //    CODE

     // METHOD 1 -->> SORTING  
      

             int largestElement_sortMethod(vector<int>& arr) {
                     sort(arr.begin(), arr.end());                         // rearrange ascending
                      return arr[arr.size() - 1];                         // last position holds the max
                      }

   // METHOD 2 -->> Compare Every Element Against Every Other Element

             int largestElement_compareAllMethod(vector<int>& arr) {
                 int n = arr.size();
                 for (int i = 0; i < n; i++) {
                      bool isLargest = true;
                    for (int j = 0; j < n; j++) {
                       if (arr[j] > arr[i]) {                        // someone beats this candidate
                          isLargest = false;
                                break;
                              }
                            }  
                       if (isLargest) return arr[i];              // survived every comparison
                        }
                         return -1;                              // unreachable for non-empty arrays
                      }
