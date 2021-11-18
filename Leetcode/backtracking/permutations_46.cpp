#include <vector>

using namespace std;

class BT{
private:
    // using backtracking to avoid to use more space
    void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans){
        if( level == nums.size() -1){ // edga cases
            ans.push_back(nums);
            return ;
        }
        
        for(int i = level ; i < nums.size(); i++) {
            // change the current node situation
            swap(nums[i], nums[level]);
            // backtrack to the next levem
            backtracking(nums,level+1,ans);
            // return to the last situation
            swap(nums[i],nums[level]);
        }
    }
public:
    // all permutations can be get by swap each numbe with the values behind it
    vector<vector<int>> permute(vector<int>& nums){
        // return value
        vector<vector<int>> ans;
        backtracking(nums,0, ans);
        return ans;
    }
};
// Your runtime beats 70.57 % of cpp submissions
// Your memory usage beats 78.14 % of cpp submissions (7.7 MB)