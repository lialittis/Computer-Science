/* sweep line */
#include <algorithm>
#include <vector>

using namespace std;

struct Interval{
  int start;
  int end;

  bool operator < (Interval i) {
    return start < i.start ;
  }
};

class Solution{
public:

  bool canAttendMeetings(vector<Interval> intervals){
    sort(intervals.begin(),intervals.end());

    for(int i = 0; i < (int)intervals.size()-1; i++){
      if(intervals[i].end > intervals[i+1].start) return false;
    }
    return true;
  }
};

int main(){
  
}
