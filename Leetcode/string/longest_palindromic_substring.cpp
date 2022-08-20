/* string */

/* 
 * Find the longest palindromic substring in a given string
 *
 * */

#include <string>
#include <iostream>
using namespace std;


// brute force
// start from each character, depart from both sides
// O(n^2)

// One problem : two forms of palindrome "aa" and "aba". !!!
// I didn't consider "aa" in the following program
class SolutionbruteForce{
public:
	string longestPalindrome(string const& s){
		const int size = s.size();
		int longest = 0;
		string res,curP;
		for(int i = 0; i< size; i++){
			curP = searchPalindrome(s,i);
			if(curP.size() > longest){
				longest = curP.size();
				res = curP;
			}
		}

		return res;
	}

private:
	string searchPalindrome(string const& s, int center){
		string palindrome;
		palindrome.insert(palindrome.begin(),s[center]);
		int l = center - 1,r = center + 1;
		while(l >=0 && r < s.size() ){
			if(s[l] == s[r]){
				palindrome.insert(palindrome.begin(),s[l--]);
				palindrome.insert(palindrome.end(),s[r++]);
			}
			else
				break;
		}
		return palindrome;
	}

};


/* 
 * Second Method
 *
 * A memorized method helps to remember the previous palindrome string
 *
 * f[i][j] stands for the longest palindrome string in s:
 * f[i][j] = 
 * 	if (i==j) S[i]
 * 	if (s[i] == S[j] && f[i+1][j-1] == S[i+1][j-1]) S[i][j]
 * 	else max(f[i+1][j-1], f[i][j-1],f[i+1][j])
 *
 * It is not a very good method
 * */

class SolutionMemorized{
public:
	
};

/* Dynamic Programming
 *
 * State Transformaion Function
 *
 * f(i,j) = 	true, i = j
 * 		S[i] = S[j], j = i+1
 * 		S[i] = S[j] and f(i+1,j-1), j > i+1
 * 		
 *
 * O(n^2) time, and O(n^2) space
 * */

class SolutionDP{
public:
	string longestPalindrome(string const&s){
		const int n = s.size();
		bool f[n][n]; // definition of 2D array
		fill_n(&f[0][0], n * n, false); // initialization
		// REMARK : use vector will over time
		// vector<vector<bool>> f(n,vector<bool>(n,false));
		
		size_t max_len = 1, start = 0;

		for(size_t i = 0; i < s.size(); i++){
			f[i][i] = true;
			for(size_t j = 0; j < i; j++) {
				// [j,i]
				f[j][i] = (s[j]==s[i] && (i-j < 2 ||
							f[j+1][i-1]));
				if(f[j][i] && max_len < (i - j + 1)){
					max_len = i - j + 1;
					start = j;
				}
			}
		}

		return s.substr(start,max_len);
	}
};

// Keys :
// 1. std::fill_n(outIt,length,value)
// 2. vector costs more time than usual arrays
// 3. string.substr(startIndex,length)
// 4. a proper way of programming : 
// 	f[j][i] = (s[j]==s[i]) && (i-j < 2 || f[j+1][i-1])
// 	<=>
// 	if(i-j<2 && s[j] == s[i]) f[j][i] = true;
// 	else if(f[j+1][i-1] && s[j] == s[i]) f[j][i] = true;

int main(){
	string s = "fdsafasdicxvncccsdfjsdfabcddcbaasdfafxyayxdf";
	SolutionbruteForce sol1;
	cout  << sol1.longestPalindrome(s) <<endl; // It has a bug, watch !

	SolutionDP sol2;
	cout << sol2.longestPalindrome(s) <<endl;
}
