/* sweep line*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval{
  int start;
  int end;
  Interval() : start(0), end(0){}
  Interval(int x) : start(x), end(x){}
  Interval(int x, int y): start(x), end(y) {}
};

class TPoint {
public:
  int time;
  int flag;   // -1 land, 1 take off
  
  TPoint() {}
  
  TPoint(int time, int flag)
    : time(time)
    , flag(flag) {}
  
  bool operator < (const TPoint& rhs) const {
    return time < rhs.time || (time == rhs.time && flag < rhs.flag); 
  }
  // This operator is very important for sort function
};

class Solution{
public:
  int countOfAirplanes(vector<Interval> airplanes){

    int n = airplanes.size();

    vector<TPoint> l;

    for(Interval i : airplanes) {
      l.push_back(TPoint(i.start,1));
      l.push_back(TPoint(i.end,-1));
    }

    sort(l.begin(),l.end());

    int cnt = 0;
    int ans = 0;
    for(auto p : l){
      cnt += p.flag;
      ans = max(ans,cnt);
    }

    return ans;
  }
};

int main(){
  Solution sol;

  vector<Interval> airplanes;
  airplanes.push_back(Interval(1,10));
  airplanes.push_back(Interval(2,3));
  airplanes.push_back(Interval(5,8));
  airplanes.push_back(Interval(4,7));

  cout<<"max number airplanes in the sky : "<< sol.countOfAirplanes(airplanes)<<endl;

  return 0;
}
