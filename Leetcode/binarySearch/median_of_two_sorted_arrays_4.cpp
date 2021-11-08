// binary search


#include <vector>
#include <math.h>
#include <stdlib.h>
#include <climits>

using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int> numsX, vector<int>numsY){
        if(numsX.size() > numsY.size() ) return findMedianSortedArrays(numsY,numsX);
        int left = 0, right = numsX.size();
        while (left <= right)
        {
            int x = left + (right - left)/2;
            int y = (numsX.size() + numsY.size()+1)/2 - x;
            int xLeft = (x==0) ? INT_MIN : numsX[x-1];
            int xRight = (x == numsX.size()) ? INT_MAX: numsX[x];
            int yLeft = (y==0) ? INT_MIN : numsY[y - 1];
            int yRight = (y==numsY.size()) ? INT_MAX : numsY[y];
            if(xLeft <= yRight && yLeft <= xRight){
                if((numsX.size()+numsY.size()) %2 == 0){
                    return (double)(max(xLeft,yLeft) +min(xRight,yRight))/2;
                }
                else return (double)max(xLeft,yLeft);
            }
            else if(xRight > yLeft) right = x-1;
            else left = x +1;
        }
        return -1;
    }
};