# Data Structure

## Most used

Array, String, Linked List, Tree(BT, BST), Stack, Queue,
PriorityQueue(Heap), HashMap, HashSet

## Less used

Trie, Disjoint-Set(Union Find), Deque, Graph

## Rarely used

TreeMap, TreeSet;
Segment Tree, Binary Index Tree

## Array

continuously in memory, has index, start from 0

Pro: fast to find by index, fast to loop the whole array by indexes

Cons: size is fixed after intialization, data type is fixed, slow to add or delete elements because of moving the other elements

Used in senarios : frequent to find, no strict requirements for storage size, non-frequent to add or delete

## String : non-primitive data type(in Java)

primitive type : boolean, int, char, double, long, byte, short, float (in Java)

non-primitive data type in Java: Strings, Arrays, Classes, Interfaces

## Linked List

non-continuously in memory, val + pointer

pros: fast to assign; don't need to initialize ; fast to add or delete element;

cons: take much space to store because of pointers; slow to find element;

used in senarios: small data set; frequent to add and delete

## Tree

limited node, level relation data structure, root on top, leafs on bottom; value + left + right

Binary Tree is one special tree - every node could have two nodes at most; values in order for left child and right child

## Trie : prefix tree or dictionary tree or key tree

multiple branches tree (Trie is like a N-array Tree):
- root has no value(char), all others have one (char) for each
- read from any path from root to leaf, there is one string
- every children for each node has different values

## Stack : LIFO, FILO

linear table, operations work on one end of data

## Queue : FIFO

Linear table, add in one end but take in another end

used usually for BFS

## Deque : DOuble-ended queue

## PriorityQueue : Heap

data structure like a BT;

Max Heap : every parent node is larger than children

Min Heap : everty parent node is smaller than children

to add element : O(logn) ; to push element: O(logn) ; to pop element : O(logn)

## Map : HashTable / HashMap

use unique key and value to visit the data; store position by f(key);

pros : fast to add, delete and find (O(1))

How to deal with collisions : 1. separate Chaining; 2. open addressing

## Set : (Java HashSet)

Not allow replicated elements, no graduatee for order of element, allow one null element in set

## TreeMap : (Java only)

## Disjoint-Set (Union Find)

similar with tree structure, deal with union and find question; is a data sturcture that keeps track of elements which are split into one or more disjoint sets.

Find : confirm which subset the element belongs to, can be used to confirm that if there are two elements belong to same subset; O(logn)

Union: union two sub sets; O(logn)

Optimization !!!

## Graphy

one to one; one to multiple; multiple to multiple; undirected, directed (cyclic, acylic); adjacted table, adjact matrix;

Vertex/node + edge

Using BFS,DFS

## segment tree

## binary index tree(fenwick tree)

## Summary

basic structure -> algo

graph -> search method

dp

