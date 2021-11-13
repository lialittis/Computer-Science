#include <vector>
#include <string>

using namespace std;

// using vector as a stack to store value before the ( and pop them up after ).
class Solution_iterative_stack{
public:
    int calculate(string s){
        if(s.empty()) return 0;
        int res = 0, sign = 1, N = s.size();
        vector<int> stack{};

        for(int i = 0; i< N;i++){
            char c = s[i];
            if( c >= '0' && c <= '9'){
                int num = 0;
                while(i<N && c >= '0' && c <= '9'){
                    num = num * 10 + (c - '0');
                    c = s[++i];
                }
                i--;
                res += sign * num;
            }
            else if(c == '+') sign = 1;
            else if(c== '-') sign = -1;
            else if(c == '('){
                stack.push_back(res);
                stack.push_back(sign);
                res = 0;
                sign = 1;
            }
            else if(c == ')'){
                res *= stack[stack.size()-1];
                stack.pop_back();
                res += stack[stack.size()-1];
                stack.pop_back();
            }
        }
        return res;
    }
};

// Runtime: 8 ms, faster than 85.42% of C++ online submissions for Basic Calculator.
// Memory Usage: 8 MB, less than 92.71% of C++ online submissions for Basic Calculator.

// using vector as stack, to store each element and add them up at the end
class Solution_recursive_stack{
private:
    int i = 0;
public:
    int calculate(string s){
        if(s.size() == 0) return 0;
        vector<int> stack{};
        char op = '+';
        int res = 0;
        while(i< s.size()){
            char c = s[i];
            i++;
            if(c >= '0' && c <= '9'){
                res = res*10 + (c-'0');
            }
            if(c == '('){
                res = calculate(s);
            }
            if(i >=s.size() || c == '+'  || c == '-' || c == ')'){
                if(op == '+') stack.push_back(res);
                else stack.push_back(-res);
                res = 0;
                op = c;
            }
            if(c == ')'){
                break;
            }
        }

        res = 0;
        for(auto value : stack){
            res += value;
        }
        return res;
    }
};
// Runtime: 32 ms, faster than 20.44% of C++ online submissions for Basic Calculator.
// Memory Usage: 286.3 MB, less than 5.17% of C++ online submissions for Basic Calculator.


int main(int argc, char *argv){

}