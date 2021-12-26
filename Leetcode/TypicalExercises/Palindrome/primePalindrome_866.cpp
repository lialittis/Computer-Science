/* Medium */

/* Given an integer n, return the smallest prime palindrome greater than or equal to n
 * 
 */

/* First Try :
 * ideas : 
 * 1. how to verify if it's palindrome : string or integer
 * 2. how to check it is prime
 * 3. how to quickly find a prime
 */

/* have no idea in 5 mins , because the basic idea 
 * of check each number will definitely run out of time
 */


/* Learn by this reference :
 * 1. not check each number, but check each palindrome bigger than or equal as n
 * 2. construct the palindrome by concadinate two half of the palindrome
 * 3. all even length palindrome are dividable by 11 -> not prime
 * 4. check if the odd length palindrome is prime
 */

#include <string>
#include <math.h>

using namespace std;

class Solution{
// Your runtime beats 65.27 % of cpp submissions
// Your memory usage beats 44.35 % of cpp submissions (6 MB)
public:
    int primePalindrome(int N) {
        if(N>=8 && N <=11) return 11; // corner case for even length palindrome;
        for(int i = 1; i < 1e5; ++i) {
            // 1e5 , because the largest n is 1e8
            string s = to_string(i), t(s.rbegin(),s.rend()); // reverse string
            int x = stoi(s + t.substr(1)); // substr, sub string from 1 to the end
            if(x>=N && isPrime(x)) return x;
        }

        return -1;
    }

    bool isPrime(int num){
        if(num < 2 || num %2 == 0) return num==2;
        // int limit = sqrt(num);
        for( int i = 3; i*i <= num; ++i) {
            if( num %i == 0) return false;
        }
        return true;
    }
};



