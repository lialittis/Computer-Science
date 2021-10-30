/* sweep line */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "interval.h"

using namespace std;

class mycomp{
public:
  bool operator () (Interval i, Interval j){
    return (i.start < j.start || (i.start == j.start && i.end > j.end ));
  }
};

class Solution{
public:
  int removeCoveredIntervals(vector<Interval> intervals){
    sort(intervals.begin(),intervals.end(),mycomp());
    int count = 0, cur = 0;

    for(Interval i : intervals){
      if(cur < i.end){
        cur = i.end;
        count++;
      }
    }
    return count;
  }
};
