/* array */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Question : We only need the size of the new list */

/* Conclusion on the top :
 *
 * First method is slow, but it is also useful for unsorted arrays;
 *
 * Second\Third\Fourth methods are same in principle.
 *
 * */

/* One Naive method
 *
 * a table storing the appeared numbers 
 * + 
 * one time read 
 * + 
 * find(STL)
 *
 * O(n) space, O(nlogn) time */
class Solution_hash_table{
public:
	int removeDuplicates(vector<int>& nums) {
		// edge case
		if(nums.empty()) return 0;
		
		vector<int> res;
		for(auto n:nums){
			// if n doesn't exist
			if(find(res.begin(),res.end(),n) == res.end()){
				res.push_back(n);
			}
		}

		return res.size();
		
	}
};

/* Second Solution :
 * modifying the reference of original vector
 * by `two pointers`
 *
 * O(1) space, O(n) time
 * */
class Solution_modifing{
public:
	int removeDuplicates(vector<int>& nums){
		// edge case
		if(nums.empty()) return 0;

		// one index records all unique number
		// another index read the vector from the second number
		//
		int index = 0;
		for(int i = 1; i < nums.size(); i++){
			if(nums[index] != nums[i]){
				nums[++index] = nums[i];
			}
		}

		return index+1;
	}
};

/* Third Solution :
 * 
 * STL unique, distance
 *
 * O(1) space O(n) time
 * */
class Solution_STL{
public:
	int removeDuplicates(vector<int>& nums){
		return distance(nums.begin(),unique(nums.begin(),nums.end()));
	}
};

/* Forth Solution :
 *
 * STL distance, upper_bound
 * +
 * template function
 * 
 * O(1) space, O(n) time
 *
 * */
class Solution_Template{
public:
	int removeDuplicates(vector<int>& nums){
		return distance(nums.begin(),removeDuplicates(nums.begin(),nums.end(),nums.begin()));
	}

	template<typename InIt, typename OutIt> OutIt removeDuplicates(InIt first, InIt last, OutIt output){
		while(first != last){
			*output++ = *first;
			first = upper_bound(first,last,*first);
		}

		return output;
	}
};

int main(int argc, char* argv[])
{
	//vector<int> inputs {1,2,3,4,5,4,3,2,1};
	vector<int> inputs {1,1,2,2,3,3,4,4,4,5};

	Solution_hash_table sol1;
	Solution_modifing sol2;
	Solution_STL sol3;
	Solution_Template sol4;
	int ans1 = sol1.removeDuplicates(inputs);
	int ans2 = sol2.removeDuplicates(inputs);
	inputs = {1,1,2,2,3,3,4,4,4,5};
	for(auto n : inputs) cout<<n<<" ";
	cout <<endl;
	int ans3 = sol3.removeDuplicates(inputs);
	int ans4 = sol4.removeDuplicates(inputs);

	cout<<ans1<<endl;
	cout<<ans2<<endl;
	cout<<ans3<<endl;
	cout<<ans4<<endl;


	return 1;

}
