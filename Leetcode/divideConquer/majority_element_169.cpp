/* divide and conquer */

#include <vector>
#include <algorithm>

using namespace std;

class Solution1{
public: 
    int majorityElement(vector<int>& nums){
        return divide(nums,0,nums.size()-1);
    }

    int divide(vector<int> nums,int left, int right){
        if(left == right) return nums[left]; // only one element
        int mid = left + (right - left)/2;
        int leftRes = divide(nums,left,mid);
        int rightRes = divide(nums,mid,right);

        if(leftRes == rightRes) return leftRes;
        int leftCount = conquer(nums,leftRes,left,right);
        int rightCount = conquer(nums,rightRes,left,right);
        return leftCount > rightCount ? leftRes : rightRes;
    }

    int conquer(vector<int>nums, int target, int left, int right){
        int count = 0;
        for (int i = left; i <= right; i++){
            if(nums[i] == target) count++;
        }

        return count;
    }
};


// vote
class Solution2{
public: 
    int majorityElement(vector<int>& nums){
        int count=0, candidate = 0;
        for(int num : nums){
            if(count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

// sort
class Solution3{
public:
    int majorityElement(vector<int>& nums){
        sort(nums.begin(),nums.end());
        return (nums[nums.size()/2]);
    }
};


int main() {

}