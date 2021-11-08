#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// class Solution{
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums){
//         vector<vector<int>> res{};
//         sort(nums.begin(),nums.end());
//         vector<int> levels{};
//         // vector<bool> used(false,nums.size());
//         backtrack(res,0,nums,levels);
//         return res;
//     }

//     void backtrack(vector<vector<int>>& res, int i,vector<int>& nums, vector<int>& levels){
//         if(levels.size() == nums.size()){
//             res.push_back(levels);
//             return;
//         }
//         for( int k=i;k < nums.size(); i++) {
//             if ( i > 0 && nums[i] == nums[i -1] ) continue;
//             levels.push_back(nums[i]);
//             backtrack(res,i+1,nums,levels);
//             levels.pop_back();
//         }
//     }
// };

class Solution2 {
public:
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res{};
        backtrack(nums,0,res);
        return res;
    }

    void backtrack(vector<int> nums, int i, vector<vector<int>>& res){
        if(i == nums.size()-1){
            res.push_back(nums);
            return;
        }

        for(int k = i; k < nums.size(); k++ ) {
            if(nums[i] == nums[k] && i !=k) continue;
            swap(nums[i],nums[k]);
            backtrack(nums,i+1,res);
        }
    }
};

class Solution3 {
public:
    void permuteUniqueHelper(int i, vector<int>& nums, vector<vector<int> >& result) {
        if (i == nums.size()) { result.emplace_back(nums); return; }
        unordered_set<int> st;
        for (int j = i; j < nums.size(); ++j) {
            if (st.count(nums[j]) == 1) { continue; }
            st.insert(nums[j]);
            std::swap(nums[i], nums[j]);
            permuteUniqueHelper(i + 1, nums, result);
            std::swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        permuteUniqueHelper(0, nums, result);
        return result;
    }
    
};

int main(){

}