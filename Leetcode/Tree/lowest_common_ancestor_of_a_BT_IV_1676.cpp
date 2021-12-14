/* VIP */

/* Given the root of a binary tree and an array of TreeNode objects nodes, 
 * return the lowest common ancestor (LCA) of all the nodes in nodes.
 * All the nodes will exist in the tree, and all values of the tree's nodes are unique.
 */

#include "treenode.h"
#include <vector>
#include <set>

using namespace std;


/* First Try, using the same path as the two nodes to find */
/* using a for loop to compare the root, it takes time */
TreeNode* lca(TreeNode* root, vector<TreeNode*> list) {
    if(root == nullptr) return nullptr;

    for(auto n : list) {
        if(root == n) return root;
    }

    TreeNode* left = lca(root->left, list);
    TreeNode* right = lca(root->right, list);

    if(left && right) return root;
    if(left) return left;
    else return right;
}


/* reference */
/* using a set to compare the root, faster */
TreeNode* lowestCommonAncestor(TreeNode* root, const set<TreeNode*>& nodes_set) {
    if (root == nullptr) {
        return nullptr;
    }

    if (nodes_set.count(root) > 0) {
        return root;
    }

    TreeNode* l = lowestCommonAncestor(root->left, nodes_set);
    TreeNode* r = lowestCommonAncestor(root->right, nodes_set);

    if (l && r) {
        return root;
    }

    return l ? l : r;
}

TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
    set<TreeNode*>nodes_set(nodes.begin(), nodes.end());
    return lowestCommonAncestor(root, nodes_set);
}