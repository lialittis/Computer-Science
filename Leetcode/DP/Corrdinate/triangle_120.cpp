/* No greedy, DP */
#include <vector>

using namespace std;

// dp 2d iterative
int minimumTotal1(vector<vector<int>> triangle){
    int n = triangle.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=n-1; i>= 0; --i){
        for(int j = i; j>=0; --j){
            dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
        }
    }

    return dp[0][0];
}

// recursive 2d


int miniTotal2(vector<vector<int>> triangle){
    int n = triangle.size();
    return helper(n-1,n-1,triangle,vector<vector<int>>(n,vector<int>(n)));
}

int helper(int x, int y, vector<vector<int>> triangle,vector<vector<int>> memo){
    // bound check
    if(x >= triangle.size()) return 0;

    // end check
    // memo exist
    if(memo[x][y] != 0) return memo[x][y];
    return memo[x][y] = min(helper(x+1,y,triangle,memo),helper(x+1,y+1,triangle,memo)) + triangle[x][y];
}


int main(){

}