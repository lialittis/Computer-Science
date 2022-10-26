1. Sequence Containers：维持顺序的容器。
(a). vector：动态数组，是我们最常使用的数据结构之一，用于 O(1) 的随机读取。因为大
部分算法的时间复杂度都会大于 O(n)，因此我们经常新建 vector 来存储各种数据或中
间变量。因为在尾部增删的复杂度是 O(1)，我们也可以把它当作 stack 来用。
(b). list：双向链表，也可以当作 stack 和 queue 来使用。由于 LeetCode 的题目多用 Node 来
表示链表，且链表不支持快速随机读取，因此我们很少用到这个数据结构。一个例外
是经典的 LRU 问题，我们需要利用链表的特性来解决，我们在后文会遇到这个问题。
(c). deque：双端队列，这是一个非常强大的数据结构，既支持 O(1) 随机读取，又支持 O(1)
时间的头部增删和尾部增删，不过有一定的额外开销。
(d). array：固定大小的数组，一般在刷题时我们不使用。
(e). forward_list：单向链表，一般在刷题时我们不使用。

2. Container Adaptors：基于其它容器实现的数据结构。
(a). stack：后入先出（LIFO）的数据结构，默认基于 deque 实现。stack 常用于深度优先搜
索、一些字符串匹配问题以及单调栈问题。
(b). queue：先入先出（FIFO）的数据结构，默认基于 deque 实现。queue 常用于广度优先
搜索。
(c). priority_queue：
最大值先出的数据结构，
默认基于 vector 实现堆结构。它可以在 O(n log n)
的时间排序数组，O(log n) 的时间插入任意值，O(1) 的时间获得最大值，O(log n) 的时
间删除最大值。priority_queue 常用于维护数据结构并快速获取最大或最小值。

3. Associative Containers：实现了排好序的数据结构。
(a). set：有序集合，元素不可重复，底层实现默认为红黑树，即一种特殊的二叉查找树
（BST）。它可以在 O(n log n) 的时间排序数组，O(log n) 的时间插入、删除、查找任
意值，O(log n) 的时间获得最小或最大值。这里注意，set 和 priority_queue 都可以用
于维护数据结构并快速获取最大最小值，但是它们的时间复杂度和功能略有区别，如
priority_queue 默认不支持删除任意值，而 set 获得最大或最小值的时间复杂度略高，具
体使用哪个根据需求而定。
(b). multiset：支持重复元素的 set。
(c). map：有序映射或有序表，在 set 的基础上加上映射关系，可以对每个元素 key 存一个
值 value。
(d). multimap：支持重复元素的 map。

4. Unordered Associative Containers：对每个 Associative Containers 实现了哈希版本。
(a). unordered_set：哈希集合，可以在 O(1) 的时间快速插入、查找、删除元素，常用于快
速的查询一个元素是否在这个容器内。
(b). unordered_multiset：支持重复元素的 unordered_set。
(c). unordered_map：哈希映射或哈希表，在 unordered_set 的基础上加上映射关系，可以对
每一个元素 key 存一个值 value。在某些情况下，如果 key 的范围已知且较小，我们也
可以用 vector 代替 unordered_map，用位置表示 key，用每个位置的值表示 value。
(d). unordered_multimap：支持重复元素的 unordered_map。
因为这并不是一本讲解 C++ 原理的书，更多的 STL 细节请读者
