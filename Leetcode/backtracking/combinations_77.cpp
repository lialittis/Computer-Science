#include <vector>
#include <iostream>

using namespace std;    

class BT{
private:
    void backtracing(vector<vector<int>>& ans, vector<int>& cur, int level, int n, int k){
        // signal to push back
        if(cur.size() == k){
            ans.push_back(cur);
            return ;
        }

        // go deeper for find more opportunity of combinations
        for(int i = level; i <= n; i++){
            cur.push_back(i); // change the state
            backtracing(ans,cur,i+1,n,k); // deeper
            cur.pop_back(); // back and return the original state
        }
    }

public:
    vector<vector<int>> combinate(int n, int k){
        // return value
        vector<vector<int>> ans{};
        // to store each combination
        vector<int> cur{};

        backtracing(ans, cur, 1, n, k);
        return ans;
    }
};
// Your runtime beats 84.67 % of cpp submissions
// Your memory usage beats 78.71 % of cpp submissions (9 MB)

int main() {

}