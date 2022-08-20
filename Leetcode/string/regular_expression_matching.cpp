/* string */

/* Implement regular expression matching with support for 
 * '.' and '*'
 *
 * */

/* 
 * Recursive method:
 *
 * It is hard to read only once and figure it out,
 * So we could use recursive way to check piece by piece
 *
 * O(n) time and O(1) space
 * The key is when next pattern is '*', which part we should consider it is in '*'
 *
 * 1. current char != current pattern, then we need go to the position after '*'
 * 2. current char == current pattern, do while loop, until not, then go to the position after '*'
 * */

//isMatch("aa","a") → false
//isMatch("aa","aa") → true
//isMatch("aaa","aa") → false
//isMatch("aa", "a*") → true
//isMatch("aa", ".*") → true
//isMatch("ab", ".*") → true
//isMatch("aab", "c*a*b") → true

#include <string>

using namespace std;

class SolutionRec{
public:
	bool isMatch(const string& s, const string& p){
		return isMatch(s.c_str(),p.c_str());
		// use string.c_str() convert string to char*
	}
private:
	bool isMatch(const char *s, const char *p){
		if (*p == '\0') return *s == '\0';

		// next char is not '*', then must match current character
		// ---c---  ---c.--
		if(*(p+1) != '*'){
			if(*p == *s || (*p == '.' && *s != '\0'))
				return isMatch(s+1,p+1);
			else return false;
		} else {// next char is '*'
			//---c---  ---c*--
			while(*p == *s || (*p == '.' && *s != '\0')){
				if(isMatch(s,p+2)) // check if s match part after *
					return true;
				s++;
			}
			return isMatch(s,p+2);
		}
	}

};

// Keys :
// 1. convert string reference into char pointer
// 2. recursive method


