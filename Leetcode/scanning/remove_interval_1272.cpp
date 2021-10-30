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
public:
  vector<Interval> removeInterval(vector<Interval> intervals, Interval toBeRemoved){
    vector<Interval> output{};
    for(Interval e : intervals){
      if(e.start >= toBeRemoved.end || e.end <= toBeRemoved.start){
        output.push_back(e);
      }
      else{
        if (e.start < toBeRemoved.start){
          output.push_back(Interval(e.start,toBeRemoved.start));
        }
        if(e.end > toBeRemoved.end){
          output.push_back(Interval(toBeRemoved.end,e.end));
        }
      }
    }
    
    return output;
  }
};


int main(){
  return 0;
}
