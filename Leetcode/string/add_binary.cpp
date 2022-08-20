/* string */


/* Add binary
 * 
 * two binary string, return sum
 *
 * */


// two pointers, from right to left, do sum
// 1 + 1 = 10, 0 + 1 = 1, 0 + 0 = 0 => two conditions : change or not
// use one number to record the additional 1 from lower digit
// 1 + 1 + 1 = 11, 0 + 1 + 1 = 10, 0 + 0 + 1 = 1 => three conditions
// reverse need to be used
// after reversing, we only need one pointer from left to right
//
//
// A better formula:
// val = (a + b + carry) % 2
// carry = (a + b + carry) / 2

#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
	string addBinary(string a, string b){
		string result;
		const size_t n = a.size() > b.size() ? a.size() : b.size();

		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());

		int carry = 0;
		for(size_t i = 0; i< n; i++){
			const int ai = i < a.size() ? a[i] - '0' : '0'; // O(1) to get value of a[i]; another method is build a dictionary
			const int bi = i < b.size() ? b[i] - '0' : '0';

			const int val = (ai + bi + carry) % 2;
			carry = (ai + bi + carry) / 2;
			result.insert(result.begin(),val+'0');
		}
			
		if(carry == 1) {
			result.insert(result.begin(), '1');
		}

		return result;
	}
};
