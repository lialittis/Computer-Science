#include <stack>
#include <string>

using namespace std;

bool isValid(string s){
    stack<char> parsed;
    for(int i = 0; i< s.size();i++){
        char c = s[i];
        if(c == '{' || c== '[' || c == '('){
            parsed.push(c);
        }
        else if(c==')'){
            if(parsed.empty()|| parsed.top()!='(') return false;
            parsed.pop();
        }
        else if(c==']' ){
            if(parsed.empty()|| parsed.top()!='[') return false;
            parsed.pop();            
        }
        else if(c=='}'){
            if(parsed.empty()|| parsed.top()!='{') return false;
            parsed.pop();            
        }
    }

    return parsed.empty(); // check if the stack is empty

}
    // similar method
    // bool isValid(string s) {

        // for(char c : s) {
        //     switch (c)
        //     {
        //     case '(' :
        //         stk.push_back(')');
        //         break;
        //     case '[' :
        //         stk.push_back(']');
        //         break;
        //     case '{' :
        //         stk.push_back('}');
        //         break;
        //     default:
        //         if(stk.size() == 0 || c != stk.back()) return false;
        //         else stk.pop_back();
                
        //     }
        // }

        // return stk.size() == 0;
    // }