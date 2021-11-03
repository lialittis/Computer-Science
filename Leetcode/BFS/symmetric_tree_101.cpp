/* BFS; DFS */
#include <vector>
#include <queue>
#include "treenode.h"

using namespace std;

class Solution{
    //solution iterative(BFS)
    // less time, more memory
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
            if(t1 == nullptr && t2 == nullptr) continue;
            if(t1 == nullptr || t2 == nullptr) return false;
            if(t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;    
    }

    // solution recurive (DFS)
    // less memory, more time
    bool isSymmetric2(TreeNode* root){
        if(!root) return true;
        return judge(root->left,root->right);
    }

    bool judge(TreeNode* l, TreeNode* r){
        if( l==nullptr && r==nullptr ) return true;
        if( l== nullptr || r == nullptr) return false;
        if(l->val == r->val) return ((judge(r->left,l->right)) && (judge(r->right,l->left)));
        return false;
        // simplify
        //return (!l || !r ) ? l == r : l->val == r->val &&(judge(r->left,l->right)) && (judge(r->right,l->left));
    }
};

int main(){
    return 0;
}