#include <vector>

/*
 * 0 - 1 backbag problem
 *
 * N objects and W volume in total
 *
 * using dp[i][j] to record the max value with taking i object and using j volume
 * the recursive formula should be
 * if j>=w : dp[i][j] = max (dp[i-1][j], dp[i-1][j-w] + v)
 * else : dp[i][j] = dp[i-1][j]
 *
 * Space and time complexity : O(NW)
 *
 * */

using namespace std;

int knapsack(vector<int> weights, vector<int> values, int N, int W){
	vector<vector<int>> dp(N+1,vector<int>(W+1,0));
	for(int i = 1;i<=N;++i){
		int w = weights[i-1], v = values[i-1];
		for(int j = 1; j <= W; ++j){
			if(j>=w){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[N][W];
}

/*
 * Optimize Space complexity
 *
 * From 2d to 1d
 *
 * because the d[i][j] only relies on last w element in the previous row
 *
 * but the vector has to be update from right to left
 *
 * */

int knapsack_opt(vector<int> weights, vector<int> values, int N, int W){
	vector<int> dp(W+1,0);
	for(int i = 1; i <= N; ++i){
		int w = weights[i-1], v =values[i-1];
		for(int j = W; j >= w; --j){
			dp[j] = max(dp[j], dp[j-w]+v);
		}
	}
	return dp[W];
}













