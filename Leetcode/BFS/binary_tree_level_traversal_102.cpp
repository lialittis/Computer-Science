#include <queue>
#include "treenode.h"

using namespace std;

class Solution{
    vector<vector<int>> levelOrder(TreeNode* root){
        if(!root) return vector<vector<int>>{};
        vector<vector<int>> output;
        vector<int> cur;
        queue<TreeNode*> q;
        q.push(root);

        int count = 1;

        while (!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            cur.push_back(t->val);
            if(--count==0){
                output.push_back(cur);
                cur.clear();
                count = q.size();
            }
        }

        return output;
        
    }
};

int main(){

}