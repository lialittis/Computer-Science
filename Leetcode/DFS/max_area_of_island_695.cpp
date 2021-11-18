#include <vector>
#include <stack>

using namespace std;

class DFS{
public:
    int maxArea_rec(vector<vector<int>>& grid){
        int max_area = 0; // initial max_area
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j <grid[0].size(); j++) {
                if(grid[i][j] == 1){ // condition to dfs
                    max_area = max(max_area,dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }

    int maxArea_stack(vector<vector<int>>& grid){
        int m = grid.size(), n = m ? grid[0].size() : 0;
        int local_area, area = 0, x, y;
        for(int i = 0; i< m; i++){
            for(int j = 0; j <n; j++){
                if(grid[i][j]){
                    local_area = 1;
                    grid[i][j] = 0; // erase the used area

                    // build a stack to store island
                    stack<pair<int,int>> island;
                    island.push({i,j});
                    while (!island.empty())
                    {
                        auto location = island.top();
                        island.pop();
                        for(int k =0; k< 4; k++){
                            x = location.first + direction[k];
                            y = location.second + direction[k+1];
                            if(x>=0 && x<m && y>=0&&y< n&&grid[x][y]==1){
                                grid[x][y] = 0;
                                island.push({x,y});
                                ++local_area;
                            }
                        }
                    }
                    area = max(area,local_area);
                }
            }
        }

        return area;
    // Your runtime beats 82.59 % of cpp submissions
    // Your memory usage beats 15.71 % of cpp submissions (26.9 MB)
    }

private:
    vector<int> direction{-1,0,1,0,-1};

    int dfs(vector<vector<int>>& grid, int r, int c){
        if( r < 0 || r >= grid.size() ||
            c < 0 || c >=grid[0].size() ||
            grid[r][c] == 0) return 0; // end search
        grid[r][c] = 0; // to avoid recalculation

        return 1 + dfs(grid,r-1,c) + dfs(grid,r+1,c) + dfs(grid,r,c-1) + dfs(grid,r,c+1);
    }
// Your runtime beats 82.59 % of cpp submissions
// Your memory usage beats 88.42 % of cpp submissions (23.2 MB)

    int dfs_2(vector<vector<int>>& grid, int r, int c){
        if( grid[r][c] == 0) return 0; // end search
        grid[r][c] = 0; // to avoid recalculation
        int area = 1;
        for(int i = 0; i<4;i++) {
            int x = r + direction[i];
            int y = c + direction[i+1];
            if(x>=0 && x < grid.size() && y>= 0 && y < grid.size()){
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};