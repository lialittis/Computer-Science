/* native O(n); divide and conquer O(lgn) */

#include <vector>
#include <math.h>

using namespace std;

class Solution{
public:
    int power_native(int x, int n){
        int power = 1;
        int i;
        for(i = 0; i<n; i++){
            power *= x;
        }
        return power;
    }

    double myPow(double x, int n){
        if(x == 0 || x == 1) return x;
        if(n<0) return (Pow(1/x,n)); // do this to avoid INT_MIN
        return Pow(x,n);
    }

    double Pow(double x, int n){
        if (n==0) return 1;
        double y = Pow(x,n/2);
        if(n%2 == 0) return y*y; // or use !(n & 1)
        else return y*y*x;
    }
};

int main(){

}