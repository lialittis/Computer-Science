#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty()) return 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=0, j =0;
        while (i<=g.size()-1 && j<=s.size()-1)
        {
            if(s[j]>=g[i]){
                i++;
            }
            j++;
        }

        return i;
    }
};
// Your runtime beats 89.38 % of cpp submissions
// Your memory usage beats 76.4 % of cpp submissions (17.4 MB)

int main(){

}