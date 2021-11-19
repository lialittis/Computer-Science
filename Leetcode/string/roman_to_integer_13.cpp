#include <string>
#include <map>

using namespace std;

class Solution{
public:
    int romanToInt(string s){
        map<char,int> m{{'I', 1}, {'V',5},
                        {'X',10}, {'L',50},
                        {'C',100},{'D',500},
                        {'M',1000}};
        char p = 0;
        int ans = 0;
        for(char c: s) {
            ans+=m[c];
            if(p && m[c] > m[p]){
                ans -= 2*m[p];
            }
            p = c;
        }
        return ans; 
    }
    /* time : O(n) ; space : O(1) */
};

class Solution2 {
public:
    int romanToInt(string s) {
        
        int res = 0;
        int temp = 0;

        for(char c : s) {
            int add = charToInt(c);
            if(temp >= add) {
                res += add;
                temp = add;
            }else {
                res += add;
                res -= temp * 2;
                temp = add;
            }
        }
        return res;
    }

    // it is also possible to use unordered map to contain
    // this chart to int map
    int charToInt(char c) {
        switch (c)
        {
        case 'I':
            /* code */
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
};