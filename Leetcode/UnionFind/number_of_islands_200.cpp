#include <algorithm>
#include <vector>

using namespace std;

class Solution_UF{
private :
    vector<int> id;
    vector<int> size; // balance the tree
public :
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();

        // initialize
        size = vector<int>(m*n,1);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j] == '1'){
                    id.push_back(i*n+j);
                }
                id.push_back(0);
            }
        }
    }
};

int main() {

}