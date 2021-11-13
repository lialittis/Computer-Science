#include <vector>
#include <string>
#include <stack>

using namespace std;


// use stack container
class Solution_iterative_loop{
    int calculate(string s){
        if(s.empty()) return 0;
        int res = 0; 
        char sign = '+';
        stack<int> st{};

        int N = s.size();

        for(int i = 0; i< N; i++){
            char c = s[i];
            if(c>= '0' && c <= '9'){
                res = res*10 + (c - '0');
            } 

            if(i == N -1 || c == '+' || c == '-' || c == '*' || c == '/'){
                if(sign == '+') st.push(res);
                else if(sign == '-') st.push(-res);
                else if(sign == '*') {
                    int tmp = st.top();
                    st.pop();
                    st.push(tmp*res);
                }
                else if(sign == '/') {
                    int tmp = st.top();
                    st.pop();
                    st.push(tmp/res);
                }
                res = 0;
                sign = c;

            }
        }

        while( !st.empty())
        {
            res += st.top();
            st.pop();
        }

        return res;
        
    }
};

// Runtime: 8 ms, faster than 89.71% of C++ online submissions for Basic Calculator II.
// Memory Usage: 8.5 MB, less than 60.83% of C++ online submissions for Basic Calculator II.



// use vector container
class Solution_iterative_loop_vec{
    int calculate(string s){
        if(s.empty()) return 0;
        int res = 0; 
        char sign = '+';
        vector<int> st{};

        int N = s.size();

        for(int i = 0; i< N; i++){
            char c = s[i];
            if(c>= '0' && c <= '9'){
                res = res*10 + (c - '0');
            } 

            if(i == N -1 || c == '+' || c == '-' || c == '*' || c == '/'){
                if(sign == '+') st.push_back(res);
                else if(sign == '-') st.push_back(-res);
                else if(sign == '*') {
                    int tmp = st[st.size()-1];
                    st.pop_back();
                    st.push_back(tmp*res);
                }
                else if(sign == '/') {
                    int tmp = st[st.size()-1];
                    st.pop_back();
                    st.push_back(tmp/res);
                }
                res = 0;
                sign = c;

            }
        }

        for( auto e : st)
        {
            res += e;
        }
        return res;
        
    }
};

// Runtime: 8 ms, faster than 89.71% of C++ online submissions for Basic Calculator II.
// Memory Usage: 9 MB, less than 24.15% of C++ online submissions for Basic Calculator II.

int main(){

}