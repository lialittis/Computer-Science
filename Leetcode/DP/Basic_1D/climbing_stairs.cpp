/* 
 * There is n stairs, each step could be one or two,
 * there are how may ways of climbing in total.
 *
 * we use dp[i] stands for the number of ways when climb to i stairs
 * Init : dp[0] = 1, dp[1] = 1
 * State Transition : dp[i] = dp[i-1] + dp[i-2]
 *
 * */

#include <vector>

using namespace std;

class Solution{
public:
	int climbStairs(int n){
		if (n<=2) return n;
		vector<int> dp(n+1,1);
		for(int i = 2; i <= n; ++i ){
			dp[i] = dp[i-1] + dp[i-2];
		}

		return dp[n];
	}

	// Optimize space 
	// since dp[i] is only related with dp[i-1] and dp[i-2]
	int climbStairsOpt(int n){
		if(n <=2) return n;
		vector<int> dp(3,1);
		for(int i = 2; i<=n; ++i){
			dp[2] = dp[0] + dp[1];
			dp[1] = dp[0];
			dp[0] = dp[2];
		}
		return dp[3];
	}

	// Ideal implementation
	// Less explanation
	int climbStairsIdeal(int n){
		int a = 1, b = 1;
		while(--n){
			b += a;
			a = b - a;
		}
		return b;
	}
};



