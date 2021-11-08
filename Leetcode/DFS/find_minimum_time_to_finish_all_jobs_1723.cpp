#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
public:
    int res = INT32_MAX; 
    int minimumTimeRequired(vector<int>& jobs, int k){
        sort(jobs.begin(),jobs.end());  // prune
        vector<int> workers(k);
        // cout<<workers.size()<<endl;
        dfs(jobs,jobs.size()-1,workers);
        return res;
    }
    void dfs(vector<int> jobs,int position,vector<int>& workers){
        if (position < 0){
            res = min(*max_element(workers.begin(),workers.end()),res);
            cout << res<<endl;
            return;
        }
        if(*max_element(workers.begin(),workers.end())>=res ) return; // prune
        for(int i=0; i<workers.size();i++){
            if( i>0 && workers[i] == workers[i-1]) continue; // prune
            workers[i] += jobs[position];
            dfs(jobs,position-1,workers);
            workers[i] -= jobs[position];
        }
    }

};

int maint(){

}