/*
 * There are many houses on the street, max money you could rob without
 * robbing the near two houses.
 *
 * Use dp[i] to stand for the max money you could rob until i house
 *
 * Init: dp[0] = 0, dp[1] = nums[0]
 * State Transition : dp[i] = max(dp[i-1],dp[i-2] + nums[i-1])
 *
 * */

#include <vector>

using namespace std;

class Solution{
public:
	
};
