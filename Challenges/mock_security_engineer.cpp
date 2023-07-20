/*
 * Binary Tree Algorithms
 *
 * You are given a binary tree containing digits from 0 to 9 only
 *
 * Each root-to-leaf path in the tree represents a number
 *
 * Return the total number of all root-to-leaf numbers
 *
 * */

/*

	1
       / \
      2   3
      	 / \
	4   5

*/

#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1{
public:
	// using dfs traversal firstly
	// in recursive way
	//
	// O(N) time, O(H) space, in worst case it is O(N)
	int sumNumbers(TreeNode *root){
		return dfs(root, 0);
	}
	
	int dfs (TreeNode *root, int cur){
		if(!root) return 0;
		cur = cur * 10 + root->val;
	
		if(!root->left && !root->right)
			return cur;
		return dfs(root->left, cur) + dfs(root->right, cur); 
	}
};


class Solution2{
public:
	// using dfs preorder in iterative way
	// using an explicit stack to store {TreeNode, cur}
	// O(N) time and O(H) space
	int sumNumbers(TreeNode *root){
		stack<pair<TreeNode*,int>> s; // {node, cur}
		s.push({root,0});
		int sum = 0;
		while(!s.empty()){
			auto [root,cur] = s.top();
			s.pop();
			cur = cur * 10 + root->val;
			if(!root->left && !root->right) sum += cur; // reached leaf node
			if(root->right) s.push({root->right,cur});
			if(root->left) s.push({root->left,cur});
		}
		return sum;
	}

};

class Solution3{
public:
	// BFS
	// O(N) and O(N)
	int sumNumbers(TreeNode* root){
		int sum = 0;
		queue<pair<TreeNode*,int>> q;
		q.push({root,0});
		while(q.size()) {
			auto [n,cur] = q.front(); q.pop();
			cur = cur * 10 + n->val;
			if(n->left) q.push({n->left,cur});
			if(n->right) q.push({n->right,cur});
			if(!n->left && !n->right) sum += cur; // add to total sum 

		}
		return sum;
	}
};



// https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/1556417/C%2B%2BPython-Recursive-and-Iterative-DFS-%2B-BFS-%2B-Morris-Traversal-O(1)-or-Beats-100
