// binary search


#include <vector>
#include <math.h>
#include <stdlib.h>
#include <climits>
#include <algorithm>
using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int> numsX, vector<int>numsY){
        if(numsX.size() > numsY.size() ) return findMedianSortedArrays(numsY,numsX);
        int left = 0, right = numsX.size();
        while (left <= right)
        {
            int x = left + (right - left)/2;
            int y = (numsX.size() + numsY.size()+1)/2 - x;
            int xLeft = (x==0) ? INT_MIN : numsX[x-1];
            int xRight = (x == numsX.size()) ? INT_MAX: numsX[x];
            int yLeft = (y==0) ? INT_MIN : numsY[y - 1];
            int yRight = (y==numsY.size()) ? INT_MAX : numsY[y];
            if(xLeft <= yRight && yLeft <= xRight){
                if((numsX.size()+numsY.size()) %2 == 0){
                    return (double)(max(xLeft,yLeft) +min(xRight,yRight))/2;
                }
                else return (double)max(xLeft,yLeft);
            }
            else if(xRight > yLeft) right = x-1;
            else left = x +1;
        }
        return -1;
    }
};









// Self - Test

class SolutionTest{
public: // The overall run time complexity should be O(log (m+n)).
	double findMedianSortedArraysBySort(vector<int> nums1, vector<int>nums2){ // in 4 mins
		/* First method : merge and sort*/
		nums1.insert(nums1.end(),nums2.begin(),nums2.end());
		sort(nums1.begin(),nums1.end());

		int n = nums1.size();
		if(n%2 != 0){
			return (double)nums1[(n-1)/2];
		}else{
			return ((double)nums1[(n-1)/2] + (double)nums1[(n-1)/2 + 1]) / 2;
		}
	}

	double findMedianSortedArraysByBS(vector<int> nums1, vector<int>nums2){
		/*Second Method: binary search + kth*/

		// understand this question as find kth smallest element in two sorted arrays
		int m = nums1.size(), n = nums2.size();
		if((m+n)%2!=0)
			return kth(nums1,nums2,(m+n-1)/2);
		else
			return (kth(nums1,nums2,(m+n-1/2))+ kth(nums1,nums2,(m+n-1)/2+1))/2;
	}

private:
	double kth(vector<int> nums1, vector<int>nums2, int k){
		int m = nums1.size(), n = nums2.size();
		if(m > n) return kth(nums2,nums1,k); // make sure nums1 is shorter that nums2
		int cut1 = 0, cut2 = 0;

		// valid conditions :
		// 1. cut1 + cut2 = k
		// 2. nums1[cut1] < nums2[cut2+1]
		// 3. nums2[cut2] < nums1[cut1+1]

		// for nums1 : cut1 [0,m-1]
		int left = 0, right = m-1;
		while(left <= right){
			cut1 = (left + right) >> 1;
			cut2 = k - cut1;
			if(nums1[cut1] <= nums2[cut2+1] && nums2[cut2] <= nums2[cut1+1]) break;
			if(nums1[cut1] > nums2[cut2+1])
				right = cut1 -1;
			else if(nums2[cut2] > nums1[cut1+1]) // because this can not happen at the same time as last condition
				left = cut1 + 1;
		}

		return max(nums1[cut1],nums2[cut2]);
	}
};







