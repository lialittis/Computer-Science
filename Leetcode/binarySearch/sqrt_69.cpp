#include <iostream>
using namespace std;

class Solution{
public:
    int sqrt_x(int x){
        // iteratively
        if(x == 0) return 0;
        int l = 1, r = x, mid, sqrt;
        while (l<=r)
        {
            // mid = (l+r)/2; // could be out of stack
            mid = l + (r-l)/2;
            sqrt = x / mid;
            if(sqrt == mid){
                return mid;
            }
            else if(sqrt > mid){
                l = mid +1;
            }
            else{
                r = mid - 1;
            }
        }

        return r; // it is right because when l = r - 1, mid = l
/*
Your runtime beats 53.73 % of cpp submissions
Your memory usage beats 24.95 % of cpp submissions (6 MB)
*/
    }

    int sqrt_newton(int x){
        long y = x; // using long to avoid out of buffer
        while (y*y> x){
            y = (y+x/y) / 2;
        } 
        return y;
    }
/*
Your runtime beats 100 % of cpp submissions
Your memory usage beats 24.95 % of cpp submissions (5.9 MB)
*/
};

int main(){
    Solution sol;
    cout<<sol.sqrt_x(1);
}