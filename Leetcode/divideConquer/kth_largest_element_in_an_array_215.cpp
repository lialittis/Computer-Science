#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
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

class Solution2{
public:
    int findKthLargest(vector<int>& nums, int k){
    int left = 0, right = nums.size() -1;
    while(true){
      int position = partition(nums,left, right);
      if(position == nums.size() - k) {
        // for(auto num : nums){
        //   cout<<num<<endl;
        // }
        return nums[position];
      }
      if(position > nums.size() - k ) right = position -1;
      else left = position + 1;
    }
  }

  // partition the vector into three part
  // < pivot, =pivot, > pivot
  int partition(vector<int>& nums, int left, int right){
    int pivot = nums[right], l = left , wall = left;
    while(l < right) {
      if (nums[l] < pivot ){
        swap(nums[l], nums[wall++]);
      }
      ++l;
    }
    swap(nums[wall],nums[right]);
    return wall;
  }


// to avoid  the worst case:
    void shuffle(vector<int>& nums){
        /* initialize random seed: */
        srand (time(NULL));
        /* generate secret number between 1 and 10: */
        int iSecret = rand() % 10 + 1;
        for(int i = 0; i< nums.size(); i++){
            int j = rand()%(i+1);
            swap(nums[i],nums[j]);
        }
        
    }
// or randomly choose a value but not the rightest one as pivot
};


int main() {

}