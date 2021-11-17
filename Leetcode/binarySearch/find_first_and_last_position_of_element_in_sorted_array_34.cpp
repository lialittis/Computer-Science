#include <vector>

using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        if(nums.empty()) return vector<int>{-1,-1};
        int left = lower_bound(nums, target);
        int right = upper_bound(nums,target);
        if(left == nums.size() || nums[left] != target){
            return vector<int>{-1,-1};
        }

        return vector<int>{left,right};

    }

    int lower_bound(vector<int>&nums, int target){
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid]>=target){
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }

    int upper_bound(vector<int>&nums, int target){
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l)/2;
            while(l<r){
                int mid = l + (r - l) /2;
                if(nums[mid] > target) {
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return l-1;
    }
    // Your runtime beats 68.73 % of cpp submissions
    // Your memory usage beats 84.15 % of cpp submissions (13.5 MB)
};


int main() {

}