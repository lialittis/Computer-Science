/* sweep line */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Interval{
  int start;
  int end;
  Interval() : start(0), end(0){}
  Interval(int x) : start(x), end(x){}
  Interval(int x, int y): start(x), end(y) {}

  bool operator < (Interval i) {
    return start < i.start || (start == i.start && end < i.end);
  }
};

class Solution{
  vector<Interval> insert(vector<Interval> intervals, Interval newInterval){
    vector<Interval> output{};
    int flag = 0;
    for(auto cur : intervals){
      if(cur.start > newInterval.end && flag == 0) {
        output.push_back(newInterval);
        output.push_back(cur);
        flag = 1;
      }
      else if(cur.end < newInterval.start || flag == 1){
        output.push_back(cur);
      }
      else{
        cur.start = min(cur.start, newInterval.start);
        cur.end = max(cur.end, newInterval.end);
        flag = 1;
      }
    }
    if(flag == 0) output.push_back(newInterval);
    return output;
  }
};

int main(){
  return 0;
}
