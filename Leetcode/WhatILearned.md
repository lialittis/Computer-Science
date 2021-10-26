# What I Learned From LeetCode [CPP]

## vector

### concatenate two vectors

```
AB.reserve( A.size() + B.size() ); // preallocate memory
AB.insert( AB.end(), A.begin(), A.end() );
AB.insert( AB.end(), B.begin(), B.end() );
```


or

```
std::vector<int> AB = A;
AB.insert(AB.end(), B.begin(), B.end());
```

## TreeNode

### Structure

```
typedef struct TreeNode *tree;

struct TreeNode {
    int val;
    tree left;
    tree right;
    TreeNode(): val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x, tree left, tree right) : val(x), left(left), right(right) {}
};
```

### Functions useful


#### clone

```
/*Clone function*/
TreeNode* clone(TreeNode *root){
    if(root == nullptr){
        return nullptr;
    }
    TreeNode *newroot = new TreeNode(root->val);

    newroot->left = clone(root->left); // important
    newroot->right = clone(root->right); // important

    return newroot;
}
```
### Remarks

#### pointer

"=" between pointers means one same address, it could be used to move forward/deeper for
a (changable) tree; also, it could be used to store its value temporarily.

"clone" used to create a new variable with the same value but differen addresses.

