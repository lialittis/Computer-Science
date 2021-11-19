/* Easy */
/* sliding window, hashtable */

#include <string>
#include <vector>

/* Solution 1: Brute Force
    O((|S| - |P|)*|P|) = O(n^2)
*/

/* Solution 2: Sliding Window
    Use a hash table to represent p and the sliding window
    O(|S|*26/128) = O(n)
*/

using namespace std;

class Solution2{
public:
    vector<int> findAnagrams(string s, string p){
        vector<int> ans; // to reaturn
        // get the size of each string
        int n = s.length();
        int l = p.length();
        // pre_allocate two vectors
        // using int to count the number of appearance of eahc letter
        vector<int> vp(26,0);
        vector<int> vs(26,0);

        for(char c: p) ++vp[c-'a']; // count for p

        // sliding window
        for(int i = 0; i<n; i++){
            // when the vs is too long, move the first elements
            // by reducing the count of corresponing letter
            if(i>=l) --vs[s[i-l] - 'a'];
            // add the new letter by number
            ++vs[s[i] - 'a'];
            // if find one, give it to ans
            if(vs==vp) ans.push_back(i+1 -l);
        }

        return ans;
    }
    // Your runtime beats 83.89 % of cpp submissions
    // Your memory usage beats 99.12 % of cpp submissions (8.5 MB)
};