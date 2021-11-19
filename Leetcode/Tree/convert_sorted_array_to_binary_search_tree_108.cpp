#include <vector>
#include "treenode.h"

using namespace std;

class BST{
private:
    TreeNode* build(vector<int>& nums, int l, int r){
        if(l>r) return nullptr;
        int m = l + (r - l)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = build(nums,l,m-1);
        root->right = build(nums,m+1,r);
        return root;

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        return build(nums,0,nums.size() - 1);
    }
};

int main() {

}