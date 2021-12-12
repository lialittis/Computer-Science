/* Easy */


/* return all paths in any order */

#include <vector>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x) , left(nullptr), right(nullptr) {};
    
};

/* First Try : DFS
 * Time : O(n)
 * Space : O(n) ?
 */

// iterative, using stack
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Paths.
// Memory Usage: 12.2 MB, less than 93.72% of C++ online submissions for Binary Tree Paths.
vector<string> returnAllPaths(TreeNode* root) {
    if(root == NULL) return {};

    vector<string> res{};
    stack<TreeNode*> s; // used to search node in the tree by DFS
    stack<string> pathStack; // used to update path in the tree by DFS
    s.push(root);
    pathStack.push(to_string(root->val));

    while(!s.empty()) {
        TreeNode* curNode = s.top();
        s.pop();

        string tmpPath = pathStack.top();
        pathStack.pop();

        if(curNode->left == NULL && curNode->right == NULL) {
            res.push_back(tmpPath); continue;
        }

        if(curNode->left != NULL) {
            pathStack.push(tmpPath+"->"+to_string(curNode->left->val));
            s.push(curNode->left);
        }

        if(curNode->right != NULL) {
            pathStack.push(tmpPath+"->" + to_string(curNode->right->val));
            s.push(curNode->right);
        }
    }

    return res;
}


/* Second method */

/* Using recursive way
 * 
 */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Paths.
// Memory Usage: 12.9 MB, less than 72.35% of C++ online submissions for Binary Tree Paths.

void dfs(TreeNode* node, string path, vector<string>& res) {
    if(node->left == NULL && node->right == NULL) {
        res.push_back(path); return;
    }

    if(node->left != NULL) {
        dfs(node->left, path + "->" + to_string(node->left->val), res);
    }

    if(node->right != NULL) {
        dfs(node->right,path + "->" + to_string(node->right->val),res);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    if(root == NULL) return {};

    vector<string> res;
    string path = to_string(root->val);
    dfs(root,path,res);

    return res;
}