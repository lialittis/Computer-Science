#include <vector>

using namespace std;

class Solution{
public:
    bool search(vector<int>& nums, int target){
       int l = 0, r = nums.size()-1;
        while (l <= r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true; // find

            if(nums[mid] == nums[l]){
                ++l; // we have no idea about the order
            }
            else if(nums[mid] <= nums[r]){ // right side is in ascending order
                if(nums[mid] < target && nums[r] >= target){
                    l = mid+1;
                }
                else{
                    r = mid;
                }
            }
            else{ // left side is in ascending order
                if(nums[mid] >= target && nums[l] <= target){
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
        }

        return false;
    }
};

// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.27 % of cpp submissions (13.9 MB)