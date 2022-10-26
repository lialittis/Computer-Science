/* stack */

/* 
 * Largest Rectangle in Histogram
 *
 *
 * */

// similar: container with most water

// Brute Force, start from each element, and take them as middle,
// search for both sides until find lower that themselves.
// O(n^2) time

#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
	int largestRectangleArea(vector<int> &height){
		stack<int> s;
		height.push_back(0);

		int result = 0;

		for (int i = 0; i<height.size();){
			if(s.empty() || height[i] > height[s.top()])
				s.push(i++);
			else {
				int tmp = s.top();
				s.pop();
				result = max(result,height[tmp] * (s.empty()?i:i-s.top() - 1));
			}
		}
		return result;
	}
};
