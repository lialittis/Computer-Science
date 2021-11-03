# BFS

## symmetric tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Follow up: Could you solve it both recursively and iteratively?

### noise

*BFS* : using TreeNode structure

1. iteratively : with one queue (or two queues)


- verify root
- add root->left and root->right to queue
- while(queue!=empty)
  - if only one left or right is null => return false
  - if both are null => continue
  - if both are not null
    - push left->left, right->right,left->right, right->left into queue (in order)
- return true

2. recursively : DFS

- verify root
- build check (l, r) function
- check root->left and root->right
  - check (root->left)->left and (root->right)->right
    and check (root->right)->left and (root->left)->right

## binary tree level order traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

output : <vector<vector<int>>

### noise

queue + vectors, using count to count the number of each level

## binary tree zigzag level order traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

## noise

1. queue + vectors

- while queue is not empty
  - size of queue
  - create a vector and initialize its size
  - for this level of queue, loop it
    - if left to right : vector[i] = queue.front()
    - if right to left : vector[size- i - 1] = queue.front()
    - add left and right to queue

2. deque + vectors

- while deque is not empty
  - count of current deque (size)
  - while count > 0
    - if left to right, push deque.front() to current vector ; deque pop front; push childrens to back;
    - else, push deque.back() to current vector; deque pop back and push childrens to front;
    - count --
  - push current vector to total vector
  - reverse the direction

## minimum depth of binary tree

Given a binary tree, find its minimum depth.
