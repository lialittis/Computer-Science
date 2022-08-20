/* Array ; Binary Search */

#include <iostream>
#include <vector>

using namespace std;

/* Describtion :
 * a sorted array is rotated at some pivot unknown
 *
 * i.e., 0 1 2 4 5 6 7 => 4 5 6 7 0 1 2
 *
 * Goal : search a target value from this array
 *
 * */

/* First Solution 
 *
 * Binary Search + boundaries finding
 *
 * */

class SolutionBinarySearch
{
public:
	int search(const vector<int>& nums, int target){
		int first = 0, last = nums.size();

		/* Let's write a normal binary search for the moment */
		/*
		while(first != last){
			int mid = first + (last - first) /2;
			if(nums[mid] == target)
				return mid;
			if(nums[mid] > target)
				last = mid;
			else
				first = mid+1;
		}
		*/

		// there would be un issue of order
		// TO solve this, add steps to track the pivot
		// s---p---b
		//   ^ ^ ^
		
		while(first != last){
			int mid = first + (last - first) / 2;
			if(nums[mid] == target)
				return mid;
			if(nums[mid] >= nums[first]){
				// s---p---b
				//   ^
				if(nums[first] <= target && target < nums[mid])
					last = mid; // goto left
				else
					first = mid + 1; // goto right
			} else {
				// s---p---b
				//       ^
				if(nums[last-1] >= target && nums[mid] < target)
					first = mid+1;
				else
					last = mid;
			}
		}

		return -1;
	}

};


int main()
{
	const vector<int> nums {3,4,5,7,1,2};
	
	SolutionBinarySearch sol;
	int ans1 = sol.search(nums,1);
	int ans2 = sol.search(nums,3);
	int ans3 = sol.search(nums,6);
	cout << ans1 <<endl;
	cout << ans2 <<endl;
	cout << ans3 <<endl;
}
