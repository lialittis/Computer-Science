/* BFS */
#include <iostream>
#include <queue>
#include "treenode.h"

using namespace std;

class Solution{
public:
    int minDepth(TreeNode* root){
        if(root == nullptr) return 0;
        int depth = 1;
        queue<TreeNode> q;
        q.push(*root);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i< sz ; i++) {
                TreeNode cur = q.front();
                q.pop();
                if(cur.left == nullptr && cur.right == nullptr) return depth;
                if(cur.left != nullptr ) q.push(*cur.left);
                if(cur.right != nullptr ) q.push(*cur.right);
            }
            depth++;
        }
        return depth;
    }
};

using namespace std;
int main () {

}
