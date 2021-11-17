#include <vector>
#include <algorithm>

using namespace std;

class TwoSumII{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        // int* left= &nums[0];
        // int* right = &nums.back();
        vector<int> ans;
        int l = 0, r = nums.size()-1;
        while (l < r)
        {
            int x = nums[l] + nums[r];
            if(x == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            else if( x > target ){
                r--;
            }
            else {
                l++;
            }
        }

        return ans;
    }
};

// Your runtime beats 87.45 % of cpp submissions
// Your memory usage beats 43.42 % of cpp submissions (9.6 MB)

int main(){

}