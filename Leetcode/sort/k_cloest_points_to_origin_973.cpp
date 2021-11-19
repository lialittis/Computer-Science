#include <vector>
#include <algorithm>
using namespace std;

class Solution_moreSpace{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K){
        vector<vector<int>> ans;
        vector<pair<int,int>> toSort;
        for(int i = 0; i<points.size(); i++){
            toSort.emplace_back(points[i][0]*points[i][0] + points[i][1]*points[i][1],i);
        }

        // sort the pair array in terms of distance
        sort(toSort.begin(),toSort.end());
        for(int i = 0; i<K; i++) {
            ans.push_back(points[toSort[i].second]);
        }
        return ans;
    }
// Your runtime beats 94.74 % of cpp submissions
// Your memory usage beats 64.94 % of cpp submissions (54.7 MB)
};

class Solution_lessSpacs{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),[](vector<int>& p1,vector<int>& p2){
            return p1[0]*p1[0] + p1[1]*p1[1] < p2[0]*p2[0] + p2[1]*p2[1];
        });

        return vector<vector<int>>(points.begin(),points.begin()+K);
    }
// Your runtime beats 70.04 % of cpp submissions
// Your memory usage beats 94.54 % of cpp submissions (49.2 MB)
};