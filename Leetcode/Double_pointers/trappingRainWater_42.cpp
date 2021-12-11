/* Hard */

/* n non-negative integers representing an elevation map where the width of each bar is 1
 * compute how much water it can trap after raining 
 */

#include <vector>
#include <stack>
#include <iostream>

using namespace std;


/* First method */

/* Using increasing monotonic stack, (not necessary , just one highest number to remark it)
 * remark the largest height, count the water by doing minus
 * note the current trapper, because if there is no higher or equal wall at its right, the water cannot be trapped
 * we need to do it in both side, because there could be some secarios with smaller trappers
 */

/* Self Test : 23 min */

/* Complexity
 * Time O(2*n)
 * Space O(1)
 */ 

// Runtime: 8 ms, faster than 80.90% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 15.5 MB, less than 97.30% of C++ online submissions for Trapping Rain Water.

int trap(vector<int> height) {
    int l = height.size();

    // stack<int> st;
    int highest = height[0];
    int cur=0, sum = 0; // IMPORTANT TO INITIALIZE
    for(int i = 1; i < l; ++i ){
        int h = height[i];
        if(highest > h){ // IMPORTANT : > from left to right
            cur += highest - h;
        }
        else {
            highest = h;
            sum += cur;
            cur = 0;
        }
    }

    cur = 0; 
    // reverse direction 
    highest = height[l-1];
    for(int i = l-2; i >=0; --i ){
        int h = height[i];
        if(highest >= h){ // IMPORTANT: < from right to left, because equal walls could be count twice
            cur += highest - h;
        }
        else {
            highest = h;
            sum += cur;
            cur = 0;
        }
    }

    return sum;
}

/* Second Method : Two Pointers for discussion of Leetcode */

// similar idea as I did, but faster.

int trap_2(vector<int> height) {
    int left = 0, right = height.size() -1;
    int sum = 0;
    int maxLeft = 0, maxRight = 0;

    while(left <= right) {
        if(height[left] <= height[right]) { // IMPORTANT TO START FORM THE SHORTER SIDE
            if(height[left] >= maxLeft) maxLeft = height[left];
            else sum += maxLeft - height[left];
            left ++;
        }
        else{
            if(height[right] >= maxRight) maxRight = height[right];
            else sum += maxRight - height[right];
            right--;
        }
    }

    return sum;
}

int main() {

    vector<int> test{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(test)<<endl;

    vector<int> test2{2,0,2};
    cout<<trap(test2) <<endl;

}