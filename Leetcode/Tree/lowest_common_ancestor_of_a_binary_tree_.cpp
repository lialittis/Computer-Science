/* Medium */

#include "treenode.h"
#include <stack>

using namespace std;


/* recursive */

// Runtime: 8 ms, faster than 99.63% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage: 14.2 MB, less than 57.71% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.

TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2) {
    TreeNode* res = root;
    if(root == NULL) return NULL;

    if(root == n1 || root == n2) return root;

    TreeNode* left = LCA(root->left, n1, n2);
    TreeNode* right = LCA(root->right,n1,n2);

    if(left!=NULL && right != NULL) return root;

    if(left==NULL) return right;

    return left;

    // return left!=NULL ? left : right; // this line is too slow 

}

/* SIMILARY PROBLEMS

Lowest Common Ancestor of a Binary Search Tree
Smallest Common Region
Lowest Common Ancestor of a Binary Tree II
Lowest Common Ancestor of a Binary Tree III
Lowest Common Ancestor of a Binary Tree IV
Step-By-Step Directions From a Binary Tree Node to Another

*/