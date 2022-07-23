# What I Learned From LeetCode [CPP]

# Ref 
LeetCode刷题解题答案.pdf

## Programming Skills

1. `fabs(a - b) < 1e-9` | `a==b`

when you want to compare two floats, please don't use `a==b`,
but `fabs(a-b)` a small boundary.

2. `n % 2 != 0` | `n % 2 == 1`

odd numbers could be judged by both;
negative odd numbers should only use the first formula.

3. `n & 1` & `n % 2 !=0`

they are equal.

4. `char` could be negative

if you want to use `char` as indice of an array, e.g. counting
characters' apprearances, we should transfer them to `unsigned
char` and then use as indice.

5. `vector` and `string` structure are priory than dynamic 
allocated `array` structure

`vector` is continuous in memory;
if using `new` for array, you have to remember `delete`;
multiple dynamic arrays need `new` them one by one, while 
`vector` does the job in one line.

## Linear Tables

### ListNode

```
ListNode* output = new ListNode(0);
ListNode output = ListNode(0);
```

## math

### `<<` or `>>`

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

### special vector<bool>

作为一个 STL 容器，vector<bool> 确实只有两个问题：　　

1. 它不是一个STL容器　　
2. 它并不容纳 bool

因为vector<bool> 打包 bool 以节省空间，每个保存在“vector”中的“bool”占用一个单独的bit，而禁止有指向单个比特的指针，所以vector<bool>不能编译下式：

vector<bool> v; 2 bool *pb = &v[0];　　// 使用 vector<bool>::operator[] 返回的东西的地址初始化一个bool*

标准库提供了两个替代品，它们满足几乎所有的需求:

1. 第一个是deque<bool>　　deque提供了几乎多有vector所提供的，而且deque<bool> 保存真正的bool值

2. bitset。　　bitset 不是STL容器，是C++标准库的一部分，大小在编译期固定，因此不支持插入和删除元素，不是迭代器，不支持iterator。压缩表示，每个值只占用一比特。提供vector<bool> 特有的 flip 成员函数，还有一些列其他操作位集所特有的成员函数。如果不在意没有迭代器和动态改变大小，bitset正合适。


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

### to use in priority_queue

它的模板声明带有三个参数，priority_queue<Type, Container, Functional>
Type 为数据类型， Container 为保存数据的容器，Functional 为元素比较方式。
Container 必须是用数组实现的容器，比如 vector, deque 但不能用 list.
STL里面默认用的是 vector. 比较方式默认用 operator< , 所以如果你把后面俩个
参数缺省的话，优先队列就是大顶堆，队头元素最大。
看例子

```
priority_queue<int> qi;

    int a[len] = {3,5,9,6,2};

    priority_queue<int> qi;
    for(i = 0; i < len; i++)
        qi.push(a[i]);

    for(i = 0; i < len; i++)
    {
        cout<<qi.top()<<" ";
        qi.pop();
    }
```
通过<操作符可知在整数中元素大的优先级高。
故例子中输出结果为：9 6 5 3 2

```C++
// using lambad to compare elements
// make a heap with top of earliest finished meeting currently
auto comp = [](Interval i1, Interval i2) {return i1.end > i2.end; };
priority_queue<Interval,vector<Interval>, decltype(comp)> heap(comp);
```
和队列基本操作相同:

top 访问队头元素
empty 队列是否为空
size 返回队列内元素个数
push 插入元素到队尾 (并排序)
emplace 原地构造一个元素并插入队列
pop 弹出队头元素
swap 交换内容

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

1、sort函数可以三个参数也可以两个参数，必须的头文件#include < algorithm>和using namespace std;
2、它使用的排序方法是类似于快排的方法，时间复杂度为n*log2(n)
3、Sort函数有三个参数：（第三个参数可不写）
（1）第一个是要排序的数组的起始地址。

（2）第二个是结束的地址（最后一位要排序的地址）

（3）第三个参数是排序的方法，可以是从大到小也可是从小到大，还可以不写第三个参数，此时默认的排序方法是从小到大排序。


```C++
// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }//升序排列
bool myfunction2 (int i,int j) { return (i>j); }//降序排列

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
    int myints[8] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
    //std::sort (myints,myints+8,myfunction);不用vector的用法
    
  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)//输出
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
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
