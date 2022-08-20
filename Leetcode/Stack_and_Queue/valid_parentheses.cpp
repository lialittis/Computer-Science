/* stack */

/* 
 * Valid Parentheses
 *
 * input string only contains ()[]{}
 * */

#include <string>
#include <stack>

using namespace std;

class Solution{
public:
	bool isValid(string const& s){
		string left = "([{";
		string right = ")]}";
		stack<char> stk;

		for(auto c:s){
			if(left.find(c) != string::npos) {
				stk.push(c);
			} else {
				if(stk.empty() || stk.top() != left[right.find(c)])
					return false;
				else
					stk.pop();
			}

		}

		return stk.empty();

	}
};

// Keys:
// 1. stack
// 2. string.find:
// 	The function returns the index of the first occurrence of sub-string,
// 	if the sub-string is not found it returns string::npos(string::pos 
// 	is static member with value as the highest possible for the size_t data structure).

