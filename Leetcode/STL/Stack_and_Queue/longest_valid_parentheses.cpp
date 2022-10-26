/* stack */

/* 
 * Longest valid parentheses : 
 *
 * input strings only constains ()
 *
 *
 * */


// Use stack
// O(n) time O(n)space


#include <string>
#include <stack>

using namespace std;

class SolutionStack{
public:
	int longestValidParentheses(const string& s){
		int max_len = 0, last = -1; // the position of the last ')'

		stack<int> lefts; // keep track of the positions of non-matching '('s

		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '('){
				lefts.push(i);
			} else {
				if(lefts.empty()){
					// no matching left
					last = i;
				} else {
					// find a matching pair
					lefts.pop();
					if(lefts.empty()){
						max_len = max(max_len,i-last);
					}else{
						max_len = max(max_len,i-lefts.top());
					}
				}
			}
		}
		return max_len;
	}
};



// Dynamic Programming
// O(n) time, O(n) space

#include <vector>

class SolutionDP1{
public:
	int longestValidParentheses(const string& s){
		vector<int> f(s.size(), 0); // initialization
		int ret = 0;
		for(int i = s.size() - 2; i >=0; --i){
			int match = i + f[i+1] + 1;

			if (s[i] == '(' && match < s.size() && s[match]==')'){
				f[i] = f[i+1] + 2;
				if(match + 1 < s.size()) f[i] += f[match + 1];
			}
			ret = max(ret,f[i]);
		}
		return ret;
	}
};

/* 
 * Another DP : jerryrcwong in leetcode
 *
 * The main idea is as follows: 
 * I construct a array longest[], for any longest[i], 
 * it stores the longest length of valid parentheses which is end at i.
 * And the DP idea is :
 * If s[i] is '(', set longest[i] to 0,
 * because any string end with '(' cannot be a valid one.
 * Else if s[i] is ')'
     If s[i-1] is '(', longest[i] = longest[i-2] + 2
     Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', 
     longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]
 * For example, input "()(())", at i = 5, 
 * longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.
 * */

class SolutionDP2{
public:
	int longestValidParentheses(const string& s){
		int curMax = 0;
		vector<int> longest(s.size(),0);

		for(int i = 1; i < s.size(); i++){
			if(s[i]==')'){
				if(s[i-1] == '(')
					longest[i]  =(i-2>=0)? longest[i-2] + 2 : 2;
				else if (i-longest[i-1]-1 >=0 && s[i-longest[i-1]-1]=='('){
					longest[i] = longest[i-1]+2+ ((i-longest[i-1]-2>=0)? longest[i-longest[i-1]-2]:0);
				}
				curMax = max(curMax,longest[i]);
			}
		}
		return curMax;
	}
};





