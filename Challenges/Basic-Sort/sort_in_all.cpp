#include <vector>
#include <algorithm>

using namespace std;

class Sort{
public:
    // left included but not right
    void quick_sort(vector<int>& nums, int l, int r){
        if(l+1 >= r) return ;

        int first = l, last = r-1, tmp = nums[first];
        while(first < last) {
            while(first < last && nums[last] >= tmp) {
                --last;
            }
            nums[first] == nums[last];
            while(first < last && nums[first] <= tmp){
                ++first;
            }
            nums[last] = nums[first];
        }
        nums[first] = tmp;
        quick_sort(nums, l, first);
        quick_sort(nums,first+1,r);
    }

    void merge_sort(vector<int>& nums, int l, int r, vector<int>& temp){
        if(l + 1 >= r) return ;
        // divide
        int m = l + (r - l) / 2;
        merge_sort(nums, l,m,temp);
        merge_sort(nums, m, r, temp);

        //conquer
        int p = l, q = m, i = l;
        while(p < m || q < r) {
            if(q >= r || (p<m && nums[p] <= nums[q])){
                temp[i++] = nums[p++];
            } else{
                temp[i++] = nums[q++];
            }
        }

        for(i = l; i< r; ++i) {
            nums[i] = temp[i];
        }
    }

    // start from 0, and check all cards before current one, and do swap if not sorted
    void insertion_sort(vector<int> &nums, int n){
        for(int i = 0; i<n; ++i) {
            for(int j = i; j>0 && nums[j]<nums[j-1]; --j){
                swap(nums[j],nums[j-1]);
            }
        }
    }

    // start from 0 until the sorted ones, compare currect card and left card, do swap if needed, move the largest to the right
    // swapped is used to jump out of cycle once sorted before loop finishes
    void bubble_sort(vector<int>& nums, int n){
        bool swapped;
        for(int i = 1; i< n;i++){
            swapped = false;
            for(int j = 1; j <n-i+1;++j){
                if(nums[j] < nums[j-1]){
                    swap(nums[j],nums[j-1]);
                    swapped = true;
                }
            }
            if(!swapped){
                break;
            }
        }
    }

    // current start from 0,  read right cards of current one, take the smallest one(and smaller that current), and swap them
    void selection_sort(vector<int>& nums, int n){
        int mid;
        for(int i=0; i< n-1; i++){
            mid = 1;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[mid]){
                    mid = j;
                }
            }
            swap(nums[mid],nums[i]);
        }
    }
};


int main(){
    Sort sortClass;
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,4,0,7,5,4,2,5,6,1};
    vector<int> temp(nums.size());
    sort(nums.begin(),nums.end());
    sortClass.quick_sort(nums,0,nums.size());
    sortClass.merge_sort(nums,0,nums.size(),temp);
    sortClass.insertion_sort(nums,nums.size());
    sortClass.bubble_sort(nums,nums.size());
    sortClass.selection_sort(nums,nums.size());

}