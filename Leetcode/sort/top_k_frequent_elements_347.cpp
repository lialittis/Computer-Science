#include <vector>
#include <unordered_map>

using namespace std;


class TopK{
public:
    vector<int> topK(vector<int>& nums, int k){
        unordered_map<int,int> buckets;
        int max_count;
        for(auto n : nums){
            max_count = max(max_count, ++buckets[n]);
        }

        vector<vector<int>> all(max_count+1);
        for(auto p : buckets){
            all[p.second].push_back(p.first);
        }

        vector<int> ans;
        for(int i = max_count; i>=0 && ans.size() < k; i--){
            for(auto n: all[i]){
                ans.push_back(n);
                if(ans.size() == k){
                    break;
                }
            }
        }
        return ans;
    }

    // Your runtime beats 93.02 % of cpp submissions
    // Your memory usage beats 22.11 % of cpp submissions (13.8 MB)
};