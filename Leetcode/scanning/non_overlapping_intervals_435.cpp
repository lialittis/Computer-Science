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

