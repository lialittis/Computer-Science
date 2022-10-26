/* Array ; */
#include <iostream>
#include <vector>

using namespace std;
/* Describtion:
 *
 * Follow up the first version, 
 * What if duplicates are allowed ?
 *
 * Whould this affect the run-time complexity ? How and why ?
 * Goal: determine if the given target is in the array
 * */


// The key is still to know if the mid is in ascending order or descending order

class Soluction1 
{
public:
	bool search(const vector<int>& nums, int target){
		int first = 0, last = nums.size();

		while(first != last){
			const int mid = first + (last - first) / 2;
			if(nums[mid] == target )
				return true;
			if(nums[first] < nums[mid]){
				// ss---p---ees
				//    ^
				if(nums[first] <= target && target < nums[mid])
					last = mid;
				else
					first = mid + 1;
			}else if (nums[first] > nums[mid]) {
				// ss---p---ees
				//        ^
				if (nums[mid] < target && target <= nums[last - 1])
					first = mid + 1;
				else
					last = mid;
			}else{
				// sss---p---eesss
				//   ^          ^
				first ++; // skip the duplicate ones
			}

			last = mid;
		}
		return false;
	}
};
