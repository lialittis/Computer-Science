

/*
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
 * with the colors in the order red, white, and blue.
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * You must solve this problem without using the library's sort function.
 *
 *
 * */


#include <vector>

using namespace std;

class Solution{ // finished in 6min 29seconds
public:
	// this is not actually a hash problem
	// it could be considered as a swap problem
	void sortColors(vector<int> &colors){
		// in-place
		int n = colors.size();
		int i = 0,left = 0, right = n-1;

		while(i<=right){
			if(colors[i] == 0){
				swap(colors[i++],colors[left++]);
			}else if(colors[i]==2){
				swap(colors[i],colors[right--]);
			}else
				i++;
		}
	}
};
