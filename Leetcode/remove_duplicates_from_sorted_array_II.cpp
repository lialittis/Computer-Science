/* array */

/* Question : Follow up for "Remove Duplicates" : 
 * What if duplicates are allowed at most twice */

// Key is to add a variable to record the occurrence of each number
// because the list is sorted, we only need one variable
// if it is unsorted, we need a hash map to do the job

#include <vector>
#include <iostream>

using namespace std;

/* First Solution
 * 
 * O(1) space, O(n) time
 * */
class Solution_standard{

	public:
		int removeDuplicates(vector<int>& nums){
			// edge case
			if(nums.size() <= 2) return nums.size();

			// two pointers
			int index = 2;
			for(int i = 2; i < nums.size(); i++){
				if(nums[i] != nums[index - 2])
					nums[index++] = nums[i];
			}
			return index;
		}
};

int main()
{

}
