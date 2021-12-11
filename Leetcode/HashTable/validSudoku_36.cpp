/* Medium HashTable */

/* Determine if a sudoku board is valid
 * basic rules of sudoku
 * only the filled cells need to be validated
 * not necessarily solvable
 */


/* Self-Test : 24 min in brute force ; */

// how to read the board : arrays in array

// return bool value

#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

/* First Method */
// brute force + hashtable to count the appearance time

/* Complexity:
 * Time O(3 * size of board (n^2)) 
 * Space O(3 * size of each row (9) ) or O(9)
 */

// Your runtime beats 39.83 % of cpp submissions
// Your memory usage beats 52.31 % of cpp submissions (19 MB)

bool isValid(vector<vector<char>> board){

    int r = board.size() , c = board[0].size() ; // 9 and 9 in our case
    unordered_set<char> hashtable_r;
    unordered_set<char> hashtable_c;
    unordered_set<char> hashtable_b;
    // read rows
    for(int i = 0; i< r; ++i) {
        
        for(int j = 0; j < c ; ++j) {
            char c = board[i][j];
            if( c >= '1' && c <= '9'){
                if(hashtable_r.find(c) != hashtable_r.end()) { // find c
                    return false;
                }
                else hashtable_r.insert(c);
            }
        }
        hashtable_r.clear();

    }

    cout << "finish rows check" <<endl;
    // read columns

    for(int i = 0; i< c; ++i) {
        for(int j = 0; j < r ; ++j) {
            char c = board[j][i];
            if( c >= '1' && c <= '9'){
                if(hashtable_c.find(c) != hashtable_c.end()) { // find c
                    return false;
                }
                else hashtable_c.insert(c);
            }
        }
        hashtable_c.clear();
    }

    cout << "finish columns check"<<endl;

    // read square
    for(int i = 0; i< r; ) {
        for(int j = 0; j < c ; ) {
            for(int k = 0; k < 3; ++k) {
                for(int l = 0; l < 3; ++l ){
                    char c = board[i+k][j+l];
                    if( c >= '1' && c <= '9'){
                        if(hashtable_b.find(c) != hashtable_b.end()) { // find c
                            return false;
                        }
                        else hashtable_b.insert(c);
                    }
                }
            }
            j += 3;
            hashtable_b.clear();
        }
        i += 3;
    }
    cout << "finish box check" <<endl;

    return true;
}

/* Second method */

// check for rows , columns and sub-boxes in one for loop

// Runtime: 24 ms, faster than 59.38% of C++ online submissions for Valid Sudoku.
// Memory Usage: 21.8 MB, less than 6.17% of C++ online submissions for Valid Sudoku.

bool isValid(vector<vector<char>>& board) {
    int r = board.size() , c = board[0].size() ; // 9 and 9 in our case
        vector<unordered_set<char>> hashtables_r(9,unordered_set<char>{});
        vector<unordered_set<char>> hashtables_c(9,unordered_set<char>{});
        vector<unordered_set<char>> hashtables_b(9,unordered_set<char>{});

    for(int i = 0; i<r; ++i) {
        for(int j = 0; j < c; ++j ){
            char c= board[i][j];
            if(c != '.') {
                int k = i/3 * 3 + j/3; // to inditity the number of hashtable for subboxes
                if( hashtables_b[k].find(c) != hashtables_b[k].end() ||
                    hashtables_r[i].find(c) != hashtables_r[i].end() ||
                    hashtables_c[j].find(c) != hashtables_c[j].end() ) {
                    return false;
                }
                hashtables_b[k].insert(c);
                hashtables_r[i].insert(c);
                hashtables_c[j].insert(c);
            }
        }
    }
    return true;
}

int main(){

}