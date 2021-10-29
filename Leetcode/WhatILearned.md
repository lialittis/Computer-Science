# What I Learned From LeetCode [CPP]

## math

### << or >>

#### 2^i

```
int power = 0;
int value = 1;
for(...){
    power += 1;
    value += (1<<power); // which is actually +2^i
}
```

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

## queue

### priority_queue

```C++
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```

## lambda function

### cmp

```C++
auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
```


## Algorithms in <algorithm>

### swap

```C++
template<class T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
```

- Examples : 

```
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
```

- Remind : Quick Method for SWAP integer

```
int a = 17;
int b = 6;
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

### sort

It is quick, and often be used to sort vector.

```
sort(l.begin(),l.end());
```

#### overload operator <

In the type of element of that vector, we could redefine the operator, in order to
change the way of sorting. For example,

```
bool operator < (const TPoint& rhs) const {
    return time < rhs.time || (time == rhs.time && flag < rhs.flag); 
}
```

or

```C++
class Employee{
    int id;
    string name;
    string secName;

    bool operator<(Employee a, Employee b)
    {
        if (a.id < b.id) return true;
        if (a.id > b.id) return false;
        if (a.name < b.name) return true;
        if (a.name > b.name) return false;
        if (a.secName < b.secName) return true;
        return false;
    }
}

```
