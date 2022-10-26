/*array*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size()<=1) return 1;
        int cur_max = 0, count = 0;
        for(int i= 0; i<arr.size();i++){
            cur_max = max(cur_max,arr[i]);
            if(cur_max == i) {
                ++count;
            }
        }
        return count;
    }
};