/* Easy */

/* Given a string, return the length of longest palindrome that can be built with those letters
 * letters are case sensitive
 * only letters (uppercase and lowercase)
 */

/* First Try : 17mins
 * even number of letters + one odd number of letter
 * only need a map to count the number of all letters
 * or maybe vector is good enough
 */

/* Analysis : O(n) ; O(52 * 2) */

// 95/95 cases passed (4 ms)
// Your runtime beats 71.8 % of cpp submissions
// Your memory usage beats 12.95 % of cpp submissions (6.7 MB)


#include <unordered_map>

using namespace std;

unordered_map<char,int> dict{};

int longestPalindrome(string s) {
    int l = s.size();
    if(l <= 1) return true;

    for(int i=0; i<l; i++) {
        if(dict.find(s[i]) != dict.end()){
            dict.at(s[i]) += 1;
        }
        else{
            dict[s[i]] = 1;
        }
    }

    int res = 0;
    int flag = false;

    for(auto ele : dict) {
        if (ele.second%2 ==0 ) res += ele.second;
        else {
            flag = true;
            res += ele.second-1;
        }
    }
    if(flag==true) res +=1;
    return res;
}