#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        // initialization
        vector<int> values(ratings.size(),1);
        for(int i=1; i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]) values[i]=values[i-1]+1;
        }

        for(int i = ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) values[i] = max(values[i], values[i+1]+1);
        }

        int sum=0;
        for(auto c:values){
            sum+= c;
        }
        // int sum = accumulate(values.begin(),values.end(),0);
        return sum;
    }
};

int main(){

}