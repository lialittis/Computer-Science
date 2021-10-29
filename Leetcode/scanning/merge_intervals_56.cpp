/* sweep line ; heap */
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
public:
  vector<Interval> merge(vector<Interval> intervals){
    vector<Interval> output{};
    if(intervals.size() == 0) return output;

    sort(intervals.begin(),intervals.end());

    Interval cur = intervals[0];

    for(auto next : intervals){
      if(cur.end >= next.start) cur.end = max(cur.end,next.end);
      else {
        output.push_back(cur);
        cur = next;
      }
    }
    output.push_back(cur);
    return output;
  }
};

int main(){
  
}
