#include <vector>

using namespace std;

// recursive
int uniquePathsWithObstacles1(vector<vector<int>> obstacleGrid){
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector<vector<int>> memo(m,vector<int>(n));
	return helper(obstacleGrid,m-1,n-1,memo);
}

int helper(vector<vector<int>> obstacleGrid, int i,int j,vector<vector<int>>& memo){
	// bound check
	if(i<0 || j< 0 || obstacleGrid[i][j] == 1) return 0;
	// end check
	if(i == 0 && j==0 ) return 1;
	// have memo
	if(memo[i][j] > 0) return memo[i][j];
	// compare and choose
	return memo[i][j] = helper(obstacleGrid,i-1,j,memo) + helper(obstacleGrid,i,j-1,memo);
}

// iterative
int uniquePathsWithObstacles2(vector<vector<int>> obstacleGrid){
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    // init
    for(int i = 0;i<m;++i){
        if(obstacleGrid[i][0] == 1) break;
        dp[i][0] = 1;
    }
    for(int j = 0;j<n;++j){
        if(obstacleGrid[0][j] == 1) break;
        dp[0][j] = 1;
    }
    // iterate
    for( int i=1;i<m ;++i){
        for(int j=1;j<n;++j){
            dp[i][j] = obstacleGrid[i][j] !=1 ? dp[i-1][j] + dp[i][j-1] : 0;
        }
    }

	return dp[m-1][n-1];
}
 
int main(){

}