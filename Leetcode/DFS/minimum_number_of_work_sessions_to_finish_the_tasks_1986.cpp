#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution{
public:
    int res;
    int maxSessionTime;
    int minSessions(vector<int>& tasks, int sesstionTime){
        sort(tasks.begin(),tasks.end());
        res = tasks.size();
        maxSessionTime = sesstionTime;
        vector<int> sessions(res);
        dfs(tasks,sessions,tasks.size()-1);
        return res;
    }

    void dfs(vector<int> tasks, vector<int>& sessions, int pos){
        if(sessions.size() > res) return; // prune global min
        if(pos < 0) {
            res = min(res,(int)sessions.size());
            return;
        }

        for(int i=0;i<sessions.size();i++){
            if(sessions[i]+tasks[pos] <= maxSessionTime){
                sessions[i] += tasks[pos];
                dfs(tasks,sessions,pos-1);
                sessions[i] -= tasks[pos];
            }
            sessions.push_back(tasks[pos]);
            dfs(tasks,sessions,pos-1);
            sessions.push_back(tasks[pos]);
        }
    }



};