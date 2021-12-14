/* VIP */

/* lowest common ancestor of a binary tree II
 * normal lca + if p or q doesn't exist
 */


/* First Try 
 * recursive, it one null then return null
 */

#include "treenode.h"
#include <algorithm>

pair<TreeNode*, int> dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) return {nullptr,0} ; // no node found
    // go through the branch first
    pair<TreeNode*,int> left = dfs(root->left, p, q);
    pair<TreeNode*,int> right = dfs(root->right, p, q);
    // return values later
    if(root == p || root == q) {
        return {root, 1 + left.second + right.second}; // update number of nodes found
    }

    if(left.first && right.first) {
        return {root, 2}; // return directly
    }

    if(left.first) return left;
    else return right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    pair<TreeNode*, int> res = dfs(root, p, q); // int is used to count how many nodes found
    if(res.second < 2) {
        return nullptr;
    }

    return res.first;
} 