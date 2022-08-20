/* string */

//isMatch("aa","a") → false
//isMatch("aa","aa") → true
//isMatch("aaa","aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false
//

#include <string>

using namespace std;

/*
 * O(n!*m!) time
 * */

class SolutionRec{
public:
	bool isMatch(const string& s, const string& p){
		return isMatch(s.c_str(),p.c_str());
		// use string.c_str() convert string to char*
	}
private:
	bool isMatch(const char *s, const char *p){
		if(*p == '*'){
			while (*p=='*') ++p; // skip continuous '*'
			if(*p == '\0') return true; // if p ends
			// if p does not end
			while(*s != '\0' && !isMatch(s,p)) ++s;// move s until Match or end of s
			return *s != '\0';
		}
		else if (*p == '\0' || *s == '\0') return *p == *s; // end part
		else if (*p == *s || *p == '?') return isMatch(++s,++p); // equal or ?
		else return false;
	}
};


/* Iterative method */
class SolutionIte{
public:
	bool isMatch(const string& s, const string& p){
		return isMatch(s.c_str(),p.c_str());
		// use string.c_str() convert string to char*
	}
private:
	bool isMatch(const char *s, const char *p){
		bool star = false;
		const char *str, *ptr;

		for (str = s, ptr = p; *str != '\0'; str++, ptr++){
			switch(*ptr){
				case '?':
					break;
				case '*':
					star = true;
					s = str, p =ptr;
					while (*p == '*') p++; // skip continuous *
					// * to the end case
					if(*p == '\0') return true;
					
					// to keep current positions
					str = s - 1;
					ptr = p - 1;
					break;
				default:
					if(*str !=*ptr){
						if(!star) return false;
						s++;
						str = s - 1;
						ptr = p - 1;
					}
			}
		}

		while(*ptr == '*') ptr++;
		return (*ptr == '\0');

	}
};
