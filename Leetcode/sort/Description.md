# sort methods

bubble sort, insertion sort, selection sort, shell sort, 
quick sort, merge sort, heap sort, counting sort, bucket sort, 
radix sort*pancake sort

the most important keys :
merge sort; quick sort(quick select); bucket sort; counting sort; heap sort

## bubble sort

核心是相邻的两个元素互相交换位置，基本模板

```
for i
    for j
        swap
```

O(n^2)

## selection sort

核心是观察每个element,找到最小元素放到头部
```
for i 0-size
    for i+1-size
        compare
    swap
```

## insertion sort

核心是把每个元素插入到应该有的位置上，类似于摸牌； 依次读取，判断是否在正确位置
```
for i: 0-size
    temp = cur[i]
    j = i
    while(j>0 && cur[j-1] >temp) // compare this with the previous ones
        push the previous one to the current position
        j--
    push temp to the j position
```

O(N^2)

## shell sort

核心是每隔一定位置gap选择两个element进行insertion sort,然后递减gap

O(N^2)

## quick sort !!!

核心： pivot !!!

On average O(nlogn), worst O(n^2)

Space: O(logn)

how to solve the worst case : 
1. shuffle the array first before sort
2. pick pivot randomly

```pseudo code
quickSort(array, leftmostIndex, rightmostIndex)
  if (leftmostIndex < rightmostIndex)
    pivotIndex <- partition(array,leftmostIndex, rightmostIndex)
    quickSort(array, leftmostIndex, pivotIndex - 1)
    quickSort(array, pivotIndex, rightmostIndex)

partition(array, leftmostIndex, rightmostIndex)
  set rightmostIndex as pivotIndex
  storeIndex <- leftmostIndex - 1
  for i <- leftmostIndex + 1 to rightmostIndex
  if element[i] < pivotElement
    swap element[i] and element[storeIndex]
    storeIndex++
  swap pivotElement and element[storeIndex+1]
return storeIndex + 1
```
## merge sort

核心是分成两半分别进行sort，然后依次merge

```
divide:O(nlogn)
    left >= right return one element
    mid <- middle point
    divide left to mid
    divide lid to right
    merge result from two sides

merge: O(n)
    new array to store
    read all elements from two sides and add them together
```

O(nlogn)

## heap sort

1. Heap conception

2. Heapify : to make a heap

T(n) = O(n)

 

3. Heap sort
