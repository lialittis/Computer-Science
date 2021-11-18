#include <vector>

using namespace std;

class Solution{
public:
    // quick sort
    int findKthLargest(vector<int>& nums, int k){
        int l = 0, r = nums.size()-1;
        while (l<r)
        {
            int mid = quickselection(nums, l, r);
            if(mid = nums.size() - k) return nums[mid];
            if(mid < nums.size() - k) l = mid + 1;
            else r = mid - 1;
        }

        return nums[l];   
    }

    // method
    int quickselection(vector<int>& nums, int l, int r){
        int i = l+1, j = r;
        // take the first element as a pivot
        while(i<j){
            while(i<r && nums[i] <=nums[l]){
                ++i;
            }
            while(l < j && nums[j] >= nums[l]){
                --j;
            }
            if(i>=j) break;
            swap(nums[i],nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
        
    }
};


int main() {

}