/* Medium Two pointers */

/* product of numbers, O(n)
 *  
 */


#include <vector>

using namespace std;

/* First Try :
 * product of all numbers / current number
 * special case : cur is 0; 1. how many 0 2. recalculate
 * Time O(n)
 * Space O(n)
 */

// Runtime: 20 ms, faster than 88.11% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 24 MB, less than 79.74% of C++ online submissions for Product of Array Except Self.

vector<int> productExceptSelf(vector<int>& nums) {
    int nZeros = 0, index = 0;
    int prodAll = 1;

    int i = 0;
    for(auto n : nums) {
        if(n==0) {
            nZeros++;
            index = i;
        }
        else prodAll *= n;
        i++;
    }

    if(nZeros>1) return vector<int>(nums.size(),0);

    vector<int> res(nums.size());
    if(nZeros == 1) {
        for(int i = 0; i<nums.size(); ++i) {
            if(i==index) {
                res[i] = prodAll;
            }
            else res[i] = 0;
        }
    }
    else{
        for(int i=0; i<nums.size(); ++i) {
            res[i] = prodAll / nums[i];
        }
    }
    return res;

}

/* Second Method from discussion of Leetcode 
 * From begin and from end
 */

vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> fromBegin(n);
    fromBegin[0]=1;
    vector<int> fromLast(n);
    fromLast[0]=1;
    
    for(int i=1;i<n;i++){
        fromBegin[i]=fromBegin[i-1]*nums[i-1];
        fromLast[i]=fromLast[i-1]*nums[n-i];
    }
    
    vector<int> res(n);
    for(int i=0;i<n;i++){
        res[i]=fromBegin[i]*fromLast[n-1-i];
    }
    return res;
}

/* optimization : without extra space */
vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    int fromBegin=1;
    int fromLast=1;
    vector<int> res(n,1);
    
    for(int i=0;i<n;i++){
        res[i]*=fromBegin;
        fromBegin*=nums[i];
        res[n-1-i]*=fromLast;
        fromLast*=nums[n-1-i];
    }
    return res;
}