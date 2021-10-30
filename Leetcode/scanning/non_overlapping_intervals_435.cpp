/* sweep line */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "interval.h"

using namespace std;

class mycomp{
public:
  bool operator() (Interval i, Interval j){
    return i.end < j.end || (i.end == j.end && i.start < j.start);
  }
};

class Solution{
public:
  int eraseOverlapIntervals(vector<Interval> intervals){
    if(intervals.size() == 0) return 0;
    // sort the intervals by their end times
    sort(intervals.begin(),intervals.end(),mycomp());

    int count = 0, end = INT32_MIN;

    for(Interval cur : intervals){
      if(end <= cur.start) end = cur.end;
      else count ++;
    }
    return count;
  }
};


int main() {

  vector<Interval> intervals;
  intervals.push_back(Interval(1,2));
  intervals.push_back(Interval(2,3));
  intervals.push_back(Interval(3,4));
  intervals.push_back(Interval(1,3));

  Solution sol;
  cout<<sol.eraseOverlapIntervals(intervals)<<endl;

  return  0;
}

