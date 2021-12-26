/* Easy */

/* converting all uppercase letters into lowercase letters
 * removing all non-alphanumeric characters 
 */

#include <string>

using namespace std;

/* First Try : 
 * left, right, recursively
 * two possiblities : even, odd
 * skip no use elements and transfer uppercase letters 
 */

/* Analysis : 479/480 passed
 */

bool isPalindrome(string s){
    if(s.size() == 0 || s.size() == 1) return true;

    char f = s[0], e = s.back();

    if(f <= 'Z' && f >= 'A') {
        f +=32;
    }

    if(e <='Z' && e>='A') {
        e += 32;
    }

    if(f<= '9' && f >= '0' ) {
        if(e <= 'z' && e >= 'a') return false;
        else if(e <= '9' && e >= '0') {
            if(f==e) {
                s.erase(s.begin());
                s.erase(s.end()-1);
                return isPalindrome(s);
            }
            else return false;
        }
        else {
            s.erase(s.end()-1);
            return isPalindrome(s);
        }
    }

    if(f<= 'z' && f >= 'a'){
        if(e <= 'z' && e >= 'a'){
            if(f==e){
                s.erase(s.begin());
                s.erase(s.end()-1);
                return isPalindrome(s);
            }
            else return false;
        }
        else if(e <= '9' && e >= '0') return false;
        else{
            s.erase(s.end()-1);
            return isPalindrome(s);
        }
    }
    else{
        s.erase(s.begin());
        return isPalindrome(s);
    }

    return false;
}

/* give some references */

// 480/480 cases passed (4 ms)
// Your runtime beats 93.19 % of cpp submissions
// Your memory usage beats 88.61 % of cpp submissions (7.3 MB)

class Solution1 {
public:
    bool isPalindrome(string s){
        int left = 0, right = s.size() - 1; // there is no need to use recursive way
        while(left <right) {
            if(!isAlphaNumber(s[left])) ++ left;
            else if(!isAlphaNumber(s[right])) --right;
            else if((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32) return false;
            else{
                ++left;
                --right;
            }
        }

        return true;
    }

    bool isAlphaNumber(char &ch){
        if( ch >= 'a' && ch <= 'z') return true;
        if( ch >= 'A' && ch <= 'Z') return true;
        if( ch >= '0' && ch <= '9') return true;
        return false;
    }
};
