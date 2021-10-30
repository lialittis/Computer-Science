/* sweep line */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "interval.h"

using namespace std;

class Solution{
public:
  set<Interval> treeset;
  void addNum(int val){
    Interval i = Interval(val,val);
    if(treeset.count(i)){
      return;
    }
    auto low_it = treeset.lower_bound(i), high_it = treeset.upper_bound(i);
    if(high_it != treeset.end() && high_it->start == val){
      return;
    }
    if(low_it != treeset.end() && low_it->end + 1 == val &&
       high_it != treeset.end() && high_it->start - 1 == val){
      treeset.insert(Interval(low_it->start,high_it->end));
      treeset.erase(low_it);
      treeset.erase(high_it);
    }
    else if (low_it != treeset.end() && low_it->end + 1 >= val) {
      treeset.insert(Interval(low_it->start,max(low_it->end,val)));
        treeset.erase(low_it);
    }
    else if (high_it != treeset.end() && val == high_it->start){
      treeset.insert(Interval(val,high_it->end));
      treeset.erase(high_it);
    }
    else treeset.insert(i);

  }
  vector<Interval> getIntervals(vector<int> inputs){
    for(int i : inputs){
      treeset.insert(i);
    }

    vector<Interval> x(treeset.begin(),treeset.end());
    return x;
  }
};

int main() {

}
