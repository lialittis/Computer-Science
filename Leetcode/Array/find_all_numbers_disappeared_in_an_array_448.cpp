/*array*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// work locally but not in leetcode
// why ??????????
class FindAllNumbers{
public:
    // brust force
    vector<int> findDisappearedNumbers(vector<int>& nums){
        vector<int> ans{};
        // if(nums.empty()) return vector<int>();
        // int max = *max_element(nums.begin(),nums.end());
        // // find the maximum value in this nums
        int max = nums.size();

        // build an array to store each nums in each position
        vector<int> all(max,0);
        for(auto n : nums){
            all[n-1] = n;
        }

        for(int i =0; i< max; i++) {
            if(all[i]==0) ans.push_back(i+1);
        }
        return ans;
    }
//     33/33 cases passed (48 ms)
// Your runtime beats 85.85 % of cpp submissions
// Your memory usage beats 33.48 % of cpp submissions (34.8 MB)

    // set as negative
    vector<int> findDisappearedNumbers2(vector<int>& nums){
        vector<int> ans{};
        for(int n : nums){
            int pos = abs(n) -1;
            if( nums[pos] >0){
                nums[pos] = -nums[pos];
            }
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
// 33/33 cases passed (44 ms)
// Your runtime beats 94.04 % of cpp submissions
// Your memory usage beats 94.54 % of cpp submissions (33.6 MB)
};

int main( int argc, char* argv[]){
    FindAllNumbers sol;
    vector<int> inputs{4,3,2,7,8,2,3,1};
    vector<int> ans = sol.findDisappearedNumbers2(inputs);
    for(auto n : ans){
        cout<<n<<" "<<endl;
    }
}