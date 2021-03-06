# Scanning

## number of airplanes in the sky

Given a table of time of taking off and landing for airplanes, using intervals, please
calculate the maximum number of airplanes in the sky at the same time.

Idea 1: brute scanning - check each moment

Idea 2: sweep line - only check the start point or the end point


### Example

Input : [(1,10),(2,3),(5,8),(4,7)]

Output : 3

### Implement

Set a counter;

If we meet the start of interval, counter++;

If we meet the end of intervals, counter--;

## meeting rooms

Given an array of meeting time intervals consisting of start and end times `[[s1,e1],[s2,e2],...]` (si < ei), determine if a person could attend all meetings.

### Example

Input : [[0,30],[5,10],[15,20]]

Output : false

## meeting rooms II

find the minimum number of conference rooms required.

Three methods :

- sweep line by one one sort
- sort + pq
- two sorts

## merge intervals

Given a collection of intervals, merge all overlapping intervals

### Example

Input : [[1,3],[2,6],[8,10],[15,18]]

Output : [[1,6],[8,10],[15,18]]

### Implement

- Sort intervals by its start
- if curr.start <= last.end:
  - merge intervals;
- else
  - insert a new interval

time : O(nlogn)

space : O(n)


## insert interval

Given a set of non-overlapping intervals, insert a new interval into the intervals 
(merge if necessary)

You may assume that the intervals were initially sorted according to their start times.

### Example

Input : intervals = [[1,3],[6,9]], newInterval = [2,5]

Output : [[1,5],[6,9]]


## remove interval

Given a sorted list of disjoint intervals.

We remove the intersections between any interval in intervals and the interval toBeRemoved.

Return a sorted list of intervals.

### Example

Input : intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]

Output : [[0,1],[6,7]]

### implement

## non-overlapping Intervals

Given a collection of intervals, find the minimum number of intervals you neet to remove to
make the rest of the intervals non-overlapping.


### Example

Input : [[1,2],[2,3],[3,4],[1,3]]

Output : 1

### implementation

- sort by end times
- iteratively compare the last end time and current start time

## remove covered intervals

Retrun the numer of rest intervals.

Similarly as the previous one; sort by start time inscreasing, end time decreasing.

## Data Stream as Disjoint Intervals

Given a data stream input of non-negative integers a1,a2,..., summarize the numbers seen so
far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1,3, 7,2,6,..., then the summary
will be:
```
[1,1]
[1,1], [3,3]
[1,1], [3,3]
[1,3], [7,7]
[1,3], [6,7]
...
```

