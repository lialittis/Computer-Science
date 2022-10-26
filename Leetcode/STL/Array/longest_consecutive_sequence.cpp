/* Array */

/* Description :
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * [100, 4, 200, 1, 3, 2]
 *
 * in O(n) time complexity
 *
 * */

/* First Solution : 
 *
 * If it is allowed in O(nlogn) time, first sort the array and read the array
 *
 * */

/* Second Solution :
 *
 * to reach O(n) and also because it is in unsorted => using hash table, hash find is only in O(n)
 * record their occurrence and search its neighbors
 *
 * */


#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution_hash_table
{
public:
	int longestConsecutive(const vector<int>& nums){
		unordered_map<int, bool> used; // marking true to avoid re-count

		for (auto i: nums) used[i] = false; // initialization
		int longest = 0;
		for (auto i: nums){
			if (used[i]) continue;

			used[i] = true;

			int length = 1;

			// goto right
			for(int j=i+1; used.find(j) != used.end(); ++j){
				used[j] = true;
				++length;
			}

			// goto left
			for(int j =i - 1; used.find(i) != used.end(); --j){
				used[i] = true;
				++length;
			}

			longest = max(longest,length);
		}

		return longest;

	}


};


class Solution_clustering
{
public:
	// using unsorted map <int, int> to record the current consecutive length
	// and merge neighbor

}
















int main()
{

}

















