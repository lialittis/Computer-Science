/* Array */

/* Description:
 * 
 * a + b + c = 0 ? 
 *
 * non-descending order
 *
 * */


/* Solution :
 *
 * sort first,
 * converge from both sides
 *
 * ----> could be used for k-sum
 *
 * */


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public :
	vector<vector<int>> threeSum(vector<int>& nums){
		vector<vector<int>> result;

		if (nums.size() < 3) return result;
		const int target = 0;
		sort(nums.begin(), nums.end()); // O(nlogn)

		auto last = nums.end();

		for(auto i = nums.begin(); i < last - 2; ++i) {
			auto j = i+1;

			if (i>nums.begin() && *i == *(i-1)) continue; // skip the same number

			auto k = last -1;
			while(j < k){
				if(*i + *j + *k < target){
					++j;
					while(*j == *(j-1) && j< k) ++j;
				}else if(*i + *j + *k > target){
					--k;
					while(*k == *(k+1) && j < k) --k;
				}else{
					result.push_back({*i,*j,*k});
					++j;
					--k;
					while(*j == *(j-1) && *k == *(k+1) && j<k) ++j;
				}
			}

		}

		return result;

	}

}
