/* Hashing, bucket sorting */

/* Given an integer array nums and an integer k, 
 * return the k most frequent elements. You may return the answer in any order.
 * */

// Review target : 10 min O(n) & O(n)
// Finished in 9min 40seconds
// with a small bug of k--
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
	vector<int> kMostFreQuent(vector<int> nums, int k){
		// get a hash map for each element {key: element; value: freq}
		unordered_map<int,int> freq;
		int max_freq = 0;
		for(int i = 0; i<nums.size(); ++i) {
			max_freq = max(max_freq,++freq[nums[i]]);
		}

		// sort element by its freq : in vector
		vector<vector<int>> buckets(max_freq+1); // from 0 to max_freq
		for(auto it : freq){
			buckets[it.second].push_back(it.first);
		}

		// return elements as freq order, count the number
		vector<int> ans;
		while(k>0){
			for(auto i : buckets[max_freq--]){
				ans.push_back(i);
				k--;
			}
		}
		return ans;
	}
};
