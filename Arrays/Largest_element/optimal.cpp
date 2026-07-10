 //CODE ---->>

//optimal approach -->  single pass 


           int largestElement(vector<int>& arr) {
                   if (arr.empty()) return -1;                 //guard: no elements 
                 int max_val = arr[0];                        // seed with first element, NOT 0
                    for (int i = 1; i < arr.size(); i++) {   
                      if (arr[i] > max_val) {
                          max_val = arr[i];                  // dethrone the old champion
                            }
                          } 
                    return max_val;
                       }

