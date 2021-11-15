#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class UF_map{
private:
    vector<int> id;
    vector<int> size;
public:

    int find(int p){
        while (p != id[p]) // root node of the tree with a parent-link structure
        {
            id[p] = id[id[p]]; // change the currend node id to its parent id
            // the purpose is to make a small depth tree => faster find nearly in O(1)
            // but this could break the size of the subtree (little important)
            p = id[p];
        }
        return p;
    }

    void unionSet(int a, int b){
        int i = find(a);
        int j = find(b);
        if(i == j) return;
        if(size[i] > size[j]){ // to make the tree more balance
            id[j] = i;
            size[i] += size[j]; // attention to the order
        }else{
            id[i] = j;
            size[j] += size[i];
        }
    }
    int longestConsecutive(vector<int>& nums){
        int n = nums.size();
        if(n < 2) return n;
        // initialization for id and size;
        size = vector<int>(n,1);
        for(int i = 0; i< n; i++){
            id.push_back(i);
        }

        // build a unordered map to store the tree
        // the first integer stands for the value, the second is its id
        // because we want to find the values during the search process
        unordered_map<int,int> records;

        for(int i = 0; i<n ; i++){
            if(records.find(nums[i]) != records.end()) continue; // find it self
            records[nums[i]] = i; // set the id for ith value
            if(records.find(nums[i]-1) != records.end()) {
                // find the consective value
                unionSet(i, records[nums[i]-1]);
            }
            if(records.find(nums[i]+1) != records.end()) {
                // find the consecutive value
                unionSet(i, records[nums[i]+1]);
            }
        }

        int res = *max_element(size.begin(),size.end());
        return res;
    }
};
// 70/70 cases passed (221 ms)
// Your runtime beats 41.9 % of cpp submissions
// Your memory usage beats 8.03 % of cpp submissions (33.1 MB)

int main(){

}