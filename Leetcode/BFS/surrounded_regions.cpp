/* BFS */



/*
 * Capture all regions surrouned by 'X' and flip them to 'X'
 *
X X X X
X O X O
X O O X
X X X X
*/

// BFS
// Start from four boundaries into insides,
// keep the 'O's connected with boundaries

#include <vector>
#include <queue>

using namespace std;

class SolutionBFS{
public:
	void solve(vector<vector<char>> &board){
		if(board.empty()) return;

		const int m = board.size();
		const int n = board[0].size();

		for(int i = 0; i<n; i++){
			bfs(board,0,i);
			bfs(board,m-1,i);
		}

		for(int j = 1; j<m-1;j++){
			bfs(board,j,0);
			bfs(board,j,n-1);
		}

		for(int i = 0; i<m ;i++){
			for (int j = 0; j<n;j++){
				if(board[i][j] == 'O')
					board[i][j] = 'X';
				else if(board[i][j] == '+')
					board[i][j] = 'O';
			}
		}
	}
private:
	void bfs(vector<vector<char>> &board,int i, int j){
		typedef pair<int, int> state_t;
		queue<state_t> q;
		const int m = board.size();
		const int n = board[0].size();

		auto state_is_valid = [&](const state_t &s) {
			const int x = s.first;
			const int y = s.second;
			if(x<0 || x >=m || y < 0 || y>=n || board[x][y]!= 'O')
				return false;
			return true;
		};

		auto state_extend = [&](const state_t &s){
			vector<state_t> result;
			const int x = s.first;
			const int y = s.second;
			const state_t new_states[4] = {{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
			for(int k = 0; k< 4; ++k){
				if(state_is_valid(new_states[k])){
					board[new_states[k].first][new_states[k].second] = '+'; // remark it
					result.push_back(new_states[k]);
				}
			}
			return result;
		};

		state_t start = {i,j};
		if(state_is_valid(start)) {
			board[i][j] = '+'; // remark it
			q.push(start);
		}

		while(!q.empty()){
			auto cur = q.front();
			q.pop();
			auto new_states = state_extend(cur);
			for(auto s:new_states) q.push(s);
		}
	}
};


// Keys
// 1. [&] before lambda function :
// 	It means that the lambda function will capture all variables in the scope by reference.
// 	To use other variables other than what was passed to lambda within it, we can use capture-clause []. 
// 	You can capture by both reference and value, which you can specify using & and = respectively:
// 	[=] capture all variables within scope by value
// 	[&] capture all variables within scope by reference
// 	[&var] capture var by reference
// 	[&, var] specify that the default way of capturing is by reference and we want to capture var
// 	[=, &var] capture the variables in scope by value by default, but capture var using reference instead
