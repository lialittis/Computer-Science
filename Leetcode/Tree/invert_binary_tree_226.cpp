/* binary tree */

/* Given the root of a binary tree
 * invert the tree
 * return its root
 *
 * */

#include "treenode.h"
#include <algorithm>
// first idea : recursive way, do invert for each sub-tree

class SolutionRec{
public:
	TreeNode* invertTree(TreeNode *root){
		// end
		if(root == nullptr ) return root;
		
		TreeNode *tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);
		return root;
	}
};

// Same method, another way of writing

class SolutionRec2{
public:
	TreeNode* invertTree(TreeNode* root){
		if(root==NULL) return NULL;
		swap(root->left, root->right);

		invertTree(root->left);
		invertTree(root->right);

		return root;
	}
};
