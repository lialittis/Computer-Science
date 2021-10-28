#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/* First solution, merge sort, no good implementation */
class Solution1 {
public:
        // Ideas
    // sort + output the index
    // very slow and very expensive
    int findKthLargest(vector<int>& nums, int k) {
        /* merge sort */
        vector<int> res = mergesort(nums);
        // for(int x : res){
        //     cout << "ans :" << x<<endl;
        // }
        return res[k-1];
    }

    vector<int> mergesort(vector<int> nums) {
        if(nums.size() == 1) {
            return nums;
        }
        int left = nums.size()/2 -1 ;
        int right = left+1;

        vector<int> l1 = vector<int>(nums.begin(),nums.begin()+left+1);
        // cout<<"l1 size :"<<l1.size()<<endl;
        vector<int> l2 = vector<int>(nums.begin()+right,nums.end());
        // cout<<"l2 size :"<<l2.size()<<endl;
        return merge(mergesort(l1),mergesort(l2));
    }

    vector<int> merge(vector<int> l1, vector<int> l2){
        vector<int> l3;
        int i = 0, j = 0;
        for(; i < l1.size() && j < l2.size() ;){
            if(l1[i] > l2[j]){
                l3.push_back(l1[i]);
                i++;
            }
            else {
                l3.push_back(l2[j]);
                j++;
            }
        }
        if(i==l1.size()){
            for(;j<l2.size();j++){
                l3.push_back(l2[j]);
            }
        }else{
            for(;i<l1.size();i++){
                l3.push_back(l1[i]);
            }
        }

        for(auto x : l3){
            cout << " " <<x;
        }
        cout <<endl;
        return l3;
    }
};

/* sort in C++ STL */
class SolutionSTL{
public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};

/* priority_queue : max heap in C++ STL */
class SolutionSTL2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
};

/* Quick sort */
/* A good method, but takes too much time */
class SolutionOpt{
public:
  // watch the pivot and verify if it is the kth element
  // if yes, return; it not, remove the bounds;
  int findKthLargest(vector<int>& nums, int k){
    int left = 0, right = nums.size() -1;
    while(true){
      int position = partition(nums,left, right);
      if(position == k-1) return nums[position];
      if(position > k-1 ) right = position -1;
      else left = position + 1;
    }
  }

  // partition the vector into three part
  // > pivot, =pivot, < pivot
  int partition(vector<int>& nums, int left, int right){
    int pivot = nums[left], l = left + 1, r = right;
    while(l <= r) {
      if (nums[l] < pivot && nums[r] > pivot){
        swap(nums[l++], nums[r--]);
      }
      if (nums[l] >= pivot) ++l;
      if (nums[r] <= pivot) --r;
    }
    swap(nums[left],nums[r]);
    return r;
  }
};

int main(){
    vector<int> target{3,2,3,1,2,4,5,5,6};
    int k = 4;

    int output;

    Solution1 sol1;

    vector<int> sorted = sol1.mergesort(target);
    output = sorted[k-1];
// 32/32 cases passed (208 ms)
// Your runtime beats 5.03 % of cpp submissions
// Your memory usage beats 8.69 % of cpp submissions (58.9 MB)

    SolutionSTL solSTL;
    output = solSTL.findKthLargest(target,k);
// 32/32 cases passed (8 ms)
// Your runtime beats 79.79 % of cpp submissions
// Your memory usage beats 97.69 % of cpp submissions (9.9 MB)

    SolutionSTL2 solSTL2;
    output = solSTL2.findKthLargest(target,k);
// 32/32 cases passed (8 ms)
// Your runtime beats 79.79 % of cpp submissions
// Your memory usage beats 34.06 % of cpp submissions (10.2 MB)

    SolutionOpt solopt;
    output = solopt.findKthLargest(target,k);
// 32/32 cases passed (140 ms)
// Your runtime beats 8.38 % of cpp submissions
// Your memory usage beats 97.69 % of cpp submissions (9.8 MB)
    return output;
}

