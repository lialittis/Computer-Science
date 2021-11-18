#include <vector>


using namespace std;

// not sure if it is correct
class findCircle{
private:
    void dfs_erase(vector<vector<int>>& friends,int r, int c){
        if(friends[r][c]==0) return;
        // erase
        friends[r][c] = 0;
        for(int i = 0; i < friends.size();i++){
            dfs_erase(friends,c,i);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& friends){
        if(friends.empty()) return 0;
        int n = friends.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j< n;j++){
                if(friends[i][j]==1){
                    count++;
                    dfs_erase(friends, i, j);
                }
            }
        }
        return count;
    }
};

class Solution{
private:
    void dfs(vector<vector<int>>& friends, int i, vector<bool>& visited){
        visited[i] = true;
        for(int k =0; k <friends.size();k++){
            if(friends[i][k] == 1 && !visited[k]){
                dfs(friends,k,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& friends){
        int n = friends.size(), count = 0;
        vector<bool> visited(n,false);
        for(int i = 0; i <n; ++i){
            if(!visited[i]){
                dfs(friends,i,visited);
                ++count;
            }
        }
    }
};