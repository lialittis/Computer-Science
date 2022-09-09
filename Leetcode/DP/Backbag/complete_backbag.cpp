#include <vector>

/*
 * In this case, one item could be taken many times, 
 * dp[i][j] won't depend on only the last w items in the last row
 * theoritically, it depends on how many current items it could 
 * take from one of the state in the last row and also itself.
 *
 * In reality, there is one easier way of considering, that is
 * dp[i][j] = max(dp[i-1][j],dp[i][j-w] + v)
 * */

using namespace std;

int knapsack(vector<int> weights, vector<int> values, int N, int W){
	vector<vector<int>> dp(N+1, vector<int>(W+1,0));

	for(int i = 1; i < N; ++i){
		int w = weights[i-1], v = values[i-1];
		for(int j = 1; j < W; ++j ){
			if(j >= w){
				dp[i][j] = max(dp[i-1][j],dp[i][j-w] + v);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[N][W];
}


/* Also we could optimize it
 * 
 * by update dp from left to right iteratively
 *
 * */

int knapsack_opt(vector<int> weights, vector<int> values, int N, int W){
	vector<int> dp(W+1,0);

	for(int i = 1; i < N; ++i){
		int w = weights[i-1], v = values[i-1];
		for(int j = w; j <= W; ++j){
			dp[j] = max(dp[j],dp[j-w]+v);
		}
	}
	return dp[W];
}
