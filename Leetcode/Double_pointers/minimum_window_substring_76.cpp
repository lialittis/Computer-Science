/* hard */
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    string minWindow(string S, string T){
        vector<int> chars(128,0); // number of each char in string T
        vector<bool> flag(128,0); // singals of each char in string T
        //initialize chars and flag
        for(int i = 0; i < T.size(); i++){
            ++chars[T[i]];
            flag[T[i]] = true;
        }// interesting, because all chars are from 0 to 127 as their index

        // statistics
        int cnt =0, l = 0, min_l = 0, r = 0, min_size = S.size()+1;
        // move the window
        while(r<S.size()){ // also we can use for loop

            if(flag[S[r]]){ // if s[r] is in T
                if( --chars[S[r]] >= 0){ // the number of this char in T minus - 1
                    ++cnt; // if the number is still >= 0, it counts one of T
                }

                while (cnt == T.size()) // if all chars are counted
                {
                    if( r - l + 1 < min_size){ // check the current window size
                        min_l = l; // update the size and min l
                        min_size = r - l + 1;
                    }
                    if(flag[S[l]] && ++chars[S[l]] > 0){ // if S[l] is one of the T, 
                    // and add one the number of this char is bigger than 0
                        --cnt; // minus one from the count
                    }
                    ++l; // move the left side
                }
                
            }
            ++r; // move the right side
        }

        return min_size > S.size() ? "" : S.substr(min_l,min_size);
    }
};

/*
1. start to move right pointer of the window
2. in each step, check if all chars are counted, and count the number of remained char,
negative char means offered are more that needed
3. when all chars are counted, start to move left pointer of the window
4. in each step of the left moving, update the min size, and check the condition to get out
of the loop and back to move the right pointer

Your runtime beats 90.91 % of cpp submissions
Your memory usage beats 49.25 % of cpp submissions (7.8 MB)
*/

int main(){

}