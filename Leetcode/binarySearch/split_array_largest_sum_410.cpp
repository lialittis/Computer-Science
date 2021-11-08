#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution{
public:
    int splitArray(vector<int>& nums,int m){
        int sum;
        for(auto x : nums){
            sum += x;
        }
        int max = *max_element(nums.begin(),nums.end());
        return binary(nums,m,sum,max);
    }

    int binary(vector<int> nums, int m, int high, int low){
        int mid = 0;
        while (low <= high) {
            mid = low + (high - low) /2;
            if(valid(nums,m,mid)) high = mid -1;
            else low = mid + 1;
        }
        return low;
    }

    bool valid(vector<int> nums, int m, int subArraySum){
        int curSum = 0, count = 1;
        for(int num : nums){
            curSum += num;
            if(curSum > subArraySum){
                curSum = num;
                count++;
                if(count > m ) return false;
            }
        }
        return true;
    }
};