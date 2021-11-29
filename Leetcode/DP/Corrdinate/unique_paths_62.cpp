#include <vector>

using namespace std;

// recursive
int uniquePaths1(int m, int n){
	vector<vector<int>> memo(m,vector<int>(n));
	return helper(m-1,n-1,memo);
}

int helper(int i,int j,vector<vector<int>>& memo){
	// bound check
	if(i<0 || j< 0) return 0;
	// end check
	if(i == 0 && j==0) return 1;
	// have memo
	if(memo[i][j] > 0) return memo[i][j];
	// compare and choose
	return memo[i][j] = helper(i-1,j,memo) + helper(i,j-1,memo);
}

// iterative
int uniquePaths2(int m, int n){
	vector<vector<int>> dp(m,vector<int>(n,1));
	// init

	// iterate
	for( int i=1;i<m ;++i){
		for(int j=1;j<n;++j){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}	
	}

	return dp[m-1][n-1];
}

// optimize : space O(n)
int uniquePaths3(int m, int n){
    vector<int> dp(n,1);
    for(int i = 1; i<m;++i){
        for(int j = 1; j<n;++j){
            dp[j] = dp[j] + dp[j-1];
        }
    }

    return dp[n-1];
}
 
int main(){

}