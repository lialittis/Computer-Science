/* Easy */
/* monotonic stack */
#include <vector>
#include <stack>

using namespace std;

class SolutionNaive{
public:
    vector<int> finalPrices(vector<int> prices){
        const int n = prices.size();
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++) {
                if(prices[j] <= prices[i]){
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;

    }
// best in O(N), worst in O(N^2); space in O(1)
};

class Solution{
public:
    vector<int> finalPrices(vector<int> prices){
        // try to use monotonic stack
        const int n = prices.size();
        // the stack is used to store index
        stack<int> s;
        for(int i = 0; i<n;i++){
            while(!s.empty() && prices[s.top()] >= prices[i]){
                prices[s.top()] -= prices[i];
                s.pop();
            }
            s.push(i);
        }
        return prices;
    }
};