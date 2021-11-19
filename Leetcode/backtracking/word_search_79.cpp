#include <vector>
#include <string>
#include <iostream>

using namespace std;

class BT{
private:
    vector<int> direction {-1,0,1,0,-1};
    bool flag;

    void backtracking(vector<vector<char>>& board, string word, int pos,int x, int y, vector<vector<int>>& visited){
        if(pos == word.size()){
            flag = true;
            return ;
        }

        for(int i = 0; i < 4; i++) {

            int r = x+direction[i], c = y+direction[i+1];
            // cout<<x <<","<< y<<"\t";
            // cout<<r <<","<< c<<"\t";
            // cout<<word[pos]<<endl;
            if(r>=0 && r < board.size() && c>= 0 && c < board[0].size() && 
                board[r][c] == word[pos] && visited[r][c] == 0){
                // cout<<"yes"<<endl;
                visited[r][c] = 1;
                backtracking(board,word,pos+1,r,c,visited);
                visited[r][c] = 0;
            }
        }
        return ;

    }
public:
    bool exist(vector<vector<char>>& board, string word){
        if(board.empty() || board[0].empty()) return false;
        
        int m = board.size();

        int n = board[0].size();
        // build a matrix of visited with initial value of 0
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    // cout<<word[0]<<endl;
                    visited[i][j] = 1;
                    // cout<<word[0]<<endl;
                    backtracking(board,word,1,i,j,visited);
                    visited[i][j] = 0;
                    if(flag){
                        return true;
                    }
                }
            }
        }
        return flag;
    }

// Your runtime beats 46.98 % of cpp submissions
// Your memory usage beats 5.82 % of cpp submissions (8.1 MB)
// 
};

class BetterBT{
private:
    void backtracking(int i, int j, vector<vector<char>>& board, string& word, bool& find, vector<vector<bool>>& visited, int pos){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()){
            return;
        }

        if(visited[i][j] || find || board[i][j] != word[pos]){
            return;
        }

        if(pos == word.size() - 1){
            find = true;
            return ;
        }

        visited[i][j] = true;
        backtracking(i+1,j,board,word,find,visited,pos+1);
        backtracking(i-1,j,board,word,find,visited,pos+1);
        backtracking(i,j+1,board,word,find,visited,pos+1);
        backtracking(i,j-1,board,word,find,visited,pos+1);
        visited[i][j] = false;
    }
public:
    bool exist(vector<vector<char>>& board, string word){
        if(board.empty()) return false;
        int m = board.size(), n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n,false));

        bool find = false;

        for(int i = 0; i< m; ++i){
            for(int j = 0; j<n;++j){
                backtracking(i,j,board,word,find,visited,0);
            }
        }
        return find;
    }
};
// Your runtime beats 70.71 % of cpp submissions
// Your memory usage beats 5.82 % of cpp submissions (8.1 MB)


int main() {

}