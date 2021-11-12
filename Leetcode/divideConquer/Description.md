# Divide and Conquer

## Master Theory

T(n) = a*T(N/b) + O(n^d)

## majority element

Given an array of size n, find the majority element.

appear > n/2 times

### implementation

opt : 投票法 O(n), 无空间O(1)


hashmap : 占用空间


分治：O(nlgn)

## pow

O(lgn)


## kth largest element in an array

find the kth largest element in an unsorted array

### implementation

1. sort

O(nlgn)

2. pq

O(nlgn)

3. divide and conquer

quick sort

pivot !!!

O(N + N/2 + N/4 + ... 1) = O(2N - 1)

O(N) average ; O(N^2) worst

To avoid the worst case, we need to use random tools.



