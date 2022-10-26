/* Array */

/* Description: 
 *
 * 3 sum closest to a given number target
 *
 * */

/* Solution: 
 * 
 * sort firstly,
 *
 * then converge from both sides
 *
 * */

#include <vector>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h> // INT_MAX

using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target){
		int result = 0;
		int min_gap = INT_MAX; 

		sort(nums.begin(), nums.end());

		for(auto a = nums.begin(); a != prev(nums.end(),2); ++a ){  // prev(it,2)  == it - 2
			auto b = next(a); //next(a)  == a+1
			auto c = prev(nums.end());

			while(b<c){
				const int sum = *a + *b + *c;
				const int gap = abs(sum - target);

				if (gap < min_gap) {
					result = sum;
					min_gap = gap;
				}

				if(sum < target) ++b;
				else --c;
			}
		}
		return result;
	}

};

