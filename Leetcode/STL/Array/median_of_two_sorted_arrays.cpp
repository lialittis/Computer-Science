/* Array */

#include <vector>
#include <iostream>

using namespace std;

/* Describtion
 * 
 * A and B of size m and n
 *
 * Goal : fin the median of the two sorted arrays
 *
 * in O(log(m+n)) run time complexity
 * */


// Remark : a more general version, find the k largest element


/* First solution :
 * "merge" two arrays and find the k largest element
 *
 * merge sort is not needed, we could use two pointers to realize the
 * search
 *
 * in O(k) time and O(1) space
 * when k is close to m+n, then the time using is O(m+n)
 * */


/* Second Solution :
 *
 * take advantage of sorted order
 * compare the first k/2 element's value of two arrays
 * using iterative way
 *
 * */


class Solution_Iterative
{
public:
	double findMedianSortedArrays(const vector<int>& A, const vector<int>&B){
		const int m = A.size();
		const int n = B.size();
		int total = m + n;

		if(total & 0x01){// total is odd
			return find_kth(A.begin(),m,B.begin(),n,total / 2 + 1);
		} else{
			return (find_kth(A.begin(),m,B.begin(),n,total/2)
					+ find_kth(A.begin(),m,B.begin(),n, total/2+1)) / 2.0;

		}
	}

private:
	static int find_kth(vector<int>::const_iterator A, int m,
			vector<int>::const_iterator B, int n,int k){
		// always assume that m is equal or smaller than n

		if(m > n) return find_kth(B,n,A,m,k);
		if(m==0) return *(B+k-1);
		if(k==1) return min(*A,*B);
			

		// devide k into two parts

		int ia = min(k/2,m), ib = k -ia;
		if(*(A + ia -1) < *(B+ib-1))
			return find_kth(A+ia,m-ia,B,n,k-ia);
		else if(*(A+ia-1) > *(B+ib-1))
			return find_kth(A,m,B+ib,n-ib,k-ib);
		else
			return A[ia-1];

	}


}
