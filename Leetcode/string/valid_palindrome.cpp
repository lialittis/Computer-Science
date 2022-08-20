/* String ; */

/* Valid Palindrome
 *
 * considering empty string as valid palindrome
 *
 * */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
	bool isPalindrome(string s){
		// turn all letters to lower cases
		// use <algorithm>, in O(n) time
		transform(s.begin(),s.end(),s.begin(), ::tolower);

		auto left = s.begin(), right = prev(s.end());

		while(left < right) {
			if(!::isalnum(*left)) ++left;
			else if (!::isalnum(*right)) --right;
			else if (*left != *right) return false;
			else { left++,right--;}
		}

		return true;
	}
};

/* 
 * O(n) time ; O(1) space
 *
 * Keys
 * 
 * 1. std::transform(InputIt,InputIt,OutputIt,UnaryOperaion)
 * 2. std::tolower(char c) : turn an uppercase letter to lowercase letter
 * 3. std::isalnum(int c) : c is either a decimal digit or an uppercase or lowercase letter
 * 4. prev(iterator)
 *
 * */

int main(){
	string test = "Yes,se;y";
	Solution sol;
	if(sol.isPalindrome(test)) cout<<"it is"<<endl;
	else cout<<"it is not"<<endl;

}
