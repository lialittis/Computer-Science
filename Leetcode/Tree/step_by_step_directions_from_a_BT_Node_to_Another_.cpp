/* VIP */


/* Find shorest path from one node to another */

/* first try :
 * basic idea is that find their lca and load the path
 * implementation := find lca first, then search the two node , finally change the start path to UUU
 */

#include "treenode.h"
#include <string>
#include <stack>
#include <queue>

using namespace std;

// note that, 

TreeNode* lca(TreeNode* root, int startValue , int endValue) {
    if(root == nullptr) return nullptr;
    if(root->val == startValue || root->val == endValue ) return root;

    TreeNode* left = lca(root->left, startValue, endValue);
    TreeNode* right = lca(root->right, startValue, endValue);

    if(left && right) return root;

    if(left) return right;
    return left;
}

int Path(TreeNode* root, int target, string& path){
    if(!root) return 0;

    if(root->val == target ) return 1;

    path.push_back('L');
    int flag = Path(root->left, target, path);
    if(flag) return 1;
    else path.pop_back();

    path.push_back('R');
    flag = Path(root->right, target,path);

    if(flag) return 1;
    else path.pop_back();

    return 0;
}

string shortestPathToAnother(TreeNode* root, int startValue , int endValue) {
    

    TreeNode* lcaNode = lca(root, startValue, endValue);
    string p1 = "", p2 = "";
    Path(lcaNode,startValue,p1);
    Path(lcaNode,endValue,p2);

    for(int i = 0; i< p1.size(); ++i) {
        p1[i] = 'U';
    }
    p1.append(p2);
    return p1;
}

