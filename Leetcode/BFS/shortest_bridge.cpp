/* BFS */

/*
 * 1 is land, 0 is sea,
 * 
 * shorest bridge to connect two islands
 *
 * Input:
[[1,1,1,1,1],
[1,0,0,0,1],
[1,0,1,0,1],
[1,0,0,0,1],
[1,1,1,1,1]]
 * Output: 1
 * */


/* BFS : 
 *
 * 1. find any of islands
 * 2. use BFS to search another island
 *
 * */
#include <queue>
#include <utility>

using namespace std;

vector<int> direction{-1,0,1,0,-1};

class SolutionBFS{
public:
	int shortestBridge(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		queue<pair<int,int>> points;

		// use dfs to find the first island
		// modify its 1 to 2
		bool flipped = false;
		for(int i = 0;i<m;++i){
			if(flipped) break;
			for(int j = 0; j<n;++j){
				if(grid[i][j] == 1){
					dfs(points,grid,m,n,i,j);
					flipped = true;
					break;
				}
			}
		}

		// bfs to find the second island
		// assign passed 0 to 2
		int x,y;
		int level = 0;
		while(!points.empty()){
			++level;
			int n_points = points.size();
			while(n_points--){
				auto [r,c] = points.front();
				points.pop();

				for(int k = 0; k< 4; ++k){
					x = r + direction[k], y = c + direction[k+1];
					if(x >= 0 && y >=0 && x < m && y < n){
						if(grid[x][y] == 2) continue;
						if(grid[x][y] == 1) return level;
						points.push({x,y});
						grid[x][y] = 2;
					}
				}
			}
		}
		return 0;
	}
private:
	void dfs(queue<pair<int,int>>& points, vector<vector<int>>& grid, int m, int n, int i, int j){
		if(i<0||j<0||i==m ||j==n|| grid[i][j]==2){
			return;
		}

		if(grid[i][j] == 0){
			points.push({i,j});
			return;
		}

		grid[i][j] = 2;
		dfs(points,grid,m,n,i-1,j);
		dfs(points,grid,m,n,i+1,j);
		dfs(points,grid,m,n,i,j-1);
		dfs(points,grid,m,n,i,j+1);

	}
};
