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
  int minMeetingRooms(vector<Interval> intervals){
    vector<Interval> l;

    for(Interval i : intervals) {
      l.push_back(Interval(i.start,1));
      l.push_back(Interval(i.end,-1));
    }

    sort(l.begin(),l.end());

    int cnt = 0;
    int ans = 0;
    for(auto p : l){
      cnt += p.end;
      ans = max(ans,cnt);
    }

    return ans;
  }
};

//time O(nlogn)
//space O(n)
class SolutionPQ{
public:
  int minMeetingRooms(vector<Interval> intervals){
    // sort the meetings according to their star time;
    sort(intervals.begin(),intervals.end());

    // using lambad to compare elements
    // make a heap with top of earliest finished meeting currently
    auto comp = [](Interval i1, Interval i2) {return i1.end > i2.end; };
    priority_queue<Interval,vector<Interval>, decltype(comp)> heap(comp);

    // first room
    if(intervals.size() != 0) heap.push(intervals[0]);

    for(int i  = 1; i < intervals.size() ; i++) {
      Interval top = heap.top();
      if(top.end <= intervals[i].start) {heap.pop();}
      heap.push(intervals[i]);
    }

    return heap.size();
  }
};

// Another worser solution
// sort both by starts and ends

int main(){
  Solution sol;
  SolutionPQ solpq;

  vector<Interval> meetings;
  meetings.push_back(Interval(1,10));
  meetings.push_back(Interval(2,7));
  meetings.push_back(Interval(3,19));
  meetings.push_back(Interval(8,12));
  meetings.push_back(Interval(10,20));
  meetings.push_back(Interval(11,30));

  cout << "first method : "<<sol.minMeetingRooms(meetings)<<endl;
  cout << "second method : "<< solpq.minMeetingRooms(meetings)<<endl;

  return 0;
}
