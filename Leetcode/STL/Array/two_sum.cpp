/* Array */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/* First Method : brute force O(n^2)*/


/* Second Method : hash table, store index of each number, O(n) */


/* Third Method(not working in returning index case) :
 *
 * sort firstly, O(nlogn)
 * then converge from both sides O(n)
 *
 * */

class Solution_hash
{
public:
	vector<int> twoSum(vector<int> &nums, int target){
		unordered_map<int, int> mapping;

		vector<int> result;
		// set index
		for (int i=0;i<nums.size(); i++){
			mapping[nums[i]] = i;
		}

		// search
		for(int i = 0; i < nums.size(); i++) {
			const int gap = target - nums[i];
			if(mapping.find(gap) != mapping.end() && mapping[gap] > i) {
				result.push_back(i+1);
				result.push_back(mapping[gap] + 1);
				break;
			}
		}

		return result;

	}
		
};



int main()
{


}
