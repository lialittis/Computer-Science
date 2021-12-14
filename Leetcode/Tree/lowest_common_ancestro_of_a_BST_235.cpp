/* Easy */


/* First Try 
 * O(log n)
 */

/* lca of a BST
 * BST : values are in order; log(n) to find a value
 * compare the values of nodes with current node, decide take left branch or right branch or current branch
 */

// Runtime: 32 ms, faster than 52.30% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
// Memory Usage: 23.2 MB, less than 61.96% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.


#include "treenode.h"

using namespace std;

TreeNode* lcaBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) return nullptr;
    if(root == p || root == q) return root;

    int val = root->val;
    TreeNode* next;
    if((p->val < val && q->val > val) || (p->val > val &&  q->val <val)) return root;
    else if(p->val > val && q->val > val) {
        next = lcaBST(root->right, p, q);
    }else if(p->val < val && q->val < val ) {
        next = lcaBST(root->left,p,q);
    }

    return next;
}

/* Optimization */

/* iteration */

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* cur = root;
    while (true) {
        if (p -> val < cur -> val && q -> val < cur -> val) {
            cur = cur -> left;
        } else if (p -> val > cur -> val && q -> val > cur -> val) {
            cur = cur -> right;
        } else {
            break;
        }
    }
    return cur;
}

// Runtime: 32 ms, faster than 52.30% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
// Memory Usage: 23.2 MB, less than 92.39% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.