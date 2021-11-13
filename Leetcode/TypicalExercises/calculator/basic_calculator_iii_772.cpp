// + - * / ( ) space
#include <stack>
#include <string>
#include <iostream>

using namespace std;

// hard to implement
// have to use double stack to realize this
// stack<stack<int>> and stack<int>
class Solution_iterative{
public:
    int calculator(string s){
        return 0;
    }
};

// recursively
class Solution_rec{
private:
    int i = 0;
public:
    int calculate(string s){
        if(s.empty()) return 0;
        stack<int> st{};
        char sign = '+';
        int N = s.size();

        int num = 0;
        while(i<N){
            char c = s[i++];
            if(c >= '0' && c <= '9'){
                num = num*10 + (c - '0');
            }
            // have to before the push step
            if(c == '('){
                num = calculate(s);
            }
            if(i == N || c == '+' || c == '-' || c == '*' || c == '/' || c == ')'){ // no need for '('
                if(sign == '+') st.push(num);
                else if(sign == '-') st.push(-num);
                else if(sign == '*') {
                    int tmp = st.top();
                    st.pop();
                    st.push(tmp*num);
                }
                else if(sign == '/'){
                    int tmp = st.top();
                    st.pop();
                    st.push(tmp/num);
                }

                num = 0;
                sign = c;
            }
            if(c == ')') break;
        }

        num = 0;
        while (!st.empty())
        {   
            // cout <<st.top()<<" ";
            num += st.top();
            st.pop();
        }
        return num;
    }

    void reset_i(){
        i = 0;
    }
};

int main() {
    Solution_rec sol;
    cout<<"4 + (5 * 6) = "<< sol.calculate("4 + (5 * 6)")<<endl;
    sol.reset_i();
    cout<<"4 + 1 / (5 * 6) = " << sol.calculate("4 + 1 / (5 * 6)")<<endl;
    sol.reset_i();
    cout<<"4 - ((5 * 6) + 5 ) / 5 = "<< sol.calculate("4 - ((5 * 6) + 5 ) / 5")<<endl;
    sol.reset_i();
    cout<<"(4 + (5 - 6) * 10 ) - 1 = "<< sol.calculate("(4 + (5 - 6) * 10 ) - 1")<<endl;
    sol.reset_i();

}