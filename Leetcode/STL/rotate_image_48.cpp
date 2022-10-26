/*array*/

#include <vector>
#include <iostream>

using namespace std;

class Rotate{
public:
    void rotate(vector<vector<int>>& matrix) {
        // (x,y) -> (y, 4-x)
        int n = matrix.size();
        for(int i = 0; i < n/2 ; i ++){
            for(int j = i; j < n - i - 1; j++) {
                //cout<<n<<j<<endl;
                int x = i, y = j;
                int tmp = matrix[x][y];
                for(int k = 0; k<3;k++) {
                    matrix[x][y] = matrix[n-y-1][x];
                    int z = x;
                    x = n-y-1;
                    y = z;
                }
                matrix[x][y] = tmp;
            }
        }
    }
// 21/21 cases passed (4 ms)
// Your runtime beats 54.53 % of cpp submissions
// Your memory usage beats 93.16 % of cpp submissions (7 MB)

    void rotate2(vector<vector<int>>& matrix) {
        int temp = 0, n = matrix.size()-1;
        for (int i = 0; i <= n / 2; ++i) {
            for (int j = i; j < n - i; ++j) {
                temp = matrix[j][n-i];
                matrix[j][n-i] = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = temp;
            }
        }
    }
};

int main(){

}