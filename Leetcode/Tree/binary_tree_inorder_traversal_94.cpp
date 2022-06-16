/* Easy */

/* Given the root of a binary tree, return the inorder traversal 
 * of its nodes' values 
 *
 * number of nodes in the tree is in the range [0,100]
 *
 * -100 <= Node.val <= 100
 *
 */

#include "treenode.h"
#include <vector>
#include <stack>

using namespace std;


/* Inorder Traversal : left first, middle secondly, right last ; recursively
 * 
 * two arrays/vectors, one for left and current
 * another for right, and finally insert second
 * to the first.
 *
 * O(n) time and O(n) space
 *
 */

vector<int> inorderTraversal(TreeNode* root){
	// containers : two vectors
	vector<int> A;
	vector<int> B;

	if(root!=NULL){
		A = inorderTraversal(root->left);
		A.push_back(root->val);
		B = inorderTraversal(root->right);
		A.insert(A.end(),B.begin(),B.end());
	}

	return A;
}

/* Second Method: Iterative solution using stack
 *
 * push current node and all left nodes to stack, and pop them one by one,
 * store current node when no left node, and switch to its right node, repeat
 * stop when stack is empty and current node is null
 * 
 * O(n) time ; O(n) space
 *
 */
vector<int> inorderTraversal2(TreeNode *root){
	// container of output
	vector<int> nodes;
	// stack of todo node
	stack<TreeNode*> todo;
	
	while(root || !todo.empty()) {
		while(root){
			todo.push(root);
			root = root->left;
		}
		root = todo.top();
		todo.pop();
		nodes.push_back(root->val);
		root = root->right;
	}
	return nodes;
}

/* Third Method: Recursive Method(similar with the first method)
 * O(n) time and O(n) space (function call stack)
 *
 * Good to Remember :
 * 1. a standard recursive writen way - two functions
 * 2. using reference to avoid return value
 */

void inorder(TreeNode *root,vector<int>& nodes);

vector<int> inorderTraversal3(TreeNode *root){
	//container
	vector<int> nodes;
	inorder(root,nodes);
	return nodes;
}


void inorder(TreeNode *root, vector<int>& nodes){
	// end case
	if(!root){
		return;
	}

	inorder(root->left,nodes);
	nodes.push_back(root->val);
	inorder(root->right,nodes);
}




