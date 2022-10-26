/* Array Hashing */

/*
 * An integer array - nums
 * return true if any value appears at least twice in the array,
 * return false if every element is distinct
 *
 * */

// first idea : hash table
// O(n) & O(n)


#include <unordered_set>
#include <vector>

using namespace std;

class Solution{
public:
	bool containsDuplicate(vector<int> &nums){
		unordered_set<int> hash;

		for (int i = 0; i< nums.size(); ++i){
			if(hash.find(nums[i]) != hash.end()){
				return true;
			}
			hash.insert(nums[i]);
		}

		return false;
	}
};

// Keys :
// 1. unordered_set<*>
// 	- .insert O(1)
// 	- .find O(1)
// 	- .end()
