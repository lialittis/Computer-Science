# Binary Search

解决“从一堆数中找到指定数”的问题。

主要特征 ： 存储数组中； 有序排列

template

```
start = 0; end = len -1;
while(start <= end){
    mid = start +(e-s)/2;
    if(nums[mid]<target)
        start = mid + 1;
    else
        end = mid - 1;
}
// (end, start)
```

or
```
start = 0; end = len;
while(start < end){
    mid = start +(e-s)/2;
    if(nums[mid]<target)
        start = mid + 1;
    else
        end = mid;
}
// start == end
```

## median of two sorted array

Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.(O(log(m+n)))

### implementation

1. bad version O(mn)

merge two arrays, and sort them, take the median

2. binary search

## first bad version

### implementation

two pointers x and y;

```
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(!isBadVersion(mid)) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};
```


## split array largest sum

Given an array nums which consists of non-negative integers and an integer m, you can
split the array to m non-empty continuous subarrays.

二分法猜答案

## Others

1552

1482

1283

1292
