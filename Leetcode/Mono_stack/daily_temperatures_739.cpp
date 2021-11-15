#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures){
    int n = temperatures.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i =0; i< n; i++){
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            int pre_index = st.top();
            st.pop();
            ans[pre_index] = i - pre_index;
        }
        st.push(i);
    }

    return ans;
}
// 47/47 cases passed (128 ms)
// Your runtime beats 90.36 % of cpp submissions
// Your memory usage beats 24.38 % of cpp submissions (89 MB)

int main(){

}